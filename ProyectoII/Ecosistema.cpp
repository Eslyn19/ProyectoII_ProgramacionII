#include "Ecosistema.h"
#include "Entorno.h"
#include "RecursosContenedor.h"
#include "RecursosObserver.h"
#include "EstrategiaMorir.h"
#include <thread>
#include <atomic>
#include <mutex>

// Variables para guardar palabra en el campo de texto
char comando[64] = "";
bool textFieldActivo = false;
std::string resultadoComando = "";

// Variables para el thread de colisiones
std::thread threadColisiones;
std::atomic<bool> ejecutandoColisiones(false);
std::mutex mutexColisiones;

// Función para el thread de colisiones
void ThreadColisiones(ContenedorCriaturas* contCriaturas, RecursosContenedor* contRecursos) {
    while (ejecutandoColisiones) {
        std::lock_guard<std::mutex> lock(mutexColisiones);
        int numCriaturas = contCriaturas->GetCantidadCriaturas();

        for (int i = 0; i < numCriaturas; i++) {
            Criatura* criatura = contCriaturas->GetCriatura(i);
            if (criatura) {
                EstrategiaAlimento* estrategia = criatura->GetEstrategiaAlimento();
                if (estrategia) {
                    estrategia->Mover(criatura);
                }
            }
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Consructor
Ecosistema::Ecosistema(std::string _nombre) : nombre(_nombre), simulacionActiva(false) {}

// Funcion para crear el campo de texto en pantallas para los comandos
bool Ecosistema::CampoTexto(Rectangle recCampo, Rectangle recBoton, char* buffer, int bufferSize, bool& activo)
{
    // Obtener mouse
    Vector2 mouse = GetMousePosition();
    bool hoverCampo = CheckCollisionPointRec(mouse, recCampo);
    bool clickCampo = hoverCampo && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    bool clickBoton = CheckCollisionPointRec(mouse, recBoton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    // detectar si se presiono
    if (clickCampo) {
        activo = true;
    }
    else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !hoverCampo && !clickBoton)
    {
        activo = false;
    }

	// DIbujar campo de texto y boton, incluye transicion de color
    DrawRectangleRec(recCampo, activo ? Fade(BLUE, 0.3f) : Fade(GRAY, 0.5f));
    DrawRectangleLinesEx(recCampo, 2, activo ? BLUE : DARKGRAY);

	// Si el campo de texto esta activo, capturar la entrada del teclado
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

	// Dibujar el texto en el campo de texto
    if (strlen(buffer) == 0 && !activo)
    {
        DrawText("Escribir comando...", recCampo.x + 5, recCampo.y + 10, 20, Fade(DARKGRAY, 0.5f));
    }
    else
    {
        DrawText(buffer, recCampo.x + 5, recCampo.y + 10, 20, BLACK);
    }

    // Crear el boton de ejecutar
    DrawRectangleRec(recBoton, GRAY);
    DrawRectangleLinesEx(recBoton, 2, DARKGRAY);
    int textWidth = MeasureText("Ejecutar", 20);
    DrawText("Ejecutar", recBoton.x + (recBoton.width - textWidth) / 2, recBoton.y + 10, 20, WHITE);

    return clickBoton;
}

// Funcion para crear boton en la interfaz de menu
bool Ecosistema::CrearBoton(Rectangle rec, const char* texto) 
{
    // Verificar mouse
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, rec);
    bool click = hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    // Dibujar boton
    DrawRectangleRec(rec, hover ? Fade(GREEN, 0.7f) : Fade(GRAY, 0.5f));
    DrawRectangleLinesEx(rec, 2, DARKGRAY);

    // botonn centrado
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
    Music musica = LoadMusicStream(MUSICA);

    // cargar recursos
    SetWindowIcon(logo);
    SetMusicVolume(musica, 0.5f);
    PlayMusicStream(musica);

    // Crear criaturas usando la fábrica
    FabricaAbstracta* fabrica = new FabricaConcreta();
    Criatura* herbivoro1 = fabrica->CrearHerbivoro(HERBIVORO, 100, 700, 100, 100, VEL_HERB);
    Criatura* herbivoro2 = fabrica->CrearHerbivoro(HERBIVORO, 600, 400, 100, 100, VEL_HERB);
    Criatura* herbivoro3 = fabrica->CrearHerbivoro(HERBIVORO, 300, 200, 100, 100, VEL_HERB);
    Criatura* herbivoro4 = fabrica->CrearHerbivoro(HERBIVORO, 800, 600, 100, 100, VEL_HERB);
    Criatura* herbivoro5 = fabrica->CrearHerbivoro(HERBIVORO, 450, 300, 100, 100, VEL_HERB);
    Criatura* herbivoro6 = fabrica->CrearHerbivoro(HERBIVORO, 150, 400, 100, 100, VEL_HERB);
    Criatura* carnivoro1 = fabrica->CrearCarnivoro(CARNIVORO, 400, 200, 100, 100, VEL_CARN);
    Criatura* carnivoro2 = fabrica->CrearCarnivoro(CARNIVORO, 240, 600, 100, 100, VEL_CARN);
    Criatura* omnivoro1 = fabrica->CrearOmnivoro(OMNIVORO, 800, 750, 100, 100, VEL_OMNI);
    Criatura* omnivoro2 = fabrica->CrearOmnivoro(OMNIVORO, 600, 700, 100, 100, VEL_OMNI);
    Criatura* omnivoro3 = fabrica->CrearOmnivoro(OMNIVORO, 400, 500, 100, 100, VEL_OMNI);
    Criatura* omnivoro4 = fabrica->CrearOmnivoro(OMNIVORO, 900, 300, 100, 100, VEL_OMNI);
    Criatura* omnivoro5 = fabrica->CrearOmnivoro(OMNIVORO, 500, 100, 100, 100, VEL_OMNI);
    Criatura* omnivoro6 = fabrica->CrearOmnivoro(OMNIVORO, 140, 560, 100, 100, VEL_OMNI);

    // Crear recursos base
    FabricaRecursoAbstracta* fabricaRecursos = new FabricaRecursoConcreta();
    Recurso* carne = fabricaRecursos->CrearCarne(CARNE, 300, 200);
    Recurso* carne2 = fabricaRecursos->CrearCarne(CARNE, 500, 400);
    Recurso* carne3 = fabricaRecursos->CrearCarne(CARNE, 150, 500);
    Recurso* planta = fabricaRecursos->CrearPlanta(PLANTA, 300, 500);
    Recurso* planta2 = fabricaRecursos->CrearPlanta(PLANTA, 700, 600);
    Recurso* planta3 = fabricaRecursos->CrearPlanta(PLANTA, 230, 140);
    Recurso* agua = fabricaRecursos->CrearAgua(AGUA, 600, 300);
    Recurso* agua2 = fabricaRecursos->CrearAgua(AGUA, 800, 500);
    Recurso* agua3 = fabricaRecursos->CrearAgua(AGUA, 200, 600);

    // Crear contenedor tipo criatura
    ContenedorCriaturas ContCriaturas;

    // Crear contenedor tipo recurso
    RecursosContenedor ContRecursos;

    // Asignar el contenedor de recursos al contenedor de criaturas
    ContCriaturas.SetContenedorRecursos(&ContRecursos);

    // Crear y configurar la estrategia de alimento para cada criatura
    EstrategiaAlimento* estrategiaAlimento = new EstrategiaAlimento(&ContRecursos, &ContCriaturas);
    EstrategiaReproducir* estrategiaReproducir = new EstrategiaReproducir(&ContRecursos, &ContCriaturas);

    // Agregar al Contenedor de criaturas
    ContCriaturas.AgregarCriatura(herbivoro1);
    ContCriaturas.AgregarCriatura(herbivoro2);
    ContCriaturas.AgregarCriatura(herbivoro3);
    ContCriaturas.AgregarCriatura(herbivoro4);
    ContCriaturas.AgregarCriatura(herbivoro5);
    ContCriaturas.AgregarCriatura(herbivoro6);
    ContCriaturas.AgregarCriatura(carnivoro1);
    ContCriaturas.AgregarCriatura(carnivoro2);
    ContCriaturas.AgregarCriatura(omnivoro1);
    ContCriaturas.AgregarCriatura(omnivoro2);
    ContCriaturas.AgregarCriatura(omnivoro3);
    ContCriaturas.AgregarCriatura(omnivoro4);
    ContCriaturas.AgregarCriatura(omnivoro5);
    ContCriaturas.AgregarCriatura(omnivoro6);

    // Crear y asignar estrategia de movimiento individual para cada criatura
    EstrategiaMovimiento* estrategiaMovimiento1 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento2 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento3 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento4 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento5 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento6 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento7 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento8 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento9 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento10 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento11 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento12 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento13 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento14 = new EstrategiaMovimiento();
    EstrategiaMovimiento* estrategiaMovimiento15 = new EstrategiaMovimiento();

    estrategiaMovimiento1->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento2->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento3->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento4->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento5->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento6->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento7->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento8->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento9->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento10->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento11->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento12->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento13->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento14->SetContenedorCriaturas(&ContCriaturas);
    estrategiaMovimiento15->SetContenedorCriaturas(&ContCriaturas);

    herbivoro1->SetEstrategiaMovimiento(estrategiaMovimiento1);
    herbivoro2->SetEstrategiaMovimiento(estrategiaMovimiento2);
    herbivoro3->SetEstrategiaMovimiento(estrategiaMovimiento3);
    herbivoro4->SetEstrategiaMovimiento(estrategiaMovimiento4);
    herbivoro5->SetEstrategiaMovimiento(estrategiaMovimiento5);
    herbivoro6->SetEstrategiaMovimiento(estrategiaMovimiento6);
    carnivoro1->SetEstrategiaMovimiento(estrategiaMovimiento7);
    carnivoro2->SetEstrategiaMovimiento(estrategiaMovimiento8);
    omnivoro1->SetEstrategiaMovimiento(estrategiaMovimiento10);
    omnivoro2->SetEstrategiaMovimiento(estrategiaMovimiento11);
    omnivoro3->SetEstrategiaMovimiento(estrategiaMovimiento12);
    omnivoro4->SetEstrategiaMovimiento(estrategiaMovimiento13);
    omnivoro5->SetEstrategiaMovimiento(estrategiaMovimiento14);
    omnivoro6->SetEstrategiaMovimiento(estrategiaMovimiento15);

    // Asignar estrategia de alimento a cada criatura
    herbivoro1->SetEstrategiaAlimento(estrategiaAlimento);
    herbivoro2->SetEstrategiaAlimento(estrategiaAlimento);
    herbivoro3->SetEstrategiaAlimento(estrategiaAlimento);
    herbivoro4->SetEstrategiaAlimento(estrategiaAlimento);
    herbivoro5->SetEstrategiaAlimento(estrategiaAlimento);
    herbivoro6->SetEstrategiaAlimento(estrategiaAlimento);
    carnivoro1->SetEstrategiaAlimento(estrategiaAlimento);
    carnivoro2->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro1->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro2->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro3->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro4->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro5->SetEstrategiaAlimento(estrategiaAlimento);
    omnivoro6->SetEstrategiaAlimento(estrategiaAlimento);

    // Asignar estrategia de reproducción a cada criatura
    herbivoro1->SetEstrategiaReproducir(estrategiaReproducir);
    herbivoro2->SetEstrategiaReproducir(estrategiaReproducir);
    herbivoro3->SetEstrategiaReproducir(estrategiaReproducir);
    herbivoro4->SetEstrategiaReproducir(estrategiaReproducir);
    herbivoro5->SetEstrategiaReproducir(estrategiaReproducir);
    herbivoro6->SetEstrategiaReproducir(estrategiaReproducir);
    carnivoro1->SetEstrategiaReproducir(estrategiaReproducir);
    carnivoro2->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro1->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro2->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro3->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro4->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro5->SetEstrategiaReproducir(estrategiaReproducir);
    omnivoro6->SetEstrategiaReproducir(estrategiaReproducir);

    // Crear y asignar estrategia de muerte individual para cada criatura
    herbivoro1->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    herbivoro2->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    herbivoro3->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    herbivoro4->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    herbivoro5->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    herbivoro6->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    carnivoro1->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    carnivoro2->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro1->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro2->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro3->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro4->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro5->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));
    omnivoro6->SetEstrategiaMorir(new EstrategiaMorir(&ContRecursos, &ContCriaturas));

    // Agregar al Contenedor de recursos
    ContRecursos.AgregarRecurso(agua);
    ContRecursos.AgregarRecurso(planta);
    ContRecursos.AgregarRecurso(carne);
    ContRecursos.AgregarRecurso(agua2);
    ContRecursos.AgregarRecurso(planta2);
    ContRecursos.AgregarRecurso(carne2);
    ContRecursos.AgregarRecurso(agua3);
    ContRecursos.AgregarRecurso(planta3);
    ContRecursos.AgregarRecurso(carne3);

    // Crear el observador de generación de recursos
    GeneradorRecursosObserver* generadorRecursos = new GeneradorRecursosObserver(fabricaRecursos, &ContRecursos);
    Entorno::GetInstancia()->AgregarObservador(generadorRecursos);

    // Obtener la instancia del Singleton de Entorno
    Entorno* entorno = Entorno::GetInstancia();

    // Iniciar thread de colisiones
    ejecutandoColisiones = true;
    threadColisiones = std::thread(ThreadColisiones, &ContCriaturas, &ContRecursos);

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

                // Cargar imagen al menu
                DrawTexture(fondo, 0, 0, WHITE);

                // Crear botones de inicio, comandos y salir
                float offsetY = altura * 0.05f;
                Rectangle botonSimular = { ancho / 2.0f - 100, 300 - offsetY, 200, 50 };
                Rectangle botonComandos = { ancho / 2.0f - 100, 370 - offsetY, 200, 50 };
                Rectangle botonSalir = { ancho / 2.0f - 100, 440 - offsetY, 200, 50 };

                // Verificar si se cambia a simulacion
                if (CrearBoton(botonSimular, "Iniciar Simulacion")) {
                    currentScreen = SIMULACION;
                    simulacionActiva = true;
                    EstrategiaMorir::SetSimulacionActiva(true);
                    // Reiniciar el tiempo de última comida de todas las criaturas
                    for (int i = 0; i < ContCriaturas.GetCantidadCriaturas(); i++) {
                        Criatura* criatura = ContCriaturas.GetCriatura(i);
                        if (criatura != nullptr) {
                            criatura->SetUltimoTiempoComida(GetTime());
                        }
                    }
                }

                // Verificar si cambia a comandos
                if (CrearBoton(botonComandos, "Comandos")) {
                    currentScreen = COMANDOS;
                }

                // Verificar si cambia a salir
                if (CrearBoton(botonSalir, "Salir")) {
                    currentScreen = SALIR;
                }
            } 
            break;

            case COMANDOS:
            {
                // Cargar imagen de fondo
                DrawTexture(fondo, 0, 0, WHITE);

                // Título
                DrawText("Comandos para el cambio de clima", ancho/2 - 250, 50, 30, BLACK);
                DrawText("(Probabilidad de generacion de recursos)", ancho/2 - 200, 90, 20, BLACK);

                // Comando lluvia
                DrawText("\"lluvia\"", 450, 150, 25, BLUE);
                DrawText("Agua: 40%", 450, 190, 20, BLACK);
                DrawText("Plantas: 40%", 440, 220, 20, BLACK);
                DrawText("Alimento: 20%", 440, 250, 20, BLACK);

                // Comando soleado
                DrawText("\"soleado\"", 450, 320, 25, ORANGE);
                DrawText("Agua: 20%", 450, 360, 20, BLACK);
                DrawText("Plantas: 40%", 440, 390, 20, BLACK);
                DrawText("Alimento: 40%", 440, 420, 20, BLACK);

                // Comando nieve
                DrawText("\"nieve\"", 450, 490, 25, SKYBLUE);
                DrawText("Agua: 20%", 450, 530, 20, WHITE);
                DrawText("Plantas: 20%", 440, 560, 20, WHITE);
                DrawText("Alimento: 60%", 440, 590, 20, WHITE);

                // Botón volver al menú
                Rectangle botonVolver = { ancho/2 - 100, altura - 100, 200, 50 };
                if (CrearBoton(botonVolver, "Volver al Menu")) {
                    currentScreen = MENU;
                }
            }
            break;
        
            case SIMULACION:
            {
                // Actualizar música según el clima
                entorno->Update();

                // Actualizar el generador de recursos
                generadorRecursos->Update(GetTime());

                // Cargar imagen de simulacion en la ventana
                ClearBackground(WHITE);
                DrawTexture(entorno->GetFondoActual(), 0, 0, WHITE);

                // Crear linea separadora del juego y de los comandos
                DrawLineEx(Vector2{ 0, 100 }, Vector2{ (float)ancho, 100 }, 3.0f, DARKGRAY);

                // Dibujar las criaturas en la pantalla
                ContCriaturas.DibujarCriaturas();
                
                // Actualizar las criaturas usando sus estrategias
                for (int i = 0; i < ContCriaturas.GetCantidadCriaturas(); i++) {
                    Criatura* criatura = ContCriaturas.GetCriatura(i);
                    if (criatura != nullptr) {
                        // Actualizar movimiento
                        EstrategiaMovimiento* estrategiaMovimiento = criatura->GetEstrategiaMovimiento();
                        if (estrategiaMovimiento != nullptr) {
                            estrategiaMovimiento->Mover(criatura);
                        }
                        // Actualizar alimento
                        EstrategiaAlimento* estrategiaAlimento = criatura->GetEstrategiaAlimento();
                        if (estrategiaAlimento != nullptr) {
                            estrategiaAlimento->Mover(criatura);
                        }
                        // Actualizar muerte
                        EstrategiaMorir* estrategiaMorir = criatura->GetEstrategiaMorir();
                        if (estrategiaMorir != nullptr) {
                            estrategiaMorir->Mover(criatura);
                        }
                        // Actualizar reproducción
                        EstrategiaReproducir* estrategiaReproducir = criatura->GetEstrategiaReproducir();
                        if (estrategiaReproducir != nullptr) {
                            estrategiaReproducir->Mover(criatura);
                        }
                    }
                }

                // Solo dibujar los recursos, la actualización se hace por el patrón Observer
                ContRecursos.DibujarRecursos();

                // Mostrar el clima actual
                DrawText(("Clima actual: " + entorno->GetClimaActual()).c_str(), 420, 63, 20, BLACK);

                // Boton regresar detiene y carga la musica de las ventanas
                Rectangle botonRegresar = { 10, 25, 200, 50 };
                if (CrearBoton(botonRegresar, "Terminar"))
                {
                    currentScreen = SALIR;
                    simulacionActiva = false;
                    EstrategiaMorir::SetSimulacionActiva(false);
                }

                if (IsKeyPressed(KEY_ESCAPE))
                {
                    currentScreen = SALIR;
                    simulacionActiva = false;
                    EstrategiaMorir::SetSimulacionActiva(false);
                }

                // Dibujar el campo de texto y boton de ejecutar en la parte arriba de simulacion
                Rectangle campoTexto = { (ancho - 300) / 2.0f, 20, 300, 40 };
                Rectangle botonEjecutar = { campoTexto.x + campoTexto.width + 10, 20, 120, 40 };

                if (CampoTexto(campoTexto, botonEjecutar, comando, 64, textFieldActivo)) {
                    // Procesar comandos de clima
                    std::string comandoStr(comando);
                    if (comandoStr == "lluvia" || comandoStr == "nieve" || comandoStr == "soleado") {
                        entorno->CambiarClima(comandoStr);
                        resultadoComando = "Clima cambiado a: " + comandoStr;
                    }
                    comando[0] = '\0';
                }
            } 
            break;
        }
        // Terminar de dibujar las ventanas
        EndDrawing();
    }

    // Detener thread de colisiones
    ejecutandoColisiones = false;
    if (threadColisiones.joinable()) {
        threadColisiones.join();
    }

    // Limpiar recursos
    StopMusicStream(musica);
    UnloadMusicStream(musica);
    UnloadTexture(fondo);
    UnloadImage(logo);
  
    delete fabrica;
    delete generadorRecursos;

    // Cerrar archivos
    CloseAudioDevice();
    CloseWindow();
}

// Destructor
Ecosistema::~Ecosistema() {
    ejecutandoColisiones = false;
    if (threadColisiones.joinable()) {
        threadColisiones.join();
    }

    CloseAudioDevice();
    CloseWindow();
}