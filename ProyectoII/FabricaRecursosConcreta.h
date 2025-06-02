#pragma once
#include "FabricaRecursosAbstracta.h"
#include "RecursoAgua.h"
#include "RecursoPlanta.h"
#include "RecursoCarne.h"

class FabricaRecursoConcreta : public FabricaRecursoAbstracta {
public:
    FabricaRecursoConcreta();
    ~FabricaRecursoConcreta() override;

    Agua* CrearAgua(const char* ruta, float x, float y) override;
    Planta* CrearPlanta(const char* ruta, float x, float y) override;
    Carne* CrearCarne(const char* ruta, float x, float y) override;
};

