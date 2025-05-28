#pragma once
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"

class FabricaAbstracta {
public:
    virtual ~FabricaAbstracta() = default;
    virtual Herbivoro* CrearHerbivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 2.0f) = 0;
    virtual Carnivoro* CrearCarnivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 3.0f) = 0;
    virtual Omnivoro* CrearOmnivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 2.5f) = 0;
}; 