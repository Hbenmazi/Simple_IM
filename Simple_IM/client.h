#pragma once
#include <qtcpsocket.h>

class client
{
public:
	client();
	~client();

private:
	QTcpSocket* socket;
	
};

