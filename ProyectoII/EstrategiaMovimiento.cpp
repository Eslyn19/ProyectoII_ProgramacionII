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
                    Herbivoro* herbivoro = dynamic_cast<Herbivoro*>(criatura);
                    Omnivoro* omnivoro = dynamic_cast<Omnivoro*>(criatura);

                    if (carnivoro) {
                        if (dynamic_cast<Herbivoro*>(otraCriatura) || dynamic_cast<Omnivoro*>(otraCriatura)) {
                            contenedorCriaturas->EliminarCriatura(i);
                            criatura->SetUltimoTiempoComida(GetTime());
                            return; 
                        }
                    }
                    // Add bouncing behavior for herbivores and omnivores
                    else if (herbivoro || omnivoro) {
                        Herbivoro* otroHerbivoro = dynamic_cast<Herbivoro*>(otraCriatura);
                        Omnivoro* otroOmnivoro = dynamic_cast<Omnivoro*>(otraCriatura);
                        
                        if (otroHerbivoro || otroOmnivoro) {
                            // Calculate bounce direction
                            float dx = x - otraCriatura->GetX();
                            float dy = y - otraCriatura->GetY();
                            float length = sqrt(dx * dx + dy * dy);
                            
                            if (length > 0) {
                                // Normalize direction vector
                                dx /= length;
                                dy /= length;
                                
                                // Reverse velocities for both creatures
                                velocidadX = dx * criatura->GetVelocidad();
                                velocidadY = dy * criatura->GetVelocidad();
                                
                                // Move creatures apart to prevent sticking
                                float newX = otraCriatura->GetX() + dx * 60.0f;
                                float newY = otraCriatura->GetY() + dy * 60.0f;
                                criatura->SetPos(newX, newY);
                                
                                return;
                            }
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
