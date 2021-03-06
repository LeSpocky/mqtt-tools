/*******************************************************************//**
 * \file		mosqhelper.h
 *
 * \brief		Helper Lib for libmosquitto
 *
 * \author		Stefan Haun <tux@netz39.de>
 *
 * SPDX-License-Identifier: MIT
 * License-Filename: LICENSES/MIT.txt
 *
 * \copyright	2017 Stefan Haun, Netz39 e.V., and mqtta contributors
 **********************************************************************/

#pragma once

#include <stdbool.h>

#include <mosquitto.h>

int mqtt_init(const char* clientname,
	      struct mosquitto **mosq,
	      void *mqtt_obj);

int mqtt_connect(struct mosquitto *mosq,
                 const char* host,
                 int port,
                 int retries);

int mqtt_loop(struct mosquitto *mosq);

int mqtt_close(struct mosquitto *mosq);

int mqtt_publish(struct mosquitto *mosq,
		 int* mid,
		 const char* topic,
		 int payloadlen,
		 const char* payload,
		 int qos,
		 bool retain);
