#pragma once
#include "Estrategias.h"
#include "RecursosContenedor.h"
#include "ContenedorCriaturas.h"
#include "raylib.h"

class EstrategiaMorir : public Estrategia {
public:
    EstrategiaMorir(RecursosContenedor* _contenedorRecursos, ContenedorCriaturas* _contenedorCriaturas);
    void Mover(Criatura* criatura) override;
    bool Alimentar(Criatura* criatura, Recurso* recurso) override;

private:
    void VerificarTiempoSinComer(Criatura* criatura);
    void GenerarRestos(Criatura* criatura);
    void EliminarCriatura(Criatura* criatura);

    RecursosContenedor* contenedorRecursos;
    ContenedorCriaturas* contenedorCriaturas;
    float tiempoMaximoSinComer;
}; 