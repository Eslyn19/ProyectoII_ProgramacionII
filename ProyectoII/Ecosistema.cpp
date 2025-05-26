#include "Ecosistema.h"

char comando[64] = "";
bool textFieldActivo = false;
std::string resultadoComando = "";

Ecosistema::Ecosistema(std::string _nombre) : nombre(_nombre) {}

// Funcion para crear placeholder
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

// Funcion para crear boton en la interfaz de menu (Iniciar & salir)
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
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Simulacion");
    InitAudioDevice();
    SetTargetFPS(60);

    // Cargar recursos [imagenes | musica | logos]
    Texture2D fondo = LoadTexture("InitStartup.jpeg");
    Texture2D fondoSimulacion = LoadTexture("FondoNature.jpg");
    Music musica = LoadMusicStream("Background.mp3");
    Music musicaSimulacion = LoadMusicStream("simulacion.mp3");
    Image logo = LoadImage("Logo.png");

    // Setear recursos
    SetWindowIcon(logo);
    SetMusicVolume(musica, 0.5f);
    PlayMusicStream(musica);
    Texture2D carnivoro = LoadTexture("Carnivoro.png");
    Texture2D herbivoro = LoadTexture("Herbivoro.png");
    Texture2D omnivoro = LoadTexture("Omnivoro.png");

    Vector2 posCarnivoro = { 100, 100 };
    Vector2 posHerbivoro = { 400, 300 };
    Vector2 posOmnivoro = { 700, 500 };

    Vector2 velCarnivoro = { 2.5f, 2.0f };
    Vector2 velHerbivoro = { -2.0f, 1.5f };
    Vector2 velOmnivoro = { 1.8f, -2.2f };

    GameScreen currentScreen = MENU;

    while (!WindowShouldClose() && currentScreen != SALIR)
    {
        if (currentScreen == MENU) UpdateMusicStream(musica);
        else StopMusicStream(musica);

        BeginDrawing();

        switch (currentScreen)
        {
        case MENU:
        {
            UpdateMusicStream(musica);
            StopMusicStream(musicaSimulacion);

            DrawTexture(fondo, 0, 0, WHITE);

            float offsetY = screenHeight * 0.05f;
            Rectangle botonSimular = { screenWidth / 2.0f - 100, 350 - offsetY, 200, 50 };
            Rectangle botonSalir = { screenWidth / 2.0f - 100, 420 - offsetY, 200, 50 };

            if (CrearBoton(botonSimular, "Iniciar Simulacion")) currentScreen = SIMULACION;
            if (CrearBoton(botonSalir, "Salir")) currentScreen = SALIR;
        } break;
        case SIMULACION:
        {
            UpdateMusicStream(musicaSimulacion);
            StopMusicStream(musica);

            // Entrar a simulación: reproducir música si no está sonando
            if (!IsMusicStreamPlaying(musicaSimulacion))
                PlayMusicStream(musicaSimulacion);

            ClearBackground(WHITE);
            DrawTexture(fondoSimulacion, 0, 0, WHITE);
            DrawLineEx(Vector2{ 0, 100 }, Vector2{ (float)screenWidth, 100 }, 3.0f, DARKGRAY);

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

            posCarnivoro.x += velCarnivoro.x;
            posCarnivoro.y += velCarnivoro.y;
            if (posCarnivoro.x <= 0 || posCarnivoro.x + carnivoro.width >= screenWidth) velCarnivoro.x *= -1;
            if (posCarnivoro.y <= 100 || posCarnivoro.y + carnivoro.height >= screenHeight) velCarnivoro.y *= -1;

            posHerbivoro.x += velHerbivoro.x;
            posHerbivoro.y += velHerbivoro.y;
            if (posHerbivoro.x <= 0 || posHerbivoro.x + herbivoro.width >= screenWidth) velHerbivoro.x *= -1;
            if (posHerbivoro.y <= 100 || posHerbivoro.y + herbivoro.height >= screenHeight) velHerbivoro.y *= -1;

            posOmnivoro.x += velOmnivoro.x;
            posOmnivoro.y += velOmnivoro.y;
            if (posOmnivoro.x <= 0 || posOmnivoro.x + omnivoro.width >= screenWidth) velOmnivoro.x *= -1;
            if (posOmnivoro.y <= 100 || posOmnivoro.y + omnivoro.height >= screenHeight) velOmnivoro.y *= -1;

            DrawTexture(carnivoro, (int)posCarnivoro.x, (int)posCarnivoro.y, WHITE);
            DrawTexture(herbivoro, (int)posHerbivoro.x, (int)posHerbivoro.y, WHITE);
            DrawTexture(omnivoro, (int)posOmnivoro.x, (int)posOmnivoro.y, WHITE);
            Rectangle campoTexto = { (screenWidth - 300) / 2.0f, 20, 300, 40 };
            Rectangle botonEjecutar = { campoTexto.x + campoTexto.width + 10, 20, 120, 40 };

            if (CampoTexto(campoTexto, botonEjecutar, comando, 64, textFieldActivo))
            {
                resultadoComando = comando;  // Aquí capturas el texto al hacer clic
                comando[0] = '\0';           // Limpia el campo si quieres
            }

            // Puedes dibujar lo que devolvió el comando
            if (!resultadoComando.empty())
            {
                DrawText(("Resultado: " + resultadoComando).c_str(), 20, 75, 20, DARKGRAY);
            }

        } break;
        }
        EndDrawing();
    }

	// Limpiar recursos
    StopMusicStream(musica);
    UnloadMusicStream(musica);
    UnloadTexture(fondo);
    UnloadTexture(fondoSimulacion);
    UnloadTexture(carnivoro);
    UnloadTexture(herbivoro);
    UnloadTexture(omnivoro);
   
	// Cerrar recursos
    CloseAudioDevice();
    CloseWindow();
}

Ecosistema::~Ecosistema() {}