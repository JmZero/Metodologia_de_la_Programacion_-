#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include"tablero.h"

class Jugador{
	private:
		char nombre[50];
		int turno;
		int ganadas;
		int perdidas;
		int empatadas;
		int puntuacion;
	public:
		Jugador (char vector[]);
		
		char* GetNombre();

		int GetGanadas() const;

		int GetPerdidas() const;

		int GetEmpatadas() const;

		int GetPuntuacion() const;

		void AumentaGanadas();

		void AumentaPerdidas();

		void AumentaEmpates();

		void InicializarTurno();
		
		void Puntuacion (Tablero tablero);
		
		void escogeColumna (Tablero& tablero);
};

#endif
