#pragma once
#include "FabricaRecursosAbstracta.h"

class FabricaRecursoConcreta : public FabricaRecursoAbstracta {
public:
    FabricaRecursoConcreta();
    ~FabricaRecursoConcreta() override;

    Agua* CrearAgua(const char* ruta, float x, float y, int vida) override;
    Planta* CrearPlanta(const char* ruta, float x, float y, int vida) override;
    Carne* CrearCarne(const char* ruta, float x, float y, int vida) override;
};

