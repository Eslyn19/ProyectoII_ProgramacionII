#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "FabricaConcreta.h"
#include "FabricaAbstracta.h"

#include "FabricaRecursosConcreta.h"
#include "FabricaRecursosAbstracta.h"

enum GameScreen { MENU = 0, SIMULACION, SALIR };

class Ecosistema
{
public:
	Ecosistema(std::string _nombre);
	void IniciarAplicacion();
	bool CrearBoton(Rectangle rec, const char* texto);
	bool CampoTexto(Rectangle recCampo, Rectangle recBoton, char* buffer, int bufferSize, bool& activo);
	~Ecosistema();

private:
	std::string nombre;
};