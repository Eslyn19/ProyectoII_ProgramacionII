#include "Ecosistema.h"

// Variables para guardar palabra en el campo de texto
char comando[64] = "";
bool textFieldActivo = false;
std::string resultadoComando = "";

// Consructor
Ecosistema::Ecosistema(std::string _nombre) : nombre(_nombre) {}

// Funcion para crear el campo de texto en pantallas para los comandos
bool Ecosistema::CampoTexto(Rectangle recCampo, Rectangle recBoton, char* buffer, int bufferSize, bool& activo)
{
    Vector2 mouse = GetMousePosition();
    bool hoverCampo = CheckCollisionPointRec(mouse, recCampo);
    bool clickCampo = hoverCampo && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    bool clickBoton = CheckCollisionPointRec(mouse, recBoton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    if (clickCampo) activo = true;
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !hoverCampo && !clickBoton) activo = false;

    DrawRectangleRec(recCampo, activo ? Fade(BLUE, 0.3f) : Fade(GRAY, 0.5f));
    DrawRectangleLinesEx(recCampo, 2, activo ? BLUE : DARKGRAY);

    if (activo)
    {
        int key = GetCharPressed();
        while (key > 0)
        {
            if (key >= 32 && key <= 125 && strlen(buffer) < bufferSize - 1)
            {
                int len = strlen(buffer);
                buffer[len] = (char)key;
                buffer[len + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && strlen(buffer) > 0)
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
    }

    if (strlen(buffer) == 0 && !activo)
    {
        DrawText("Escribir comando...", recCampo.x + 5, recCampo.y + 10, 20, Fade(DARKGRAY, 0.5f));
    }
    else
    {
        DrawText(buffer, recCampo.x + 5, recCampo.y + 10, 20, BLACK);
    }

    DrawRectangleRec(recBoton, GRAY);
    DrawRectangleLinesEx(recBoton, 2, DARKGRAY);
    int textWidth = MeasureText("Ejecutar", 20);
    DrawText("Ejecutar", recBoton.x + (recBoton.width - textWidth) / 2, recBoton.y + 10, 20, WHITE);

    return clickBoton;
}

// Funcion para crear boton en la interfaz de menu
bool Ecosistema::CrearBoton(Rectangle rec, const char* texto) 
{
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, rec);
    bool click = hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    DrawRectangleRec(rec, hover ? Fade(GREEN, 0.7f) : Fade(GRAY, 0.5f));
    DrawRectangleLinesEx(rec, 2, DARKGRAY);

    int textWidth = MeasureText(texto, 20);
    int textX = rec.x + (rec.width - textWidth) / 2;
    int textY = rec.y + (rec.height - 20) / 2;

    DrawText(texto, textX, textY, 20, WHITE);
    return click;
}

void Ecosistema::IniciarAplicacion()
{
	// Definir dimensiones de la ventana
    const int ancho = 1024;
	const int altura = 768;

	// Crear ventana y audio
    InitWindow(ancho, altura, TITULO_VENTANA);
    InitAudioDevice();
    SetTargetFPS(60);

    // Asignar recursos
    Image logo = LoadImage(LOGO);
    Texture2D fondo = LoadTexture(INICIO);
    Texture2D fondoSimulacion = LoadTexture(JUEG0_SIMULACION);
    Music musicaSimulacion = LoadMusicStream(MUSICA_SIMULACION);
    Music musica = LoadMusicStream(MUSICA);

    // cargar recursos
    SetWindowIcon(logo);
    SetMusicVolume(musica, 0.5f);
    PlayMusicStream(musica);

    // Crear criaturas
    FabricaAbstracta* fabrica = new FabricaConcreta();
    Criatura* herbivoro = fabrica->CrearHerbivoro("Herbivoro.png", 700, 100, 800, 100, VEL_HERB);
    Criatura* carnivoro = fabrica->CrearCarnivoro("Carnivoro.png", 200, 200, 800, 100, VEL_CARN);
    Criatura* omnivoro = fabrica->CrearOmnivoro("omnivoro.png", 300, 300, 800, 100, VEL_OMNI);

    // Crear recursos
    FabricaRecursoAbstracta* fabricaRecursos = new FabricaRecursoConcreta();
    Recurso* carne = fabricaRecursos->CrearCarne("Carne.png", 400, 400, 100);
    Recurso* planta = fabricaRecursos->CrearPlanta("Planta.png", 500, 500, 100);
    Recurso* agua = fabricaRecursos->CrearAgua("agua.png", 600, 600, 100);

    // Crear contenedor
	ContenedorCriaturas ContCriaturas;

    // Asignar el movimiento a las criaturas
	EstrategiaMovimiento* estrategiaMovimiento = new EstrategiaMovimiento();
	ContCriaturas.AplicarEstrategiaMovimiento(estrategiaMovimiento);

    // agregar al Contenedor de criaturas
    ContCriaturas.AgregarCriatura(herbivoro);
    ContCriaturas.AgregarCriatura(carnivoro);
    ContCriaturas.AgregarCriatura(omnivoro);

    GameScreen currentScreen = MENU;
    while (!WindowShouldClose() && currentScreen != SALIR)
    {
		// Actualizar musica
        if (currentScreen == MENU) {
            UpdateMusicStream(musica);
        }
        else {
            StopMusicStream(musica);
        }
        
		// Actualizar pantalla
        BeginDrawing();

        switch (currentScreen)
        {
            case MENU:
            {
                // Empezar musica del menu
                UpdateMusicStream(musica);
                StopMusicStream(musicaSimulacion);

                // Cargar imagen al menu
                DrawTexture(fondo, 0, 0, WHITE);

			    // Crear botones de inicio y salir
                float offsetY = altura * 0.05f;
                Rectangle botonSimular = { ancho / 2.0f - 100, 350 - offsetY, 200, 50 };
                Rectangle botonSalir = { ancho / 2.0f - 100, 420 - offsetY, 200, 50 };

                // Verificar si se cambia a simulacion
                if (CrearBoton(botonSimular, "Iniciar Simulacion")) {
                    currentScreen = SIMULACION;
                }

                // Verificar si cambia a salir
                if (CrearBoton(botonSalir, "Salir")) {
                    currentScreen = SALIR;
                }
            } 
            break;
        
            case SIMULACION:
            {
				// Cargar musica del modo de juego simulacion
                UpdateMusicStream(musicaSimulacion);
                StopMusicStream(musica);

                // Verificar que se cargue correctamente
                if (!IsMusicStreamPlaying(musicaSimulacion)) {
                    PlayMusicStream(musicaSimulacion);
                }

				// Cargar imagen de simulacion en la ventana
                ClearBackground(WHITE);
                DrawTexture(fondoSimulacion, 0, 0, WHITE);

                // Crear linea separadora del juego y de los comandos
                DrawLineEx(Vector2{ 0, 100 }, Vector2{ (float)ancho, 100 }, 3.0f, DARKGRAY);

                // Dibujar las criaturas en la pantalla
                ContCriaturas.DibujarCriaturas();
			    ContCriaturas.ActualizarCriaturas();

                // Dibujar los recursos
			    carne->Dibujar();
			    planta->Dibujar();
			    agua->Dibujar();

                // Boton regresar detiene y carga la musica de las ventanas
                Rectangle botonRegresar = { 10, 25, 200, 50 };
                if (CrearBoton(botonRegresar, "Regresar"))
                {
                    currentScreen = MENU;
                    PlayMusicStream(musica);
                }

                if (IsKeyPressed(KEY_ESCAPE))
                {
                    currentScreen = MENU;
                    PlayMusicStream(musica);
                }

                // Dibujar el campo de texto y boton de ejecutar en la parte arriba de simulacion
                Rectangle campoTexto = { (ancho - 300) / 2.0f, 20, 300, 40 };
                Rectangle botonEjecutar = { campoTexto.x + campoTexto.width + 10, 20, 120, 40 };

                if (CampoTexto(campoTexto, botonEjecutar, comando, 64, textFieldActivo)) { comando[0] = '\0'; }

            } 
            break;
        }
        // Terminar de dibujar las ventanas
        EndDrawing();
    }

    // Limpiar recursos
    StopMusicStream(musica);
    UnloadMusicStream(musica);
    UnloadTexture(fondo);
    UnloadTexture(fondoSimulacion);
    UnloadImage(logo);
  
    // Liberar memoria
    delete herbivoro;
    delete carnivoro;
    delete omnivoro;
    delete fabrica;
    delete carne;
    delete planta;
    delete agua;
    delete fabricaRecursos;
    delete estrategiaMovimiento;

    // Cerrar archivos
    CloseAudioDevice();
    CloseWindow();
}

// Destructor
Ecosistema::~Ecosistema() {
    CloseAudioDevice();
    CloseWindow();
}