#include "EstrategiaMovimiento.h"
#include "ContenedorCriaturas.h"
#include "raylib.h"
#include <math.h>
#include "Criatura.h"
#include "Carnivoro.h"
#include "Herbivoro.h"
#include "Omnivoro.h"
#include "RecursoCarne.h"

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

    // Detectar colisiones con otras criaturas solo para carnívoros
    if (contenedorCriaturas) {
        int numCriaturas = contenedorCriaturas->GetCantidadCriaturas();
        for (int i = 0; i < numCriaturas; i++) {
            Criatura* otraCriatura = contenedorCriaturas->GetCriatura(i);
            if (otraCriatura && otraCriatura != criatura) {
                float dx = x - otraCriatura->GetX();
                float dy = y - otraCriatura->GetY();
                float distancia = sqrt(dx * dx + dy * dy);
                
                if (distancia < 50.0f) {
                    Carnivoro* carnivoro = dynamic_cast<Carnivoro*>(criatura);
                    if (carnivoro) {
                        if (dynamic_cast<Herbivoro*>(otraCriatura) || dynamic_cast<Omnivoro*>(otraCriatura)) {
                            contenedorCriaturas->EliminarCriatura(i);
                            criatura->SetUltimoTiempoComida(GetTime());
                            return; 
                        }
                    }
                }
            }
        }
    }

    criatura->SetPos(x, y);
}

bool EstrategiaMovimiento::Alimentar(Criatura* criatura, Recurso* recurso) {
    return false;
}
