#include "ContenedorCriaturas.h"

// Constructor
ContenedorCriaturas::ContenedorCriaturas() : capacidad(10), cantidadCriaturas(0) {
    criaturas = new Criatura*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        criaturas[i] = nullptr;
    }
}

// Destructor
ContenedorCriaturas::~ContenedorCriaturas() {}

void ContenedorCriaturas::Redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    Criatura** nuevoArreglo = new Criatura*[nuevaCapacidad];
    
    for (int i = 0; i < nuevaCapacidad; i++) {
        nuevoArreglo[i] = nullptr;
    }
    
    for (int i = 0; i < cantidadCriaturas; i++) {
        nuevoArreglo[i] = criaturas[i];
    }
  
    delete[] criaturas;
    criaturas = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

void ContenedorCriaturas::AgregarCriatura(Criatura* criatura) {
    if (criatura == nullptr) return; 
    
    if (cantidadCriaturas >= capacidad) {
        Redimensionar();
    }
    
    criaturas[cantidadCriaturas] = criatura;
    cantidadCriaturas++;
}

void ContenedorCriaturas::DibujarCriaturas() {
    for (int i = 0; i < cantidadCriaturas; i++) {
        if (criaturas[i] != nullptr) {
            criaturas[i]->Dibujar();
        }
    }
}
void ContenedorCriaturas::ActualizarCriaturas() {
    for (int i = 0; i < cantidadCriaturas; i++) {
        if (criaturas[i] != nullptr) {
            criaturas[i]->Actualizar();
        }
    }
}

void ContenedorCriaturas::AplicarEstrategiaMovimiento(EstrategiaMovimiento* estrategia) {
    if (estrategia == nullptr) return;

    for (int i = 0; i < cantidadCriaturas; i++) {
        if (criaturas[i] != nullptr) {
            criaturas[i]->SetEstrategiaMovimiento(estrategia);
        }
    }
}
