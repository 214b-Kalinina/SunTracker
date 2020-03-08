#include <iostream>

#include "TerminalClient.h"

TerminalClient::TerminalClient()
{
	std::cout << "TERMINAL CLIENT STARTED" << std::endl;
}


bool TerminalClient::send_message(const char* _message) {
	std::cout << _message << std::endl;

	return true;
}