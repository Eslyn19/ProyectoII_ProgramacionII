#pragma once
#include <string>

class Observador {
public:
    virtual ~Observador() = default;
    virtual void Actualizar(const std::string& clima) = 0;
}; 