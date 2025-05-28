#pragma once
#include "raylib.h"

class Criatura {
public:
    Criatura(const char* ruta, float _x, float _y, int ancho, int _energia = 100, float _velocidad = 2.0f);
    virtual ~Criatura();

    virtual void Dibujar() = 0;
    virtual void Actualizar() = 0;

    // Getters
    float GetX() const { return x; }
    float GetY() const { return y; }
    int GetAnchoPantalla() const { return pantallaAncho; }
    int GetEnergia() const { return energia; }
    float GetVelocidad() const { return velocidad; }

    // Setters
    void SetPos(float _x, float _y);
    void SetEnergia(int _energia) { energia = _energia; }
    void SetVelocidad(float _velocidad) { velocidad = _velocidad; }

  protected:
    float x, y;
    int energia;
    int pantallaAncho;
    Vector2 posicion;
    Texture2D textura;
    float velocidad;

}; 