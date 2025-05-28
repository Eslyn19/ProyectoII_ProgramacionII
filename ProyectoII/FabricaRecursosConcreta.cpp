#include "FabricaRecursosConcreta.h"

FabricaRecursoConcreta::FabricaRecursoConcreta() {}

FabricaRecursoConcreta::~FabricaRecursoConcreta() {}

Agua* FabricaRecursoConcreta::CrearAgua(const char* ruta, float x, float y, int vida) {
    return new Agua(ruta, x, y, vida);
}

Planta* FabricaRecursoConcreta::CrearPlanta(const char* ruta, float x, float y, int vida) {
    return new Planta(ruta, x, y, vida);
}

Carne* FabricaRecursoConcreta::CrearCarne(const char* ruta, float x, float y, int vida) {
    return new Carne(ruta, x, y, vida);
}