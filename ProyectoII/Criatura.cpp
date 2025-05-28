#include "Criatura.h"

Criatura::Criatura(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad) {
    x = _x;
    y = _y;
    posicion = { x, y };
    pantallaAncho = ancho;
    energia = _energia;
    velocidad = _velocidad;
    textura = LoadTexture(ruta);
    movimiento = nullptr;
}

// Getters

float Criatura::GetX() const { return x; }

float Criatura::GetY() const { return y; }

int Criatura::GetAnchoPantalla() const { return pantallaAncho; }

int Criatura::GetEnergia() const { return energia; }

float Criatura::GetVelocidad() const { return velocidad; }

// Setters

void Criatura::SetEnergia(int _energia) { energia = _energia; }

void Criatura::SetVelocidad(float _velocidad) { velocidad = _velocidad; }

void Criatura::SetPos(float _x, float _y) {
    x = _x;
    y = _y;
    posicion = { x, y };
}

void Criatura::SetEstrategiaMovimiento(EstrategiaMovimiento* _movimiento) {
    if (movimiento != nullptr) {
        delete movimiento;
    }
    movimiento = _movimiento;
}

Criatura::~Criatura() {
    UnloadTexture(textura);
    if (movimiento != nullptr) {
        delete movimiento;
    }
} 