#include "Carnivoro.h"

Carnivoro::Carnivoro(int _posX, int _posY, int _energia, std::string _nombre, Vector2 _pos, Texture2D _ruta)
{
	this->posX = _posX;
	this->posY = _posY;
	this->energia = _energia;
	this->nombre = _nombre;
	this->posicion = _pos;
	this->textura = _ruta;
}

Carnivoro::~Carnivoro() {}