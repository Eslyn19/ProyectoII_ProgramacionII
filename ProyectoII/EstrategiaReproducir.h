#pragma once
#include "Estrategias.h"
#include "Criatura.h"
#include "ContenedorCriaturas.h"
#include "RecursosContenedor.h"
#include "raylib.h"

#define VEL_CARNI 2.5f
#define VEL_HERBI 2.0f
#define VEL_OMNIV 2.0f

#define HERBIVORO_IMG "Herbivoro.png"
#define CARNIVORO_IMG "Carnivoro.png"
#define OMNIVORO_IMG "omnivoro.png"

class EstrategiaReproducir : public Estrategia {
private:
    RecursosContenedor* contRecursos;
    ContenedorCriaturas* contCriaturas;
    int vecesComido;
    float tiempoInicio;
    float tiempoLimite;
    float ultimoTiempoReproduccion;

public:
    EstrategiaReproducir(RecursosContenedor* _contRecursos, ContenedorCriaturas* _contCriaturas);
    void Mover(Criatura* criatura) override;
	bool Alimentar(Criatura* criatura, Recurso* recurso) override { return false;}
    void ResetearContador();
    bool SonMismoTipo(Criatura* c1, Criatura* c2);
    void CrearNuevaCriatura(Criatura* criatura);
    bool HayColision(Criatura* c1, Criatura* c2);

    float GenerarPosicionAleatoriaX();
    float GenerarPosicionAleatoriaY();
}; 