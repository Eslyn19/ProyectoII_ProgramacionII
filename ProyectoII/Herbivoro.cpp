#include "Herbivoro.h"

Herbivoro::Herbivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, _energia, _velocidad) {
    movimiento = new EstrategiaMovimiento();
}

Herbivoro::~Herbivoro() {
    UnloadTexture(textura);
}

void Herbivoro::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

void Herbivoro::Actualizar() {
    if (movimiento) {
        movimiento->Mover(this);
    }
}