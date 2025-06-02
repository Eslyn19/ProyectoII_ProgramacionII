#pragma once
#include "Recurso.h"

class Carne : public Recurso {
public:
    Carne(const char* ruta, float _x, float _y);
    ~Carne() override;

    void Dibujar() override;
    std::string GetTipoRecurso() const override;
    void Actualizar(const std::string& clima) override;
};