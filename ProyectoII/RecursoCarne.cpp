#include "RecursoCarne.h"

Carne::Carne(const char* ruta, float _x, float _y, int _vida)
    : Recurso(ruta, _x, _y, _vida) {
}

Carne::~Carne() {}

void Carne::Dibujar() {
    DrawTexture(textura, x, y, RED);
}
