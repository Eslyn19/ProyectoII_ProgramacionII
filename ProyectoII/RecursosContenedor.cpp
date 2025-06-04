#include "RecursosContenedor.h"
#include "raylib.h" 
#include "Entorno.h"

RecursosContenedor::RecursosContenedor() : capacidad(CAPACIDAD_INICIAL), cantidadRecursos(0) {
    recursoVec = new Recurso*[capacidad];
    for (int i = 0; i < capacidad; i++) {
        recursoVec[i] = nullptr;
    }
}

RecursosContenedor::~RecursosContenedor() {}

void RecursosContenedor::AgregarRecurso(Recurso* recurso) {
    if (cantidadRecursos >= capacidad) {
        Redimensionar();
    }
    recursoVec[cantidadRecursos++] = recurso;

    Entorno::GetInstancia()->AgregarObservador(recurso);
}

void RecursosContenedor::EliminarRecurso(int indice) {
    if (indice < 0 || indice >= cantidadRecursos) return;

    // Eliminar el recurso de los observadores antes de eliminarlo
    Entorno::GetInstancia()->EliminarObservador(recursoVec[indice]);

    // Mover el último recurso a la posición eliminada
    if (indice < cantidadRecursos - 1) {
        recursoVec[indice] = recursoVec[cantidadRecursos - 1];
    }
    
    // Limpiar la última posición
    recursoVec[cantidadRecursos - 1] = nullptr;
    cantidadRecursos--;
}

void RecursosContenedor::ActualizarRecursos(const std::string& clima) {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (recursoVec[i] != nullptr) { 
            recursoVec[i]->Actualizar(clima);
        }
    }
}

void RecursosContenedor::DibujarRecursos() {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (recursoVec[i] != nullptr) {
            recursoVec[i]->Dibujar();
        }
    }
}

int RecursosContenedor::GetCantidadRecursos() const { return cantidadRecursos; }

Recurso* RecursosContenedor::GetRecurso(int indice) const {
    if (indice >= 0 && indice < cantidadRecursos) {
        return recursoVec[indice];
    }
    return nullptr;
}

void RecursosContenedor::Redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    Recurso** nuevoArray = new Recurso*[nuevaCapacidad];
    
    for (int i = 0; i < nuevaCapacidad; i++) {
        nuevoArray[i] = nullptr;
    }
    
    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArray[i] = recursoVec[i];
    }
  
    delete[] recursoVec;
    recursoVec = nuevoArray;
    capacidad = nuevaCapacidad;
}