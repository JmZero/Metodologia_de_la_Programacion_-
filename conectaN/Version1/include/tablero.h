#ifndef _TABLERO_H_
#define _TABLERO_H_

#include"matriz.h"

class Tablero{
	private:
		Matriz tablero;
		int fichas_objetivo;
		int turno;
	public:
		Tablero(int fils, int cols, int fichas);
		
		int Filas() const;
		
		int Columnas() const;
		
		int FichasAlineadas() const;
		
		int GetValor(int fil, int col) const;

		int TurnoActual() const;
		
		bool Finalizada();
		
		int Ganador();
		
		int Puntuacion();
									
		bool Inserta(char caracter);
		
		void VaciarTablero();
				
		void Imprimir();
};

#endif
