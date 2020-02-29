#include "MqttClient.h"

#include <iostream>
#include <mosquittopp.h>


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
}



MqttClient::~MqttClient()
{
	loop_stop();
	mosqpp::lib_cleanup();
}



bool MqttClient::send_message(const char* _message)
{
	int ret = publish(NULL, topic, strlen(_message), _message, 1, false);
	return (ret == MOSQ_ERR_SUCCESS);
}



bool MqttClient::subscribe_topic(const char* _topic)
{
	int ret = subscribe(NULL, _topic, 1);
	return (ret == MOSQ_ERR_SUCCESS);
}




void MqttClient::on_disconnect(int rc) {
	std::cout << ">> myMosq - disconnection(" << rc << ")" << std::endl;
}


void MqttClient::on_connect(int rc)
{
	if (rc == 0) {
		std::cout << ">> myMosq - connected with server" << std::endl;
	}
	else {
		std::cout << ">> myMosq - Impossible to connect with server(" << rc << ")" << std::endl;
	}
}


void MqttClient::on_publish(int mid)
{
	std::cout << ">> myMosq - Message (" << mid << ") succeed to be published " << std::endl;
}