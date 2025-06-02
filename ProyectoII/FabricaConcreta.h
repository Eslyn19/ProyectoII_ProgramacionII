#pragma once
#include "FabricaAbstracta.h"

class FabricaConcreta : public FabricaAbstracta {
public:
    FabricaConcreta();
    ~FabricaConcreta() override;

    Herbivoro* CrearHerbivoro(const char* ruta, float x, float y, int ancho, int alto, float velocidad) override;
    Carnivoro* CrearCarnivoro(const char* ruta, float x, float y, int ancho, int alto, float velocidad) override;
    Omnivoro* CrearOmnivoro(const char* ruta, float x, float y, int ancho, int alto, float velocidad) override;
}; 