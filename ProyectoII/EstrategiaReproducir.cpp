#include "EstrategiaReproducir.h"
#include "raylib.h"
#include "FabricaConcreta.h"

EstrategiaReproducir::EstrategiaReproducir(RecursosContenedor* _contRecursos, ContenedorCriaturas* _contCriaturas) 
    : contRecursos(_contRecursos), contCriaturas(_contCriaturas), vecesComido(0), tiempoInicio(0), tiempoLimite(10.0f) {
}

void EstrategiaReproducir::Mover(Criatura* criatura) {
    float tiempoActual = GetTime();
    
    // Si es la primera vez que come, inicializar el tiempo
    if (vecesComido == 0) {
        tiempoInicio = tiempoActual;
    
    }
    
    // Verificar si ha pasado el tiempo límite
    if (tiempoActual - tiempoInicio > tiempoLimite) {

        ResetearContador();
        return;
    }
    
    // Verificar si la criatura ha comido
    if (criatura->GetUltimoTiempoComida() > tiempoInicio) {
        vecesComido++;
        
        // Detecta si ha comido 3 veces para reproducirse
        if (vecesComido >= 3) {
            // Crear una nueva criatura del mismo tipo
            FabricaAbstracta* fabrica = new FabricaConcreta();
            Criatura* nuevaCriatura = nullptr;
            
            if (dynamic_cast<Herbivoro*>(criatura)) {

                nuevaCriatura = fabrica->CrearHerbivoro(HERBIVORO_IMG, 
                    criatura->GetX() + 50, criatura->GetY() + 50, 
                    100, 100, VEL_HERBI);
            }
            else if (dynamic_cast<Carnivoro*>(criatura)) {
               
                nuevaCriatura = fabrica->CrearCarnivoro(CARNIVORO_IMG, 
                    criatura->GetX() + 50, criatura->GetY() + 50, 
                    100, 100, VEL_CARNI);
            }
            else if (dynamic_cast<Omnivoro*>(criatura)) {
   
                nuevaCriatura = fabrica->CrearOmnivoro(OMNIVORO_IMG, 
                    criatura->GetX() + 50, criatura->GetY() + 50, 
                    100, 100, VEL_OMNIV);
            }
            
            // Si se creó una nueva criatura, agregarla al contenedor
            if (nuevaCriatura != nullptr) {
 
                contCriaturas->AgregarCriatura(nuevaCriatura);
            } 
            
            delete fabrica;
            ResetearContador();
        }
    }
}

void EstrategiaReproducir::ResetearContador() {
  
    vecesComido = 0;
    tiempoInicio = 0;
} 