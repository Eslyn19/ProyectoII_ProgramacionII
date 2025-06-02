#pragma once

class Criatura;
class Recurso;

class Estrategia {
public:
    virtual ~Estrategia() = default;
    virtual void Mover(Criatura* criatura) = 0;
    virtual bool Alimentar(Criatura* criatura, Recurso* recurso) = 0;
};

