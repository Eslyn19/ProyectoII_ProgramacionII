#include "Carnivoro.h"

Carnivoro::Carnivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, _energia, _velocidad) {
}

Carnivoro::~Carnivoro() {
    UnloadTexture(textura);
}

void Carnivoro::Dibujar() {
    DrawTexture(textura, x, y, RED);
}

void Carnivoro::Actualizar() {
    // Mover en dirección actual
    x += velocidad;
    
    // Rebotar en los bordes
    if (x <= 0 || x >= pantallaAncho - textura.width) {
        velocidad = -velocidad;
    }
}