#pragma once
#include "Recurso.h"

class Planta : public Recurso {
public:
    Planta(const char* ruta, float _x, float _y, int _vida);
    ~Planta() override;

    void Dibujar() override;
};