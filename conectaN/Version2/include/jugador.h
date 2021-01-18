#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include"tablero.h"

class Jugador{
	private:
		char *nombre;
		int tamanio_nombre;
		int turno;
		int ganadas;
		int perdidas;
		int empatadas;
		int puntuacion;
	public:
		Jugador();

		Jugador (char vector[],int tam=0, int turno=1, int puntos=0, int ganado=0, int perdido=0, int empates=0);
		
		Jugador (const Jugador &jugador);

		~Jugador();

		Jugador& operator=(const Jugador &jugador);
		
		char* GetNombre();

		int GetTamanio() const;

		int GetTurno() const;

		int GetGanadas() const;

		int GetPerdidas() const;

		int GetEmpatadas() const;

		int GetPuntuacion() const;

		void AumentaTurno();

		void AumentaGanadas();

		void AumentaPerdidas();

		void AumentaEmpates();

		void InicializarTurno(int turn=1);
		
		void Puntuacion (Tablero& tablero);
		
		char JugadorAutomatico(const char tope);
	
		bool escogeColumna (Tablero& tablero);
};

std::istream& operator >> (std::istream &is, Jugador& j);

std::ostream& operator << (std::ostream &os, Jugador& j);

#endif
