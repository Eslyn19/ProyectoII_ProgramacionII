#include "Criatura.h"

Criatura::Criatura() : posX(0), posY(0), energia(0), nombre(""), posicion({ 0, 0 }), textura{} {}

Criatura::~Criatura() {}

int Criatura::getPosX() { return posX; }

int Criatura::getPosY() { return posY; }

int Criatura::getEnergia() { return energia; }

std::string Criatura::getNombre() { return nombre; }