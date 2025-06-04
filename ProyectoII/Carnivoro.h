#pragma once
#include "Criatura.h"
#include "Estrategias.h"

class Carnivoro : public Criatura {
public:
    Carnivoro(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad);
    virtual ~Carnivoro() = default;

    // metodos para pintar en pantalla
    void Dibujar() override;
    void Actualizar() override;
}; 