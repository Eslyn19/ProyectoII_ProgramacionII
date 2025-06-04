#include "RecursoPlanta.h"
#include "raylib.h"

Planta::Planta(const char* ruta, float _x, float _y)
    : Recurso(ruta, _x, _y) {
}

Planta::~Planta() {}

void Planta::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

std::string Planta::GetTipoRecurso() const { return "Planta"; }

void Planta::Actualizar(const std::string& clima) {
	// Mostrar cambio de clima en la consola
    if (clima == "lluvia") {
        TraceLog(LOG_INFO, "Planta: El clima lluvioso favorece el crecimiento de las plantas");
    } else if (clima == "soleado") {
        TraceLog(LOG_INFO, "Planta: El clima soleado es ideal para la fotosíntesis");
    } else if (clima == "nieve") {
        TraceLog(LOG_INFO, "Planta: El clima nevado puede afectar el crecimiento de las plantas");
    }
}

