#pragma once
#include "Recurso.h"

class RecursosContenedor {
public:
    RecursosContenedor();
    ~RecursosContenedor();

    void AgregarRecurso(Recurso* recurso);
    void ActualizarRecursos(const std::string& clima);
    void DibujarRecursos();
    void EliminarRecurso(int indice);
    int GetCantidadRecursos() const;
    Recurso* GetRecurso(int index) const;

private:
    Recurso** recursoVec;
    int capacidad;
    int cantidadRecursos;
    void Redimensionar();
    static const int CAPACIDAD_INICIAL = 10;
};