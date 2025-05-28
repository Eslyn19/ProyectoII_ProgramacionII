#include "Criatura.h"

Criatura::Criatura(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad) {
          
    x = _x;
    y = _y;
    posicion = { x, y };
    pantallaAncho = ancho;
    energia = _energia;
    velocidad = _velocidad;
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