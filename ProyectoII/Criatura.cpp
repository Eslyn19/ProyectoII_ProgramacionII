#include "Criatura.h"

Criatura::Criatura(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad) {
    x = _x;
    y = _y;
    ancho = ancho;
    alto = alto;
    velocidad = _velocidad;
    textura = LoadTexture(ruta);
    movimiento = nullptr;
    alimento = nullptr;
    morir = nullptr;
    ultimoTiempoComida = GetTime();
}

void Criatura::Actualizar() {
    if (movimiento != nullptr) {
        movimiento->Mover(this);
    }
    if (alimento != nullptr) {
        alimento->Mover(this);
    }
    if (morir != nullptr) {
        morir->Mover(this);
    }
}

float Criatura::GetX() const { return x; }

float Criatura::GetY() const { return y; }

int Criatura::GetAncho() const { return ancho; }

int Criatura::GetAlto() const { return alto; }

float Criatura::GetVelocidad() const { return velocidad; }

EstrategiaMovimiento* Criatura::GetEstrategiaMovimiento() const { return movimiento; }

EstrategiaAlimento* Criatura::GetEstrategiaAlimento() const { return alimento; }

EstrategiaMorir* Criatura::GetEstrategiaMorir() const { return morir; }

float Criatura::GetUltimoTiempoComida() const { return ultimoTiempoComida; }

void Criatura::SetUltimoTiempoComida(float tiempo) { ultimoTiempoComida = tiempo; }

void Criatura::SetPos(float _x, float _y) {
    x = _x;
    y = _y;
}

void Criatura::SetVelocidad(float _velocidad) {
    velocidad = _velocidad;
}

void Criatura::SetEstrategiaMovimiento(EstrategiaMovimiento* _movimiento) {
    if (movimiento != nullptr) {
        delete movimiento;
    }
    movimiento = _movimiento;
}

void Criatura::SetEstrategiaAlimento(EstrategiaAlimento* _alimento) {
    alimento = _alimento;
}

void Criatura::SetEstrategiaMorir(EstrategiaMorir* _morir) {
    if (morir != nullptr) {
        delete morir;
    }
    morir = _morir;
}

Criatura::~Criatura() {
    UnloadTexture(textura);
} 