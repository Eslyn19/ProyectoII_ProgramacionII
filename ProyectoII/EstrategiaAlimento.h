#pragma once
#include "Estrategias.h"
#include "RecursosContenedor.h"
#include "ContenedorCriaturas.h"
#include "raylib.h"

class EstrategiaAlimento : public Estrategia {
public:
    EstrategiaAlimento(RecursosContenedor* _contenedorRecursos, ContenedorCriaturas* _contenedorCriaturas);
    void Mover(Criatura* criatura) override;
    bool Alimentar(Criatura* criatura, Recurso* recurso) override;

private:
    void VerificarColisionConRecursos(Criatura* criatura);
    bool HayColisionConRecurso(Criatura* criatura, Recurso* recurso);
    void ConsumirRecurso(Criatura* criatura, Recurso* recurso);

    RecursosContenedor* contenedorRecursos;
    ContenedorCriaturas* contenedorCriaturas;
}; 