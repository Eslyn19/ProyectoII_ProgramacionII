#pragma once
#include "FabricaAbstracta.h"

class FabricaConcreta : public FabricaAbstracta {
public:
    FabricaConcreta();
    ~FabricaConcreta() override;

    Herbivoro* CrearHerbivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 2.0f) override;
    Carnivoro* CrearCarnivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 3.0f) override;
    Omnivoro* CrearOmnivoro(const char* ruta, float x, float y, int ancho, int energia = 100, float velocidad = 2.5f) override;
}; 