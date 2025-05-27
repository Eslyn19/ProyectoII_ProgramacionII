#include "Herbivoro.h"

Herbivoro::Herbivoro(const char* ruta, float x, float y, int ancho)
    : Criatura(ruta, x, y, ancho) {
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Dibujar() {
    DrawTexture(textura, (int)x, (int)y, WHITE);
}

void Herbivoro::Actualizar() {
    // Por ahora está vacío, se implementará la lógica de movimiento después
} 