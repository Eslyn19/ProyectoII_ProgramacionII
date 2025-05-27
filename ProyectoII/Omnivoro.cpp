#include "Omnivoro.h"

Omnivoro::Omnivoro(const char* ruta, float x, float y, int ancho)
    : Criatura(ruta, x, y, ancho) {
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Dibujar() {
    DrawTexture(textura, (int)x, (int)y, WHITE);
}

void Omnivoro::Actualizar() {
    // Por ahora está vacío, se implementará la lógica de movimiento después
} 