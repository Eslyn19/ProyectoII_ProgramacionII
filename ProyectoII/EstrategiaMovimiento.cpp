#include "EstrategiaMovimiento.h"
#include "ContenedorCriaturas.h"
#include "raylib.h"
#include "math.h"
#include "Criatura.h"

EstrategiaMovimiento::EstrategiaMovimiento() : velocidadX(0), velocidadY(0), contenedorCriaturas(nullptr) {}

void EstrategiaMovimiento::SetContenedorCriaturas(ContenedorCriaturas* _contenedor) {
    contenedorCriaturas = _contenedor;
}

void EstrategiaMovimiento::Mover(Criatura* criatura) {
    int ancho_pantalla = 1064;
    int alto_pantalla = 808;
    int ancho_criatura = 100;

    if (velocidadX == 0 && velocidadY == 0) {
        velocidadX = criatura->GetVelocidad();
        velocidadY = criatura->GetVelocidad();
    }

    float x = criatura->GetX() + velocidadX;
    float y = criatura->GetY() + velocidadY;

    // Rebote en bordes
    if (x <= 0) {
        x = 0;
        velocidadX = -velocidadX;
    }
    else if (x + ancho_criatura >= ancho_pantalla) {
        x = ancho_pantalla - ancho_criatura;
        velocidadX = -velocidadX;
    }

    if (y <= 100) {
        y = 100;
        velocidadY = -velocidadY;
    }
    else if (y + ancho_criatura >= alto_pantalla) {
        y = alto_pantalla - ancho_criatura;
        velocidadY = -velocidadY;
    }

    criatura->SetPos(x, y);
}

bool EstrategiaMovimiento::Alimentar(Criatura* criatura, Recurso* recurso) {
    return false;
}
