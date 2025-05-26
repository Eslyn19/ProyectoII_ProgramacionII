/* -------------------------------------------------------------------+
 * |
 * (c) 2025 |
 * EIF204 - Programacion 2 |
 * 1er ciclo 2025 |
 * NRC 41367 � Grupo 02 |
 * Proyecto II |
 * | Estudiante:
 * 2-0838-0902; Jara Calderon, Eslyn |
 * |
 * version 1.0.0 2025-05-22 |
 * |
 * Link Github: https://github.com/Eslyn19/ProyectoII_ProgramacionII
 * |
 * -------------------------------------------------------------------+
 */

/* Creditos imagenes:
   https://www.flaticon.com/free-icons/dinosaur
   https://es.vecteezy.com

   Creditos musica:
   Quincas Moreira - Robot City 8bit Music
*/

#include "Ecosistema.h"

int main()
{
    Ecosistema ecosistema("Proyecto II - Simulacion Entorno");
    ecosistema.IniciarAplicacion();

    return 0;
}

 /*MostrarVentanaInicio();*/
 /*FabricaCriatura* FDO = NULL;

 FDO = new FabricaOmnivoro();*/
 // aqui ya tengo acceso a omnivoros

/*
#include "raylib.h"
#include <string>

class Dinosaurio {
private:
    Texture2D textura;
    Vector2 posicion;
    float velocidad;
    int pantallaAncho;

public:
    // Constructor permite indicar posición inicial (x, y)
    Dinosaurio(const char* rutaImagen, float x, float y, int anchoPantalla)
        : posicion({ x, y }), velocidad(100.0f), pantallaAncho(anchoPantalla)
    {
        textura = LoadTexture(rutaImagen);
    }

    ~Dinosaurio() {
        UnloadTexture(textura);
    }

    void actualizar(float delta) {
        posicion.x += velocidad * delta;

        // Rebote o reinicio cuando sale de pantalla
        if (posicion.x > pantallaAncho) {
            posicion.x = -textura.width;
        }
    }

    void dibujar() const {
        DrawTexture(textura, (int)posicion.x, (int)posicion.y, WHITE);
    }

    // Setters si los quieres cambiar luego
    void setPosicion(float x, float y) {
        posicion.x = x;
        posicion.y = y;
    }
};

int main() {
    const int pantallaAncho = 1200;
    const int pantallaAlto = 650;

    InitWindow(pantallaAncho, pantallaAlto, "Dinosaurio con coordenadas settable");
    SetTargetFPS(60);

    // Colocar el dinosaurio en posición inicial x = 100, y = 300
    Dinosaurio dino("Logo.png", 100.0f, 100.0f, pantallaAncho);
	Dinosaurio dino2("Omnivoro.png", 500.0f, 100.0f, pantallaAncho);

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        dino.actualizar(delta);
		dino2.actualizar(delta);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        dino.dibujar();
		dino2.dibujar();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}*/
