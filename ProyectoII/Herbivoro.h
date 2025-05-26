#pragma once
#include "Criatura.h"
#include <raylib.h>

class Herbivoro : public Criatura
{
public:
	Herbivoro(int, int, int, std::string, Vector2, Texture2D);
	virtual ~Herbivoro();
};