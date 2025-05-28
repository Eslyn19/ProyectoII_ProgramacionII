#pragma once
#include "Criatura.h"

class Omnivoro : public Criatura {
public:
    Omnivoro(const char* ruta, float _x, float _y, int ancho, int _energia = 100, float _velocidad = 2.5f);
    ~Omnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 