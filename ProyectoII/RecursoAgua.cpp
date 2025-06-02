#include "RecursoAgua.h"
#include "raylib.h"

Agua::Agua(const char* ruta, float _x, float _y)
    : Recurso(ruta, _x, _y) {
}

Agua::~Agua() {}

void Agua::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

std::string Agua::GetTipoRecurso() const { return "Agua"; }

void Agua::Actualizar(const std::string& clima) {
    if (clima == "lluvia") {
        TraceLog(LOG_INFO, "Agua: El clima lluvioso favorece la generación de agua");
    } else if (clima == "soleado") {
        TraceLog(LOG_INFO, "Agua: El clima soleado puede evaporar el agua");
    } else if (clima == "nieve") {
        TraceLog(LOG_INFO, "Agua: El clima nevado puede congelar el agua");
    }
}


