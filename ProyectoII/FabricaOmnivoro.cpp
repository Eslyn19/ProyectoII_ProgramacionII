#include "FabricaOmnivoro.h"
#include "Interfaz.h"

FabricaOmnivoro::FabricaOmnivoro() 
{
	omnivoro = this->crearOmnivoros();
}

FabricaOmnivoro::~FabricaOmnivoro()
{
	delete omnivoro;
}

Criatura* FabricaOmnivoro::crearOmnivoros()
{
	return Interfaz::CrearC_Omnivoro();
}

