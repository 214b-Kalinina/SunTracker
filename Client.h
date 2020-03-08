#pragma once
class Client
{
public:
	virtual bool send_message(const char* _message) = 0;
};

