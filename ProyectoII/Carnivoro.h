#pragma once
#include "Criatura.h"
#include <raylib.h>

class Carnivoro : public Criatura
{
public:
	Carnivoro(int, int, int, std::string, Vector2, Texture2D);
	virtual ~Carnivoro();
};

