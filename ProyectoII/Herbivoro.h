#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Herbivoro : public Criatura {
public:
    Herbivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad);
    virtual ~Herbivoro() = default;

    void Dibujar() override;
    void Actualizar() override;
}; 