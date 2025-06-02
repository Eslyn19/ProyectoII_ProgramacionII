#include "ContenedorCriaturas.h"
#include "EstrategiaMovimiento.h"

// Constructor
ContenedorCriaturas::ContenedorCriaturas() : capacidad(10), cantidadCriaturas(0) {
    criaturas = new Criatura*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        criaturas[i] = nullptr;
    }
}

// Destructor
ContenedorCriaturas::~ContenedorCriaturas() {
    for (int i = 0; i < cantidadCriaturas; i++) {
        if (criaturas[i] != nullptr) {
            delete criaturas[i];
        }
    }
    delete[] criaturas;
}

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

int ContenedorCriaturas::GetCantidadCriaturas() const {
	return cantidadCriaturas;
}

Criatura* ContenedorCriaturas::GetCriatura(int indice) const {
    if (indice >= 0 && indice < cantidadCriaturas) {
        return criaturas[indice];
    }
    return nullptr;
}

void ContenedorCriaturas::EliminarCriatura(int indice) {
    if (indice < 0 || indice >= cantidadCriaturas) return;
    
    if (criaturas[indice] != nullptr) {
        delete criaturas[indice];
        criaturas[indice] = nullptr;
    }
    
    ReorganizarCriaturas();
}

void ContenedorCriaturas::ReorganizarCriaturas() {
    int j = 0;
    for (int i = 0; i < cantidadCriaturas; i++) {
        if (criaturas[i] != nullptr) {
            if (i != j) {
                criaturas[j] = criaturas[i];
                criaturas[i] = nullptr;
            }
            j++;
        }
    }
    cantidadCriaturas = j;
}
