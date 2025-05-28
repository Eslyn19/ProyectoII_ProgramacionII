#pragma once
#include "Criatura.h"

class Criatura;

class Estrategia {
public:
    virtual ~Estrategia() = default;
    virtual void Mover(Criatura* criatura) = 0;
};
