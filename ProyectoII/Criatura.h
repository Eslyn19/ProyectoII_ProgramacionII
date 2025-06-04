#pragma once
#include <string>
#include "raylib.h"
#include "Estrategias.h"
#include "EstrategiaMovimiento.h"
#include "EstrategiaAlimento.h"
#include "EstrategiaMorir.h"
#include "EstrategiaReproducir.h"

class EstrategiaMovimiento;
class EstrategiaAlimento;
class EstrategiaMorir;
class EstrategiaReproducir;

class Criatura {
public:
    Criatura(const char* ruta, float _x, float _y, int ancho, int alto, float _velocidad);
    virtual ~Criatura();

    virtual void Dibujar() = 0;
    virtual void Actualizar();

    // Getters
    float GetX() const;
    float GetY() const;
    int GetAncho() const;
    int GetAlto() const;
    float GetVelocidad() const;
    EstrategiaMovimiento* GetEstrategiaMovimiento() const;
    EstrategiaAlimento* GetEstrategiaAlimento() const;
    EstrategiaMorir* GetEstrategiaMorir() const;
    EstrategiaReproducir* GetEstrategiaReproducir() const;
    float GetUltimoTiempoComida() const;

    // Setters
    void SetPos(float _x, float _y);
    void SetVelocidad(float _velocidad);
    void SetEstrategiaMovimiento(EstrategiaMovimiento* _movimiento);
    void SetEstrategiaAlimento(EstrategiaAlimento* _alimento);
    void SetEstrategiaMorir(EstrategiaMorir* _morir);
    void SetEstrategiaReproducir(EstrategiaReproducir* _reproducir);
    void SetUltimoTiempoComida(float tiempo);

protected:
    float x, y;
    int ancho;
    int alto;
    float velocidad;
    Texture2D textura;

	// Estrategias
    EstrategiaMovimiento* movimiento;
    EstrategiaAlimento* alimento;
    EstrategiaMorir* morir;
    EstrategiaReproducir* reproducir;

    float ultimoTiempoComida;
};