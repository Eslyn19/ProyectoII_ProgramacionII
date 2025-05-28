#pragma once
#include "Recurso.h"

class Carne : public Recurso {
public:
    Carne(const char* ruta, float _x, float _y, int _vida);
    ~Carne() override;

    void Dibujar() override;

};