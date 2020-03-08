#pragma once

#include <mosquittopp.h>

#include "Client.h"

// Уточнить про множественное наследование в этом случае
class MqttClient : mosqpp::mosquittopp , public Client
{
	const char* host;
	const char* id;
	const char* topic;
	int port;
	int keepalive;
	
public:

	MqttClient(const char* _id, const char* _topic, const char* _host, int _port);
	~MqttClient();
	virtual bool send_message(const char* _message);

};