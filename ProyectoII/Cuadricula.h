#pragma once
#include <raylib.h>
#include <iostream>

class Cuadricula
{
public:
    Cuadricula();
    void Inicializar();
    void PintarMatricula() const;
    void Dibujar();
    int matriz[30][30];
private:
    int rows;
    int cols;
    int cellSize;
    Color Colors[8];
    Color getCellColor(int value) const;
};  