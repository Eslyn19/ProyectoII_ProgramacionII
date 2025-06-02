#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Omnivoro : public Criatura {
public:
    Omnivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad);
    virtual ~Omnivoro() = default;

    void Dibujar() override;
    void Actualizar() override;
}; 