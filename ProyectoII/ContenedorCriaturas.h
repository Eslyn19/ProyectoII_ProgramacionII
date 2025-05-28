#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class ContenedorCriaturas {
public:
    ContenedorCriaturas();
    ~ContenedorCriaturas();
    
    void AgregarCriatura(Criatura* criatura);
    void DibujarCriaturas();
    void ActualizarCriaturas();
    void AplicarEstrategiaMovimiento(EstrategiaMovimiento* estrategia);
    
private:
    Criatura** criaturas;        
    int capacidad;               
    int cantidadCriaturas;       
    void Redimensionar();       
}; 