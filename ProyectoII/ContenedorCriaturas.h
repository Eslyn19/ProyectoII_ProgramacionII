#pragma once
#include "Criatura.h"
#include "Estrategias.h"
#include "RecursosContenedor.h"

class EstrategiaMovimiento;

class ContenedorCriaturas {
public:
    static const int MAX_CRIATURAS = 30; // Evitar caida del sistema por sobrepoblacion
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
    void SetContenedorRecursos(RecursosContenedor* _contenedor);
    RecursosContenedor* GetContenedorRecursos() const;

private:
    Criatura** criaturas;
    int capacidad;
    int cantidadCriaturas;
    RecursosContenedor* contenedorRecursos;
    void Redimensionar();
};