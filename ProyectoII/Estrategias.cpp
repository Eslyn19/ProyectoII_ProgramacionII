#include "Estrategias.h"

void EstrategiaMovimiento::Mover(Criatura* criatura) {
    if (velocidadX == 0 && velocidadY == 0) {
        velocidadX = criatura->GetVelocidad();
        velocidadY = criatura->GetVelocidad();
    }

    float x = criatura->GetX();
    float y = criatura->GetY();

    // Mover la criatura
    x += velocidadX;
    y += velocidadY;

    // Rebote en bordes horizontales
    if (x <= 0) {
        x = 0;
        velocidadX = -velocidadX;
    }
    else if (x + ANCHO_CRIATURA >= ANCHO_PANTALLA) {
        x = ANCHO_PANTALLA - ANCHO_CRIATURA;
        velocidadX = -velocidadX;
    }

    // Rebote en bordes verticales
    if (y <= 100) {
        y = 100;
        velocidadY = -velocidadY;
    }
    else if (y + ANCHO_CRIATURA >= ALTO_PANTALLA) {
        y = ALTO_PANTALLA - ANCHO_CRIATURA;
        velocidadY = -velocidadY;
    }

    criatura->SetPos(x, y);
} 