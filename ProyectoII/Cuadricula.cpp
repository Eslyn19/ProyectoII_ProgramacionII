#include "Cuadricula.h"

Cuadricula::Cuadricula() 
{
	rows = 10;
	cols = 10;
	cellSize = 50;

	Colors[0] = BLACK;
	Colors[1] = WHITE;
	Colors[2] = RED;
	Colors[3] = GREEN;
	Colors[4] = BLUE;
	Colors[5] = YELLOW;
	Colors[6] = ORANGE;
	Colors[7] = PURPLE;
	
	Inicializar();
}

void Cuadricula::Inicializar()
{ 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matriz[i][j] = 0;
		}
	}
}

void Cuadricula::PintarMatricula() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matriz[i][j] << " ";
		}
		std::cout << std::endl; 
	}
}

Color Cuadricula::getCellColor(int value) const
{
	if (value >= 0 && value < 8)
		return Colors[value];
	return GRAY;
}

void Cuadricula::Dibujar()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int cellValue = matriz[i][j];
			DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, getCellColor(cellValue));
		}
	}
}