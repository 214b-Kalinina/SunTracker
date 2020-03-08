#pragma once

#include "Client.h"

class TerminalClient : public Client
{
public:
	TerminalClient();
	virtual bool send_message(const char* _message);
};

