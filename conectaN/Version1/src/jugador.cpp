#include<iostream>
#include"jugador.h"

using namespace std;

Jugador::Jugador (char vector[]){
	int i;
	for (i=0; vector[i] != '\0'; i++)
		nombre[i] = vector[i];
	nombre[i]='\0';
	InicializarTurno();
	puntuacion = 0;
	ganadas = 0;
	perdidas = 0;
	empatadas = 0;
}
		
char* Jugador::GetNombre(){
	char* n = &nombre[0];
	return n;
}

int Jugador::GetGanadas() const{
	return ganadas;
}

int Jugador::GetPerdidas() const{
	return perdidas;
}

int Jugador::GetEmpatadas() const{
	return empatadas;
}
		
int Jugador::GetPuntuacion() const{
	return puntuacion;
}

void Jugador::AumentaGanadas(){
	ganadas++;
}

void Jugador::AumentaPerdidas(){
	perdidas++;
}

void Jugador::AumentaEmpates(){
	empatadas++;
}

void Jugador::InicializarTurno(){
	turno = 1;
}
		
void Jugador::Puntuacion (Tablero tablero){
	puntuacion+=tablero.Puntuacion();
}
		
void Jugador::escogeColumna (Tablero& tablero){
	char caracter, columna;
	tablero.Imprimir();
			
	caracter = 'a'+tablero.Columnas()-1;
			
	if (tablero.TurnoActual()% 2 == 0)
		cout << "\nTurno: jugador 2: (o)";
	else
		cout << "\nTurno: jugador 1: (x)";
			
	do{
		cout << "\n" << nombre << ", escoja una columna (letra a-" << caracter << "): ";
		cin >> columna;
	}while(!tablero.Inserta(columna));
}
