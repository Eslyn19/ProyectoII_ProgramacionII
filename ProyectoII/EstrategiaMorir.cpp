#include "EstrategiaMorir.h"
#include "Criatura.h"
#include "RecursoCarne.h"
#include "raylib.h"

EstrategiaMorir::EstrategiaMorir(RecursosContenedor* _contenedorRecursos, ContenedorCriaturas* _contenedorCriaturas)
    : contenedorRecursos(_contenedorRecursos), contenedorCriaturas(_contenedorCriaturas), tiempoMaximoSinComer(10.0f) {
}

void EstrategiaMorir::Mover(Criatura* criatura) {
    if (!criatura) {
        return;
    }
    VerificarTiempoSinComer(criatura);
}

bool EstrategiaMorir::Alimentar(Criatura* criatura, Recurso* recurso) {
    if (criatura && recurso) {
        criatura->SetUltimoTiempoComida(GetTime());
    }
    return false;
}

void EstrategiaMorir::VerificarTiempoSinComer(Criatura* criatura) {
    float tiempoActual = GetTime();
    float ultimoTiempoComida = criatura->GetUltimoTiempoComida();
    
    if (tiempoActual - ultimoTiempoComida >= tiempoMaximoSinComer) {
        GenerarRestos(criatura);
        EliminarCriatura(criatura);
    }
}

void EstrategiaMorir::GenerarRestos(Criatura* criatura) {
    if (!contenedorRecursos) return;
    
    Carne* restos = new Carne("restos.png", criatura->GetX(), criatura->GetY());
    contenedorRecursos->AgregarRecurso(restos);
}

void EstrategiaMorir::EliminarCriatura(Criatura* criatura) {
    if (!contenedorCriaturas) return;
    
    for (int i = 0; i < contenedorCriaturas->GetCantidadCriaturas(); i++) {
        if (contenedorCriaturas->GetCriatura(i) == criatura) {
            contenedorCriaturas->EliminarCriatura(i);
            break;
        }
    }
} 