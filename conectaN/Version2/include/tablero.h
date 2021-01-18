#ifndef _TABLERO_H_
#define _TABLERO_H_

#include"matriz.h"
#include<iostream>
using namespace std;

class Tablero{
	private:
		Matriz tablero;
		int fichas_objetivo;
		int turno;
		int fichas_turno;
		int fichas_introducidas;
	public:
		Tablero();

		Tablero(int fils, int cols, int fichas, int f_turn, int f_intro=0, int turn=1);

		void SetTablero(Matriz m);
		
		int Filas() const;
		
		int Columnas() const;
		
		int FichasAlineadas() const;

		int GetValor(int fil, int col) const;

		int TurnoActual() const;

		int FichasTurno() const;
		
		int FichasRestantes() const;
	
		Matriz GetTablero();

		void InicializaIntroducidas();

		void AumentaIntroducidas();
		
		int Puntuacion();

		void AumentaTurno();
		
		int Ganador();

		bool Finalizada();
									
		bool Inserta(char caracter);
		
		void VaciarTablero();
				
		void Imprimir(ostream& os=cout);
};

std::istream& operator >> (std::istream &is, Tablero& t);

std::ostream& operator << (std::ostream &os, Tablero& t);

#endif
