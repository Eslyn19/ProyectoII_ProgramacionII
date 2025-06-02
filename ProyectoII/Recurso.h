#pragma once
#include <string>
#include "raylib.h"
#include "Observador.h"

class Recurso : public Observador {
public:
    Recurso(const char* ruta, float _x, float _y);
    virtual ~Recurso();

    virtual void Dibujar() = 0;
    float GetX() const;
    float GetY() const;
    float GetAncho() const { return ancho; }
    float GetAlto() const { return alto; }
    virtual std::string GetTipoRecurso() const;
    virtual void Actualizar(const std::string& clima);

protected:
    float x, y;
    int vida;
	float ancho;
	float alto;
    Texture2D textura;
    float tiempoUltimaActualizacion;
    float tiempoDecaimiento;
};