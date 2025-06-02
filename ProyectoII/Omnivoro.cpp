#include "Omnivoro.h"
#include "EstrategiaAlimento.h"
#include "RecursosContenedor.h"

Omnivoro::Omnivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, alto, _velocidad) {
    movimiento = new EstrategiaMovimiento();
}

void Omnivoro::Dibujar() {
    DrawTexture(textura, x, y, GREEN);
}

void Omnivoro::Actualizar() {
    if (movimiento) {
        movimiento->Mover(this);
    }
    if (alimento) {
        alimento->Mover(this);
    }
}
