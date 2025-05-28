#pragma once
#include "Estrategias.h"

// Limites para el rebote de las criaturas
#define ANCHO_PANTALLA 1064
#define ALTO_PANTALLA 808
#define ANCHO_CRIATURA 100

class EstrategiaMovimiento : public Estrategia {
public:
    EstrategiaMovimiento();
    void Mover(Criatura* criatura) override;
private:
    float velocidadX;
    float velocidadY;
};
