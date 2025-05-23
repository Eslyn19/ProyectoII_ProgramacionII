#pragma once
#include "Ciclo.h"

class Dia : public Ciclo {
public:
    void mostrar() const override {
        std::cout << "Es de día." << std::endl;
    }
};
