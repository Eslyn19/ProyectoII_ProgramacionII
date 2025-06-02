#include "Carnivoro.h"
#include "Criatura.h"
#include "EstrategiaAlimento.h"
#include "RecursosContenedor.h"

Carnivoro::Carnivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, alto, _velocidad) {
    movimiento = new EstrategiaMovimiento();
}

void Carnivoro::Dibujar() {
    DrawTexture(textura, x, y, RED);
}

void Carnivoro::Actualizar() {
    if (movimiento) {
        movimiento->Mover(this);
    }
    if (alimento) {
        alimento->Mover(this);
    }
}
