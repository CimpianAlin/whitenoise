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
#include "whitenoise_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

whitenoise_base::whitenoise_base(const char *uuid, const char *label) :
    Resource_impl(uuid, label),
    ThreadedComponent()
{
    loadProperties();

    dataFloatOut = new bulkio::OutFloatPort("dataFloatOut");
    addPort("dataFloatOut", dataFloatOut);
}

whitenoise_base::~whitenoise_base()
{
    delete dataFloatOut;
    dataFloatOut = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void whitenoise_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Resource_impl::start();
    ThreadedComponent::startThread();
}

void whitenoise_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Resource_impl::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void whitenoise_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Resource_impl::releaseObject();
}

void whitenoise_base::loadProperties()
{
    addProperty(mean,
                0.0,
                "mean",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(stddev,
                1.0,
                "stddev",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(xfer_len,
                16384,
                "xfer_len",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(packetTime,
                0.0,
                "packetTime",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(throttle,
                -1.0,
                "throttle",
                "throttle",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(sri,
                sri_struct(),
                "sri",
                "",
                "readwrite",
                "",
                "external",
                "configure");

}


