#pragma once
#include "Criatura.h"

class Carnivoro : public Criatura {
public:
    Carnivoro(const char* ruta, float _x, float _y, int ancho, int _energia = 100, float _velocidad = 3.0f);
    ~Carnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 