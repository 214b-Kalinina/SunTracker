#include "MqttClient.h"

#include <iostream>


MqttClient::MqttClient(const char* _id, const char* _topic, const char* _host, int _port)
{
	mosqpp::lib_init();

	this->keepalive = 60;
	this->id = _id;
	this->port = _port;
	this->host = _host;
	this->topic = _topic;

	connect_async(host, port, keepalive);

	loop_start();

	std::cout << "MQTT CLIENT STARTED" << std::endl;
}



MqttClient::~MqttClient()
{
	loop_stop();
	mosqpp::lib_cleanup();
}



bool MqttClient::send_message(const char* _message) 
{
	int ret = publish(NULL, topic, strlen(_message), _message, 1, false);
	std::cout << "Msg send!" << std::endl;

	return (ret == MOSQ_ERR_SUCCESS);
}
