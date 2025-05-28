#pragma once
#include "raylib.h"
#include "Estrategias.h"
#include "EstrategiaMovimiento.h"

// Implementacion patron Estrategia
class EstrategiaMovimiento;

class Criatura {
public:
    Criatura(const char* ruta, float _x, float _y, int ancho, int _energia = 100, float _velocidad = 2.0f);
    virtual ~Criatura();

    virtual void Dibujar() = 0;
    virtual void Actualizar() = 0;

    // Metodos Get
    float GetX() const;
    float GetY() const;
    int GetAnchoPantalla() const;
    int GetEnergia() const;
    float GetVelocidad() const;

    // Metodos Set
    void SetPos(float _x, float _y);
    void SetEnergia(int _energia);
    void SetVelocidad(float _velocidad);
    void SetEstrategiaMovimiento(EstrategiaMovimiento* _movimiento);

protected:
    float x, y;
    float velocidad;
    int energia;
    int pantallaAncho;
    Vector2 posicion;
    Texture2D textura;
    EstrategiaMovimiento* movimiento;
}; 