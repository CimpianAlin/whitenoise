/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This file is part of REDHAWK Basic Components whitenoise.
 *
 * REDHAWK Basic Components whitenoise is free software: you can redistribute it and/or modify it under the terms of
 * the GNU Lesser General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * REDHAWK Basic Components whitenoise is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this
 * program.  If not, see http://www.gnu.org/licenses/.
 */
#ifndef WHITENOISE_IMPL_BASE_H
#define WHITENOISE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Resource_impl.h>
#include <ossie/ThreadedComponent.h>

#include <bulkio/bulkio.h>
#include "struct_props.h"

class whitenoise_base : public Resource_impl, protected ThreadedComponent
{
    public:
        whitenoise_base(const char *uuid, const char *label);
        ~whitenoise_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:
        // Member variables exposed as properties
        float mean;
        float stddev;
        CORBA::Long xfer_len;
        double packetTime;
        float throttle;
        sri_struct sri;

        // Ports
        bulkio::OutFloatPort *dataFloatOut;

    private:
};
#endif // WHITENOISE_IMPL_BASE_H
