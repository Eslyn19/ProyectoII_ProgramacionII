#include "FabricaCriatura.h"

FabricaCriatura::FabricaCriatura() 
{
	carnivoro = NULL;
	herbivoro = NULL;
	omnivoro = NULL;
}

FabricaCriatura::~FabricaCriatura()
{
	if (carnivoro != NULL) delete carnivoro;
	if (herbivoro != NULL) delete herbivoro;
	if (omnivoro != NULL) delete omnivoro;
}