#include "FabricaRecursosConcreta.h"

FabricaRecursoConcreta::FabricaRecursoConcreta() {}

FabricaRecursoConcreta::~FabricaRecursoConcreta() {}

Agua* FabricaRecursoConcreta::CrearAgua(const char* ruta, float x, float y) {
    return new Agua(ruta, x, y);
}

Planta* FabricaRecursoConcreta::CrearPlanta(const char* ruta, float x, float y) {
    return new Planta(ruta, x, y);
}

Carne* FabricaRecursoConcreta::CrearCarne(const char* ruta, float x, float y) {
    return new Carne(ruta, x, y);
}