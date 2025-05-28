#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Carnivoro : public Criatura {
public:
    Carnivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad);
    ~Carnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 