#include "Criatura.h"

Criatura::Criatura(const char* ruta, float _x, float _y, int ancho) {
    x = _x;
    y = _y;
    posicion = { x, y };
    pantallaAncho = ancho;
    energia = 100;
    textura = LoadTexture(ruta);
}

void Criatura::SetPos(float _x, float _y) {
    x = _x;
    y = _y;
    posicion = { x, y };
}

Criatura::~Criatura() {
    UnloadTexture(textura);
} 