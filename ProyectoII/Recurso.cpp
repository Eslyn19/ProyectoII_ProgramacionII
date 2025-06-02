#include "Recurso.h"
#include "raylib.h"

Recurso::Recurso(const char* ruta, float _x, float _y)
    : x(_x), y(_y) {
    textura = LoadTexture(ruta);
}

Recurso::~Recurso() {
    UnloadTexture(textura);
}

float Recurso::GetX() const { return x; }

float Recurso::GetY() const { return y; }

std::string Recurso::GetTipoRecurso() const { return "Recurso Desconocido"; }

void Recurso::Dibujar() {
    DrawTexture(textura, x, y, WHITE);
}

void Recurso::Actualizar(const std::string& clima) {
    TraceLog(LOG_INFO, TextFormat("%s: Clima actualizado a %s", GetTipoRecurso().c_str(), clima.c_str()));
}

