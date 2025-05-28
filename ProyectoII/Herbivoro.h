#pragma once
#include "Criatura.h"

class Herbivoro : public Criatura {
public:
    Herbivoro(const char* ruta, float _x, float _y, int ancho, int _energia = 100, float _velocidad = 2.0f);
    ~Herbivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 