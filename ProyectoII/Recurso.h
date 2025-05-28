#pragma once
#include "raylib.h"

class Recurso {
protected:
    Texture2D textura;
    float x;
    float y;
    int vida;
    int pantallaAncho;

public:
    Recurso(const char* ruta, float _x, float _y, int _vida);
    virtual ~Recurso();

    virtual void Dibujar() = 0;

    float GetX() const;
    float GetY() const;
    int GetVida() const;
    Texture2D GetTextura() const;

    void SetVida(int _vida);
    void SetPosicion(float _x, float _y);
};