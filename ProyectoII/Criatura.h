#pragma once
#include "raylib.h"
#include "Estrategias.h"
#include "EstrategiaMovimiento.h"
#include "EstrategiaAlimento.h"
#include <string>

class EstrategiaMovimiento;
class EstrategiaAlimento;

class Criatura {
public:
    Criatura(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad);
    virtual ~Criatura();

    virtual void Dibujar() = 0;
    virtual void Actualizar();

    // Getters
    float GetX() const;
    float GetY() const;
    int GetAncho() const;
    int GetAlto() const;
    float GetVelocidad() const;
    EstrategiaMovimiento* GetEstrategiaMovimiento() const;
    EstrategiaAlimento* GetEstrategiaAlimento() const;

    // Setters
    void SetPos(float _x, float _y);
    void SetVelocidad(float _velocidad);
    void SetEstrategiaMovimiento(EstrategiaMovimiento* _movimiento);
    void SetEstrategiaAlimento(EstrategiaAlimento* _alimento);

protected:
    float x, y;
    int ancho;
    int alto;
    float velocidad;
    Texture2D textura;
    EstrategiaMovimiento* movimiento;
    EstrategiaAlimento* alimento;
};