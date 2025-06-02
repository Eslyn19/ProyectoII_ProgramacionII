#pragma once
#include "Recurso.h"

class Planta : public Recurso {
public:
    Planta(const char* ruta, float _x, float _y);
    ~Planta() override;

    void Dibujar() override;
    std::string GetTipoRecurso() const override;
    void Actualizar(const std::string& clima) override;
};