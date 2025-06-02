#pragma once

#include "Observador.h"
#include "FabricaRecursosAbstracta.h"
#include "RecursosContenedor.h"
#include <cstdlib>  
#include <ctime>  

#define CARNE_IMG "carne.png"
#define PLANTA_IMG "planta.png"
#define AGUA_IMG "agua.png"

class GeneradorRecursosObserver : public Observador {
private:
    FabricaRecursoAbstracta* fabrica;
    RecursosContenedor* contenedor;
    float ultimo;
    const float tiempoGen = 1.5f;

    void GenerarPosicionAleatoria(float pos[2]);
    Recurso* GenerarRecursoConPesos(const std::string& clima);

public:
    GeneradorRecursosObserver(FabricaRecursoAbstracta* _fabrica, RecursosContenedor* _contenedor);
    virtual ~GeneradorRecursosObserver() = default;

    void Actualizar(const std::string& clima) override;
    void Update(float tiempoActual);
};
