/*******************************************************************//**
 * \file		mqtt-sensors.c
 *
 * \brief		Agent for publishing values from lm-sensors.
 *
 * \author		Alexander Dahl <alex@netz39.de>
 *
 * SPDX-License-Identifier: MIT
 * License-Filename: LICENSES/MIT.txt
 *
 * \copyright	2017 Stefan Haun, Netz39 e.V., and mqtta contributors
 **********************************************************************/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <sensors/sensors.h>

int main( void )
{
    int ec;

    ec = sensors_init( NULL );
    if ( ec )
    {
        (void) fprintf( stderr, "Error (%i) initializing libsensors!\n", ec );
    }

    sensors_cleanup();

    return ((ec == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}
