#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class EstrategiaMovimiento;

class ContenedorCriaturas {
public:
    ContenedorCriaturas();
    ~ContenedorCriaturas();

    void AgregarCriatura(Criatura* criatura);
    void DibujarCriaturas();
    void ActualizarCriaturas();
    void AplicarEstrategiaMovimiento(EstrategiaMovimiento* estrategia);
    int GetCantidadCriaturas() const;
    Criatura* GetCriatura(int indice) const;
    void EliminarCriatura(int indice);
    void ReorganizarCriaturas();

private:
    Criatura** criaturas;
    int capacidad;
    int cantidadCriaturas;
    void Redimensionar();
};