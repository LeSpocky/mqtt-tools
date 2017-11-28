#
# Copyright (c) 2017 Stefan Haun, Netz39 e.V., and mqtta contributors
#
# SPDX-License-Identifier: MIT
# License-Filename: LICENSES/MIT.txt
#

include_directories(
	"${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/include"
)

# mqtt-clock
add_executable(mqtt-clock
    mqtt-clock.c
)
target_link_libraries(mqtt-clock
    mosqhelper
    mqtta
)
install(TARGETS mqtt-clock
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

# mqtt-sensors
option(MQTTA_AGENT_SENSORS
    "Agent publishing values from lm-sensors"
    OFF
)

if(MQTTA_AGENT_SENSORS)
    find_library(SENSORS_LIBRARY NAMES sensors)

    add_executable(mqtt-sensors
        mqtt-sensors.c
    )
    target_link_libraries(mqtt-sensors
        "${SENSORS_LIBRARY}"
    )
    install(TARGETS mqtt-sensors
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )
endif(MQTTA_AGENT_SENSORS)
