#include "Herbivoro.h"
#include "EstrategiaAlimento.h"
#include "RecursosContenedor.h"

Herbivoro::Herbivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad)
    : Criatura(ruta, _x, _y, ancho, alto, _velocidad) {
    movimiento = new EstrategiaMovimiento();
    // La estrategia de alimento se establecerá después de crear el contenedor de recursos
}

void Herbivoro::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

void Herbivoro::Actualizar() {
    if (movimiento) {
        movimiento->Mover(this);
    }
    if (alimento) {
        alimento->Mover(this);
    }
}
