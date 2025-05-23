#pragma once
#include <raylib.h>

enum Pantalla { MENU, JUEGO, SALIR };
Pantalla pantallaActual = MENU;

bool BotonSimple(Rectangle rec, const char* texto) {
    Vector2 mousePos = GetMousePosition();
    bool hover = CheckCollisionPointRec(mousePos, rec);
    bool click = hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    Color colorFondo = (hover) ? Fade(GRAY, 0.7f) : Fade(GRAY, 0.5f);
    DrawRectangleRec(rec, colorFondo);

    int textWidth = MeasureText(texto, 20);
    int textX = (int)(rec.x + (rec.width - textWidth) / 2);
    int textY = (int)(rec.y + (rec.height - 20) / 2);

    DrawText(texto, textX, textY, 20, WHITE);

    return click;
}

void MostrarVentanaInicio() {
    SetTraceLogLevel(LOG_NONE);
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Inicio");

    Texture2D fondo = LoadTexture("InitStartup.jpeg");

    Image icon = LoadImage("Logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    InitAudioDevice();
    Music musica = LoadMusicStream("Background.mp3");
    if (musica.stream.buffer == NULL) {
        TraceLog(LOG_ERROR, "Failed to load music file");
    }
    else {
        PlayMusicStream(musica);
        SetMusicVolume(musica, 0.5f);
    }

    SetTargetFPS(60);

    Rectangle panel = { screenWidth / 2 - 150, screenHeight / 2 - 100, 300, 200 };

    while (!WindowShouldClose()) {
        UpdateMusicStream(musica); 

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(fondo, 0, 0, WHITE);
        DrawRectangleRec(panel, Fade(BLACK, 0.6f));
        DrawRectangleLinesEx(panel, 2, GRAY);

        switch (pantallaActual) {
        case MENU:
            if (BotonSimple({ panel.x + 50, panel.y + 50, 200, 40 }, "Iniciar Simulacion")) {
                pantallaActual = JUEGO;
            }
            if (BotonSimple({ panel.x + 50, panel.y + 110, 200, 40 }, "Salir")) {
                pantallaActual = SALIR;
            }
            break;

        case JUEGO:
            DrawText("Aqui iria el juego...", screenWidth / 2 - 100, screenHeight / 2, 20, BLACK);
            if (BotonSimple({ screenWidth / 2 - 100, screenHeight / 2 + 40, 200, 40 }, "Volver al Menu")) {
                pantallaActual = MENU;
            }
            break;

        case SALIR:
            return;
            break;
        }

        EndDrawing();
    }

    UnloadMusicStream(musica);
    UnloadTexture(fondo);
    CloseWindow();
}
