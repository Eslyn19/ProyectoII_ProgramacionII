#pragma once
#include "Criatura.h"

class FabricaAbstracta {
public:
    FabricaAbstracta() {}
    virtual ~FabricaAbstracta() {}
    virtual Criatura* CrearHerbivoro(const char* ruta, float x, float y, int ancho) = 0;
    virtual Criatura* CrearCarnivoro(const char* ruta, float x, float y, int ancho) = 0;
    virtual Criatura* CrearOmnivoro(const char* ruta, float x, float y, int ancho) = 0;
}; 