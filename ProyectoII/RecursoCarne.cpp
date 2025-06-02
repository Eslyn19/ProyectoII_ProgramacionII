#include "RecursoCarne.h"
#include "raylib.h"

Carne::Carne(const char* ruta, float _x, float _y)
    : Recurso(ruta, _x, _y) {
}

Carne::~Carne() {}

void Carne::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

std::string Carne::GetTipoRecurso() const { return "Carne"; }

void Carne::Actualizar(const std::string& clima) {
    if (clima == "lluvia") {
        TraceLog(LOG_INFO, "Carne: El clima lluvioso puede acelerar la descomposición");
    } else if (clima == "soleado") {
        TraceLog(LOG_INFO, "Carne: El clima soleado puede secar la carne");
    } else if (clima == "nieve") {
        TraceLog(LOG_INFO, "Carne: El clima nevado puede preservar la carne");
    }
}

