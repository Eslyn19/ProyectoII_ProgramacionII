#include "EstrategiaAlimento.h"
#include "Criatura.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"
#include "RecursoCarne.h"
#include "RecursoPlanta.h"
#include "RecursoAgua.h"
#include "raylib.h"
#include <cmath>

EstrategiaAlimento::EstrategiaAlimento(RecursosContenedor* _contenedorRecursos, ContenedorCriaturas* _contenedorCriaturas)
    : contenedorRecursos(_contenedorRecursos), contenedorCriaturas(_contenedorCriaturas) {
}

void EstrategiaAlimento::Mover(Criatura* criatura) {
    if (!criatura) {
        return;
    }
    VerificarColisionConRecursos(criatura);
}

bool EstrategiaAlimento::Alimentar(Criatura* criatura, Recurso* recurso) {
	if (!criatura || !recurso) {
		return false;
	}

    bool puedeComer = false;

    if (dynamic_cast<Herbivoro*>(criatura)) {
        if (dynamic_cast<Planta*>(recurso) || dynamic_cast<Agua*>(recurso)) {
            puedeComer = true;
        }
    }

    else if (dynamic_cast<Carnivoro*>(criatura)) {
        if (dynamic_cast<Carne*>(recurso) || dynamic_cast<Agua*>(recurso)) {
            puedeComer = true;
        }
    }

    else if (dynamic_cast<Omnivoro*>(criatura)) {
        puedeComer = true;
    }

    if (puedeComer) {
        ConsumirRecurso(criatura, recurso);
        return true;
    }
    return false;
}

void EstrategiaAlimento::VerificarColisionConRecursos(Criatura* criatura) {
    if (!contenedorRecursos) {
        return;
    }

    int numRecursos = contenedorRecursos->GetCantidadRecursos();

    for (int i = 0; i < numRecursos; i++) {
        Recurso* recurso = contenedorRecursos->GetRecurso(i);
        if (recurso) {
            if (HayColisionConRecurso(criatura, recurso)) {
                if (Alimentar(criatura, recurso)) {
                    contenedorRecursos->EliminarRecurso(i);
                    i--;
                }
            }
        }
    }
}

bool EstrategiaAlimento::HayColisionConRecurso(Criatura* criatura, Recurso* recurso) {
    float dx = criatura->GetX() - recurso->GetX();
    float dy = criatura->GetY() - recurso->GetY();
    float distancia = std::sqrt(dx * dx + dy * dy);
    return distancia < 30.0f;
}

void EstrategiaAlimento::ConsumirRecurso(Criatura* criatura, Recurso* recurso) {
} 