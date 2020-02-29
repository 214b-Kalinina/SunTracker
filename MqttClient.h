#pragma once

#include <mosquittopp.h>

class MqttClient : mosqpp::mosquittopp
{
	const char* host;
	const char* id;
	const char* topic;
	int port;
	int keepalive;

	void on_connect(int rc);
	void on_disconnect(int rc);
	void on_publish(int mid);

public:

	MqttClient(const char* _id, const char* _topic, const char* _host, int _port);
	~MqttClient();
	bool send_message(const char* _message);
	bool subscribe_topic(const char* _topic);


};