#pragma once
#include <string>
#include "raylib.h"
#include "Observador.h"

#define LLUVIA "lluvia.mp3"
#define SOLEADO "soleado.mp3"
#define NIEVE "nieve.mp3"

#define FONDO_SOLEADO "Desertico.png"
#define FONDO_LLUVIA "lluvia.png"
#define FONDO_NIEVE "Nevado.png"

class Entorno {
private:
    static Entorno* instancia;
    std::string climaActual;
   

    Music* musicaActual;
    Music musicaLluvia;
    Music musicaNieve;
    Music musicaNormal;
    bool musicaCargada;
    Texture2D fondoActual;
    Texture2D fondoSoleado;
    Texture2D fondoLLuvia;
    Texture2D fondoNieve;
    bool fondosCargados;

    Observador** observadores;
    int capacidadObservadores;
    int numObservadores;

    Entorno();
    ~Entorno();

public:
    static Entorno* GetInstancia();
    void CambiarClima(const std::string& nuevoClima);
    std::string GetClimaActual() const;

	// metodos de musica y fondo
    void ActualizarMusica();
    void CargarMusicas();
    void LiberarMusicas();
    void Update();
    Texture2D GetFondoActual() const;
    void CargarFondos();
    void LiberarFondos();
    
	// metodos de observador
    void AgregarObservador(Observador* observador);
    void EliminarObservador(Observador* observador);
    void NotificarObservadores();
}; 