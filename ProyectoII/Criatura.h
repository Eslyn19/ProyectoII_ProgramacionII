#pragma once
#include "raylib.h"

class Criatura {
public:
    Criatura(const char* ruta, float _x, float _y, int ancho);
    virtual ~Criatura();

    virtual void Dibujar() = 0;
    virtual void Actualizar() = 0;

    // Getters
    float GetX() const { return x; }
    float GetY() const { return y; }
    int GetAnchoPantalla() const { return pantallaAncho; }

    // Setters
    void SetPos(float _x, float _y);

protected:
    float x, y;
    int energia;
    int pantallaAncho;
    Vector2 posicion;
    Texture2D textura;
}; 