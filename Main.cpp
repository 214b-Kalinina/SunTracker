#include <iostream>
#include <string>

#include "TerminalClient.h"
#include "MqttClient.h"
#include "SunTracker.h"

//TerminalClient client;
MqttClient client("test", "test/topic", "localhost", 1884);


int main(int argc, char* argv[])
{

	SunTracker sunTracker(300, 300, -2, 1200);


	for (int i = 0; i < 720; i++)
	{
		if ( sunTracker.isDangerous() )
		{
			std::string message = "WARNING! TIME: " + std::to_string(i / 12 + 7) + ":" + std::to_string(i % 60);
			client.send_message(message.c_str());
		}

		sunTracker.toModelMinute();
	}


	// Used to complete sending messages
	int test;

	std::cout << "Enter something to end: ";
	std::cin >> test;

	
	return 0;
}

// Broker start:
// mosquitto -p 1884 -v

// Client Subscribe: 
// mosquitto_sub -h localhost -p 1884 -t "test/topic"
