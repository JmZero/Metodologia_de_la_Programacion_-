#include<iostream>
#include"matriz.h"
#include"tablero.h"
#include"jugador.h"

using namespace std;

int TopeFichas(int fils, int cols){
	if (fils > cols)
		return cols -1;
	else
		return fils -1;
}

int main(){
	int filas, columnas, fichas;
	char nombre1[50], nombre2[50], revancha;
	
	cout << "Introduzca filas: ";
	cin >> filas;
	while (filas <= 3 || filas > 20){
		cout << "El numero de filas debe ser de 4 a 20: ";
		cin >> filas;
	}
	 
	cout << "Introduzca columnas: ";
	cin >> columnas;
	while (columnas <= 3 || columnas > 20){
	 	cout << "El numero de columnas debe ser de 4 a 20: ";
		cin >> columnas;
	}
	 
	cout << "Introduzca fichas a alinear (3-" << TopeFichas(filas, columnas) << "): ";
	cin >> fichas;
	while (fichas < 3 || fichas > TopeFichas(filas,columnas)){
	 	cout << "El numero de fichas debe estar entre 3 y " << TopeFichas(filas, columnas) << ": ";
	 	cin >> fichas;
	}
	 
	cout << "Introduzca nombre del primer jugador: ";
	cin.ignore();
	cin.getline(nombre1, '\n');
	cout << "Introduzca nombre del segundo jugador: ";
	cin.getline(nombre2, '\n');
	
	Jugador jugador1(nombre1), jugador2(nombre2);
	Tablero tablero(filas, columnas, fichas);
	do{
		tablero.VaciarTablero();
		jugador1.InicializarTurno();
		jugador2.InicializarTurno();
		do{	
			if (tablero.TurnoActual()%2 != 0){
				jugador1.escogeColumna(tablero);
			}
			else{
				jugador2.escogeColumna(tablero);
			}
		}while(!tablero.Finalizada());
		
		tablero.Imprimir();
		
		cout << "Partida finalizada. ";
		if (tablero.Ganador() == 1){
			jugador1.Puntuacion(tablero);
			jugador1.AumentaGanadas();
			jugador2.AumentaPerdidas();
			cout << "Ganador: jugador 1" << endl;
		}
		else if (tablero.Ganador() == 2){
			jugador2.Puntuacion(tablero);
			jugador2.AumentaGanadas();
			jugador1.AumentaPerdidas();
			cout << "Ganador: jugador 2" << endl;
		}
		else{
			jugador1.AumentaEmpates();
			jugador2.AumentaEmpates();
			cout << "Empate." << endl;
		}
		
		cout << "Resultados tras esta partida:" << endl;
		cout << jugador1.GetNombre() << ": " << jugador1.GetGanadas() << " ganadas que acumulan " << jugador1.GetPuntuacion() << " puntos" << endl;
		cout << jugador2.GetNombre() << ": " << jugador2.GetGanadas() << " ganadas que acumulan " << jugador2.GetPuntuacion() << " puntos" << endl;
		cout << "¿Jugar de nuevo(S/N)?: ";
		cin >> revancha;
		revancha = toupper(revancha);
	}while(revancha == 'S');
	
	cout << "Resultados finales:" << endl;
	cout << jugador1.GetNombre() << ": " << jugador1.GetGanadas() << " ganadas que acumulan " << jugador1.GetPuntuacion() << " puntos" << endl;
	cout << jugador2.GetNombre() << ": " << jugador2.GetGanadas() << " ganadas que acumulan " << jugador2.GetPuntuacion() << " puntos" << endl;
	cout << jugador1.GetEmpatadas() << " empatadas" << endl;
}
