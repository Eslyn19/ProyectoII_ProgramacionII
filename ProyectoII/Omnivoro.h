#pragma once
#include "Criatura.h"

class Omnivoro : public Criatura {
public:
    Omnivoro(const char* ruta, float x, float y, int ancho);
    ~Omnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 