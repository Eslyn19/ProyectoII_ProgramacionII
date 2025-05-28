#pragma once
#include "Recurso.h"

class Agua : public Recurso {
public:
    Agua(const char* ruta, float _x, float _y, int _vida = 100);
    ~Agua() override;

    void Dibujar() override;
};