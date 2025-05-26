#pragma once
#include "Criatura.h"
#include <raylib.h>

class Omnivoro : public Criatura
{
public:
	Omnivoro(int, int, int, std::string, Vector2, Texture2D);
	~Omnivoro();
	int getPosX();
	int getPosY(); 
	int getEnergia();
	std::string getNombre();
};
