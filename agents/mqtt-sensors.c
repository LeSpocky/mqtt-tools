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
    char mystr[64];
    int ec, i;
    const sensors_chip_name *cn;

    ec = sensors_init( NULL );
    if ( ec )
    {
        (void) fprintf( stderr, "Error (%i) initializing libsensors!\n", ec );
        goto leave;
    }
    (void) printf( "libsensors version %s found ...\n", libsensors_version );

    i = 0;
    while( (cn = sensors_get_detected_chips( NULL, &i )) )
    {
        if ( sensors_snprintf_chip_name( mystr, sizeof(mystr), cn ) < 0 )
        {
            break;
        }

        (void) printf( "chip %i: %s\n", i, mystr );
    }

leave:
    sensors_cleanup();
    return ((ec == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}
