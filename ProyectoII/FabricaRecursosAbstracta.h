#pragma once
#include "RecursoAgua.h"
#include "RecursoPlanta.h"
#include "RecursoCarne.h"

class FabricaRecursoAbstracta {
public:
    virtual ~FabricaRecursoAbstracta() = default;
    virtual Agua* CrearAgua(const char* ruta, float x, float y, int vida) = 0;
    virtual Planta* CrearPlanta(const char* ruta, float x, float y, int vida ) = 0;
    virtual Carne* CrearCarne(const char* ruta, float x, float y, int vida) = 0;
};
