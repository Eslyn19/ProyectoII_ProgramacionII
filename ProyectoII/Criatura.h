#pragma once
#include <string>
#include <raylib.h>

class Criatura
{
public:
	Criatura();
	virtual int getPosX();
	virtual int getPosY();
	virtual int getEnergia();
	virtual std::string getNombre();
	virtual ~Criatura();
protected:
	int posX; // Posicion x & y de moverse a traves del mapa
	int posY;
	int energia;
	std::string nombre;
	Vector2 posicion; // Posicion de imagen
	Texture2D textura;
};