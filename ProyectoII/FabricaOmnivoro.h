#pragma once
#include "FabricaCriatura.h"

class FabricaOmnivoro : public FabricaCriatura
{
public:
	FabricaOmnivoro();
	~FabricaOmnivoro();
	Criatura* crearOmnivoros();
};
