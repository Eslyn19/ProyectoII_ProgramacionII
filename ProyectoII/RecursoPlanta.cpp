#include "RecursoPlanta.h"

Planta::Planta(const char* ruta, float _x, float _y, int _vida)
    : Recurso(ruta, _x, _y, _vida) {
}

Planta::~Planta() {}

void Planta::Dibujar() {
    DrawTexture(textura, x, y, GREEN);
}