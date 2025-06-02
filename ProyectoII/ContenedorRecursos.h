#pragma once
#include "Recurso.h"

class ContenedorRecursos {
public:
    ContenedorRecursos();
    ~ContenedorRecursos();

	void AgregarRecurso(Recurso* recurso);
	void DibujarRecursos();
	int GetCantidadRecursos() const { return cantidadRecursos; }
	Recurso* GetRecurso(int index) const;

private:
    Recurso** recursoVec;
    int capacidad;
    int cantidadRecursos;
    void Redimensionar();
};