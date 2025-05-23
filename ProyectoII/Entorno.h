#pragma once
#include <string.h>
#include <iostream>

class Ciclo;
class Clima;
class Temporada;

class Entorno
{
public:
	virtual ~Entorno();
	static Entorno* getInstance(int);
	void setTicket(int);
	int getTicket();
	std::string toString() const;

private:
	Entorno(int);
	Entorno();
	int ticket;
	static Entorno* instance;
	static void destroyInstance();
	Ciclo* ciclo;
	Clima* clima;
	Temporada* temporada;
};