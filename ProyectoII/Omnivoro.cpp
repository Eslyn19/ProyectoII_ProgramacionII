#include "Omnivoro.h"

Omnivoro::Omnivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, _energia, _velocidad) {
}

Omnivoro::~Omnivoro() {
    UnloadTexture(textura);
}

void Omnivoro::Dibujar() {
    DrawTexture(textura, x, y, GREEN);
}

void Omnivoro::Actualizar() {
    // Mover en dirección actual
    x += velocidad;
    
    // Rebotar en los bordes
    if (x <= 0 || x >= pantallaAncho - textura.width) {
        velocidad = -velocidad;
    }
}