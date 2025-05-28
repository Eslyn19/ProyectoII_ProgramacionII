#include "Herbivoro.h"

Herbivoro::Herbivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, _energia, _velocidad) {
}

Herbivoro::~Herbivoro() {
    UnloadTexture(textura);
}

void Herbivoro::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

void Herbivoro::Actualizar() {
    // Mover en dirección actual
    x += velocidad;
    
    // Rebotar en los bordes
    if (x <= 0 || x >= pantallaAncho - textura.width) {
        velocidad = -velocidad;
    }
}