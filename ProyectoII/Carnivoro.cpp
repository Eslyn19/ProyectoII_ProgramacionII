#include "Carnivoro.h"

Carnivoro::Carnivoro(const char* ruta, float x, float y, int ancho)
    : Criatura(ruta, x, y, ancho) {
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Dibujar() {
    DrawTexture(textura, (int)x, (int)y, WHITE);
}

void Carnivoro::Actualizar() {
    // Por ahora está vacío, se implementará la lógica de movimiento después
} 