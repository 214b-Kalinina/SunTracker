#include <iostream>
#include <string>

#include "MqttClient.h"
#include "Sun.h"
#include "Cloud.h"
#include "SunTracker.h"



int main(int argc, char* argv[])
{
	MqttClient mqtt("test", "test/topic", "localhost", 1884);

	int test;

	// Used to complete the connection to the server
	std::cout << "Enter \"1\" to start: ";
	std::cin >> test;



	if (test == 1)
	{
		Sun sun(2000);
		Cloud cloud(300, 300, -2, 1200);

		SunTracker sunTracker(sun, cloud);


		for (int i = 0; i < 720; i++)
		{
			if ( sunTracker.isDangerousAngle() )
			{
				std::string message = "WARNING! TIME: " + std::to_string(i / 12 + 7) + ":" + std::to_string(i % 60);

				mqtt.send_message(message.c_str());
				std::cout << "Msg send!" << std::endl;
			}

			sunTracker.toModelMinute();
		}


		// Used to complete sending messages
		std::cout << "Enter something to end: ";
		std::cin >> test;
		std::cin >> test;

	}
	
	return 0;
}

// Broker start:
// mosquitto -p 1884 -v

// Client Subscribe: 
// mosquitto_sub -h localhost -p 1884 -t "test/topic"
