#pragma once
#include "FabricaAbstracta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"

class FabricaConcreta : public FabricaAbstracta {
public:
    FabricaConcreta();
    ~FabricaConcreta() override;

    Criatura* CrearHerbivoro(const char* ruta, float x, float y, int ancho) override;
    Criatura* CrearCarnivoro(const char* ruta, float x, float y, int ancho) override;
    Criatura* CrearOmnivoro(const char* ruta, float x, float y, int ancho) override;
}; 