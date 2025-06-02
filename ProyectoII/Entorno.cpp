#include "Entorno.h"

Entorno* Entorno::instancia = nullptr;

Entorno::Entorno() : climaActual("soleado"), musicaCargada(false), musicaActual(nullptr), fondosCargados(false) {
    capacidadObservadores = 10; 
    numObservadores = 0;
    observadores = new Observador*[capacidadObservadores];
    for (int i = 0; i < capacidadObservadores; i++) {
        observadores[i] = nullptr;
    }
    
    CargarMusicas();
    CargarFondos();
}

Entorno::~Entorno() {
    LiberarMusicas();
    LiberarFondos();
    delete[] observadores;
}

Entorno* Entorno::GetInstancia() {
    if (instancia == nullptr) {
        instancia = new Entorno();
    }
    return instancia;
}

void Entorno::CargarMusicas() {
    if (!musicaCargada) {
        musicaLluvia = LoadMusicStream(LLUVIA);
        musicaNieve = LoadMusicStream(NIEVE);
        musicaNormal = LoadMusicStream(SOLEADO);
        
        musicaActual = &musicaNormal;
        PlayMusicStream(*musicaActual);
        musicaCargada = true;
    }
}

void Entorno::CargarFondos() {
    if (!fondosCargados) {
        fondoSoleado = LoadTexture(FONDO_SOLEADO);
        fondoLLuvia = LoadTexture(FONDO_LLUVIA);
        fondoNieve = LoadTexture(FONDO_NIEVE);
        fondoActual = fondoSoleado; 
        fondosCargados = true;
    }
}

void Entorno::LiberarMusicas() {
    if (musicaCargada) {
        StopMusicStream(musicaLluvia);
        StopMusicStream(musicaNieve);
        StopMusicStream(musicaNormal);
        
        UnloadMusicStream(musicaLluvia);
        UnloadMusicStream(musicaNieve);
        UnloadMusicStream(musicaNormal);
        
        musicaCargada = false;
        musicaActual = nullptr;
    }
}

void Entorno::LiberarFondos() {
    if (fondosCargados) {
        UnloadTexture(fondoSoleado);
        UnloadTexture(fondoLLuvia);
        UnloadTexture(fondoNieve);
        fondosCargados = false;
    }
}

std::string Entorno::GetClimaActual() const { 
    return climaActual; 
}

void Entorno::CambiarClima(const std::string& nuevoClima) {
    if (nuevoClima == "lluvia" || nuevoClima == "nieve" || nuevoClima == "soleado") {
        // Detener la musica actual
        if (musicaActual != nullptr) {
            StopMusicStream(*musicaActual);
        }

        // Actualizar clima con su musica y fondo
        climaActual = nuevoClima;
        if (nuevoClima == "lluvia") {
            musicaActual = &musicaLluvia;
            fondoActual = fondoLLuvia;
        }
        else if (nuevoClima == "nieve") {
            musicaActual = &musicaNieve;
            fondoActual = fondoNieve;
        }
        else {
            musicaActual = &musicaNormal;
            fondoActual = fondoSoleado;
        }

        // Iniciar musica
        PlayMusicStream(*musicaActual);

        // Notificar a los observers del cambio de clima
        NotificarObservadores();
    }
}

void Entorno::ActualizarMusica() {
    if (musicaActual != nullptr) {
        UpdateMusicStream(*musicaActual);
    }
}

void Entorno::Update() {
    if (musicaActual != nullptr) {
        UpdateMusicStream(*musicaActual);
    }
}

// Implementación de los métodos del patrón Observer
void Entorno::AgregarObservador(Observador* observador) {
    if (observador != nullptr) {
        if (numObservadores >= capacidadObservadores) {
            int nuevaCapacidad = capacidadObservadores * 2;
            Observador** nuevoArray = new Observador*[nuevaCapacidad];
            
            for (int i = 0; i < numObservadores; i++) {
                nuevoArray[i] = observadores[i];
            }
            
            for (int i = numObservadores; i < nuevaCapacidad; i++) {
                nuevoArray[i] = nullptr;
            }
            
            delete[] observadores;
            observadores = nuevoArray;
            capacidadObservadores = nuevaCapacidad;
        }
        
        observadores[numObservadores++] = observador;
    }
}

void Entorno::EliminarObservador(Observador* observador) {
    for (int i = 0; i < numObservadores; i++) {
        if (observadores[i] == observador) {
            observadores[i] = observadores[numObservadores - 1];
            observadores[numObservadores - 1] = nullptr;
            numObservadores--;
            break;
        }
    }
}

void Entorno::NotificarObservadores() {
    for (int i = 0; i < numObservadores; i++) {
        if (observadores[i] != nullptr) {
            observadores[i]->Actualizar(climaActual);
        }
    }
} 