#include "FabricaConcreta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"

FabricaConcreta::FabricaConcreta() {}

FabricaConcreta::~FabricaConcreta() {}

Herbivoro* FabricaConcreta::CrearHerbivoro(const char* ruta, float x, float y, int ancho, int energia, float velocidad) {
    return new Herbivoro(ruta, x, y, ancho, energia, velocidad);
}

Carnivoro* FabricaConcreta::CrearCarnivoro(const char* ruta, float x, float y, int ancho, int energia, float velocidad) {
    return new Carnivoro(ruta, x, y, ancho, energia, velocidad);
}

Omnivoro* FabricaConcreta::CrearOmnivoro(const char* ruta, float x, float y, int ancho, int energia, float velocidad) {
    return new Omnivoro(ruta, x, y, ancho, energia, velocidad);
} 

