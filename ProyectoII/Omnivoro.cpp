#include "Omnivoro.h"

Omnivoro::Omnivoro(int _posX, int _posY, int _energia, std::string _nombre, Vector2 _pos, Texture2D _ruta)
{
	this->posX = _posX;
	this->posY = _posY;
	this->energia = _energia;
	this->nombre = _nombre;
	this->posicion = _pos;
	this->textura = _ruta;
}

Omnivoro::~Omnivoro() 
{
	UnloadTexture(textura);
}

int Omnivoro::getPosX()
{
	return posX;
}

int Omnivoro::getPosY()
{
	return posY;
}

int Omnivoro::getEnergia()
{
	return energia;
}

std::string Omnivoro::getNombre()
{ 
	return nombre;
}