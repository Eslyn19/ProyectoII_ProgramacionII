#pragma once
#include "Recurso.h"

class Agua : public Recurso {
public:
    Agua(const char* ruta, float _x, float _y);
    ~Agua() override;

    void Dibujar() override;
    std::string GetTipoRecurso() const override;
    void Actualizar(const std::string& clima) override;
};