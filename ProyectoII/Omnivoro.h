#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Omnivoro : public Criatura {
public:
    Omnivoro(const char* ruta, float _x, float _y, int ancho, int _energia, float _velocidad);
    ~Omnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 