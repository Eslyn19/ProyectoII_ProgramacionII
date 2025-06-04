#include "RecursosObserver.h"
#include "Entorno.h"
#include "raylib.h"

#define TIEMPO_GENERACION 0.5f //Tiempo en segundos entre generación de recursos

static bool rand_initialized = []() { std::srand(std::time(nullptr)); return true; }();

GeneradorRecursosObserver::GeneradorRecursosObserver(FabricaRecursoAbstracta* _fabrica, RecursosContenedor* _contenedor)
    : fabrica(_fabrica), contenedor(_contenedor), ultimo(0.0f) {
}

void GeneradorRecursosObserver::GenerarPosicionAleatoria(float pos[2]) {
    //  imites de ventana de juego
    pos[0] = 0.0f + (rand() % 900); // X (0 - 899)
    pos[1] = 130.0f + rand() % 600; // Y (130 - 729)
}

Recurso* GeneradorRecursosObserver::GenerarRecursoConPesos(const std::string& clima) {
    float pos[2];
    GenerarPosicionAleatoria(pos);

    int pesos[3];

    if (clima == "soleado") {
        pesos[0] = 40; pesos[1] = 40; pesos[2] = 20;
    }
    else if (clima == "lluvia") {
        pesos[0] = 25; pesos[1] = 25; pesos[2] = 50;
    }
    else if (clima == "nieve") {
        pesos[0] = 60; pesos[1] = 25; pesos[2] = 15;
    }

    int total = pesos[0] + pesos[1] + pesos[2];
    int r = rand() % total;

    int tipo = 0;
    if (r < pesos[0]) tipo = 0;
    else if (r < pesos[0] + pesos[1]) tipo = 1;
    else tipo = 2;

    switch (tipo) {
    case 0: return fabrica->CrearCarne(CARNE_IMG, pos[0], pos[1]);
    case 1: return fabrica->CrearPlanta(PLANTA_IMG, pos[0], pos[1]);
    case 2: return fabrica->CrearAgua(AGUA_IMG, pos[0], pos[1]);
    default: return nullptr;
    }
}

void GeneradorRecursosObserver::Actualizar(const std::string& clima) {}

void GeneradorRecursosObserver::Update(float tiempoActual) {
    if (tiempoActual - ultimo >= TIEMPO_GENERACION) {
        std::string climaActual = Entorno::GetInstancia()->GetClimaActual();
        Recurso* nuevoRecurso = GenerarRecursoConPesos(climaActual);
        
        if (nuevoRecurso != nullptr) {
            contenedor->AgregarRecurso(nuevoRecurso);
        }
        
        ultimo = tiempoActual;
    }
} 