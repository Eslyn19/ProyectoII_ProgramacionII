#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Herbivoro : public Criatura {
public:
    Herbivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad);
    ~Herbivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 