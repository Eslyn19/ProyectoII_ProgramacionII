#pragma once
#include "Criatura.h"

class Herbivoro : public Criatura {
public:
    Herbivoro(const char* ruta, float x, float y, int ancho);
    ~Herbivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 