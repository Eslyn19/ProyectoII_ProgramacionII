#pragma once
#include <cstdlib>  
#include <ctime>  
#include "Observador.h"
#include "FabricaRecursosAbstracta.h"
#include "RecursosContenedor.h"

#define CARNE_IMG "carne.png"
#define PLANTA_IMG "planta.png"
#define AGUA_IMG "agua.png"
#define TIEMPO_GENERACION 0.7f //Tiempo en segundos entre generación de recursos

class GeneradorRecursosObserver : public Observador {
private:
    FabricaRecursoAbstracta* fabrica;
    RecursosContenedor* contenedor;
    float ultimo;

    void GenerarPosicionAleatoria(float pos[2]);
    Recurso* GenerarRecursoConPesos(const std::string& clima);

public:
    GeneradorRecursosObserver(FabricaRecursoAbstracta* _fabrica, RecursosContenedor* _contenedor);
    virtual ~GeneradorRecursosObserver() = default;

    void Actualizar(const std::string& clima) override;
    void Update(float tiempoActual);
};
