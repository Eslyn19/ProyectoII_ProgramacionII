#include "EstrategiaReproducir.h"
#include "raylib.h"
#include "FabricaConcreta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include "Omnivoro.h"
#include <random>
#include <iostream>

EstrategiaReproducir::EstrategiaReproducir(RecursosContenedor* _contRecursos, ContenedorCriaturas* _contCriaturas) 
    : contRecursos(_contRecursos), contCriaturas(_contCriaturas), ultimoTiempoReproduccion(0) {
}

void EstrategiaReproducir::Mover(Criatura* criatura) {
    const float TIEMPO_REPRODUCCION = 5.0f;  
    if (!criatura || !contCriaturas) {
        return;
    }

    float tiempoActual = GetTime();
    
    // Verificar si ha pasado el tiempo de espera
    if (tiempoActual - ultimoTiempoReproduccion < TIEMPO_REPRODUCCION) {
        return;
    }

    // Verificar colisiones con otras criaturas
    for (int i = 0; i < contCriaturas->GetCantidadCriaturas(); i++) {
        Criatura* otraCriatura = contCriaturas->GetCriatura(i);
        if (otraCriatura && otraCriatura != criatura) {
            if (HayColision(criatura, otraCriatura)) {
                if (SonMismoTipo(criatura, otraCriatura)) {
                    if (tiempoActual - ultimoTiempoReproduccion >= TIEMPO_REPRODUCCION) {
                        CrearNuevaCriatura(criatura);
                        ultimoTiempoReproduccion = tiempoActual;
                        return;
                    }
                }
            }
        }
    }
}

bool EstrategiaReproducir::SonMismoTipo(Criatura* c1, Criatura* c2) {
    if (dynamic_cast<Herbivoro*>(c1) && dynamic_cast<Herbivoro*>(c2)) 
        return true;
    if (dynamic_cast<Carnivoro*>(c1) && dynamic_cast<Carnivoro*>(c2)) 
        return true;
    if (dynamic_cast<Omnivoro*>(c1) && dynamic_cast<Omnivoro*>(c2)) 
        return true;
    return false;
}

bool EstrategiaReproducir::HayColision(Criatura* c1, Criatura* c2) {
    float dx = c1->GetX() - c2->GetX();
    float dy = c1->GetY() - c2->GetY();
    float distancia = sqrt(dx * dx + dy * dy);
    return distancia < 50.0f;
}

void EstrategiaReproducir::CrearNuevaCriatura(Criatura* criatura) {
    if (!contCriaturas) {
        return;
    }

    if (contCriaturas->GetCantidadCriaturas() >= ContenedorCriaturas::MAX_CRIATURAS) {
        return; 
    }

    FabricaAbstracta* fabrica = new FabricaConcreta();
    Criatura* nuevaCriatura = nullptr;
    float nuevaX = GenerarPosicionAleatoriaX();
    float nuevaY = GenerarPosicionAleatoriaY();

    if (dynamic_cast<Herbivoro*>(criatura)) {
        nuevaCriatura = fabrica->CrearHerbivoro(HERBIVORO_IMG, nuevaX, nuevaY, 100, 100, VEL_HERBI);
    }
    else if (dynamic_cast<Carnivoro*>(criatura)) {
        nuevaCriatura = fabrica->CrearCarnivoro(CARNIVORO_IMG, nuevaX, nuevaY, 100, 100, VEL_CARNI);
    }
    else if (dynamic_cast<Omnivoro*>(criatura)) {
        nuevaCriatura = fabrica->CrearOmnivoro(OMNIVORO_IMG, nuevaX, nuevaY, 100, 100, VEL_OMNIV);
    }

    if (nuevaCriatura != nullptr) {
        EstrategiaMovimiento* nuevaEstrategiaMovimiento = new EstrategiaMovimiento();
        nuevaEstrategiaMovimiento->SetContenedorCriaturas(contCriaturas);

        nuevaCriatura->SetEstrategiaMovimiento(nuevaEstrategiaMovimiento);
        nuevaCriatura->SetEstrategiaAlimento(new EstrategiaAlimento(contRecursos, contCriaturas));
        nuevaCriatura->SetEstrategiaReproducir(new EstrategiaReproducir(contRecursos, contCriaturas));
        nuevaCriatura->SetEstrategiaMorir(new EstrategiaMorir(contRecursos, contCriaturas));

        contCriaturas->AgregarCriatura(nuevaCriatura);
    } 

    delete fabrica;
}

float EstrategiaReproducir::GenerarPosicionAleatoriaX() {
    return (float)GetRandomValue(0, 899);  
}

float EstrategiaReproducir::GenerarPosicionAleatoriaY() {
    return (float)GetRandomValue(200, 800);  
}


void EstrategiaReproducir::ResetearContador() {
    ultimoTiempoReproduccion = 0;
} 