#include "Entorno.h"

Entorno::Entorno(int _ticket) : ciclo(nullptr), clima(nullptr), temporada(nullptr)
{
	ticket = _ticket;
}

Entorno::~Entorno() 
{ 
	delete instance;
}

Entorno* Entorno::getInstance(int _ticket)
{
	if (!instance)
	{
		instance = new Entorno(_ticket);
		std::atexit(&destroyInstance);
	}
	return instance;
}

void Entorno::setTicket(int _ticket)
{
	ticket = _ticket;
}

int Entorno::getTicket() 
{
	return ticket;
}

//std::string Entorno::toString() const 
//{
//	// TODO:
//}

Entorno* Entorno::instance = nullptr;

void Entorno::destroyInstance()
{
	if (instance) 
	{ 
		delete instance;
	}
}