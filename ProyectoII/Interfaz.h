#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"
#include "Criatura.h"

class Interfaz
{
public:
	static Criatura* CrearC_Omnivoro()
	{
		Vector2 pos = { 0.0f, 0.0f };
		Texture2D tex = LoadTexture("omnivoro.png"); 
		return new Omnivoro(20, 40, 30, "Sinovenator", pos, tex);
	}
};