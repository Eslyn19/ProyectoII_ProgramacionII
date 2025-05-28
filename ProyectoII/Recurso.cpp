#include "Recurso.h"

Recurso::Recurso(const char* ruta, float _x, float _y, int _vida)
    : x(_x), y(_y), vida(_vida) {
    textura = LoadTexture(ruta);
    pantallaAncho = GetScreenWidth();
}

Recurso::~Recurso() {
    UnloadTexture(textura);
}

float Recurso::GetX() const {
    return x;
}

float Recurso::GetY() const {
    return y;
}

int Recurso::GetVida() const {
    return vida;
}

Texture2D Recurso::GetTextura() const {
    return textura;
}

void Recurso::SetVida(int _vida) {
    vida = _vida;
}

void Recurso::SetPosicion(float _x, float _y) {
    x = _x;
    y = _y;
}

void Recurso::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}