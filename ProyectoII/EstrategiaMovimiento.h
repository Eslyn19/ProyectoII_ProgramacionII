#pragma once
#include "Estrategias.h"

class ContenedorCriaturas;

class EstrategiaMovimiento : public Estrategia {
public:
    EstrategiaMovimiento();
    void Mover(Criatura* criatura) override;
    bool Alimentar(Criatura* criatura, Recurso* recurso) override;
    void SetContenedorCriaturas(ContenedorCriaturas* _contenedor);
private:
    float velocidadX;
    float velocidadY;
    ContenedorCriaturas* contenedorCriaturas;
};