#pragma once
#include <string>
#include "raylib.h"
#include "FabricaConcreta.h"
#include "FabricaAbstracta.h"
#include "FabricaRecursosConcreta.h"
#include "FabricaRecursosAbstracta.h"
#include "Estrategias.h"
#include "EstrategiaMovimiento.h"
#include "ContenedorCriaturas.h"

#define TITULO_VENTANA "Simulacion Entorno"

// Velocidad de las criaturas
#define VEL_CARN 3.0f
#define VEL_HERB 2.2f
#define VEL_OMNI 2.6f

// Ruta de recursos
#define INICIO "InitStartup.jpeg"
#define JUEG0_SIMULACION "FondoNature.jpg"
#define LOGO "Logo.png"
#define MUSICA "Background.mp3"
#define MUSICA_SIMULACION "simulacion.mp3"

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