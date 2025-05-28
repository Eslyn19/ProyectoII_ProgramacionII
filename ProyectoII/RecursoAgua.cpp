#include "RecursoAgua.h"

Agua::Agua(const char* ruta, float _x, float _y, int _vida)
    : Recurso(ruta, _x, _y, _vida) {
}

Agua::~Agua() {}

void Agua::Dibujar() {
    DrawTexture(textura, x, y, BLUE);
}

