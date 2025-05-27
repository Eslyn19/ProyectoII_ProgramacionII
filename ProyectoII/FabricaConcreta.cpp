#include "FabricaConcreta.h"

FabricaConcreta::FabricaConcreta() {}

FabricaConcreta::~FabricaConcreta() {}

Criatura* FabricaConcreta::CrearHerbivoro(const char* ruta, float x, float y, int ancho) {
    return new Herbivoro(ruta, x, y, ancho);
}

Criatura* FabricaConcreta::CrearCarnivoro(const char* ruta, float x, float y, int ancho) {
    return new Carnivoro(ruta, x, y, ancho);
}

Criatura* FabricaConcreta::CrearOmnivoro(const char* ruta, float x, float y, int ancho) {
    return new Omnivoro(ruta, x, y, ancho);
} 