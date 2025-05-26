#pragma once
#include "Criatura.h"

class FabricaCriatura
{
public:
	FabricaCriatura();
	virtual ~FabricaCriatura();
	//virtual Criatura* crearHerbivoro() = 0;
	//virtual Criatura* crearCarnivoro() = 0;
	virtual Criatura* crearOmnivoros() = 0;
protected:
	Criatura* herbivoro;
	Criatura* carnivoro;
	Criatura* omnivoro;
};