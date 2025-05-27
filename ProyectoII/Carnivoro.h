#pragma once
#include "Criatura.h"

class Carnivoro : public Criatura {
public:
    Carnivoro(const char* ruta, float x, float y, int ancho);
    ~Carnivoro() override;

    void Dibujar() override;
    void Actualizar() override;
}; 