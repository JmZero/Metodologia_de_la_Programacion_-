/////////////////////////////////
//  Jesús Miguel Jaldo Ruiz    //					
//  Alberto Hitos García       //						
//  Curso: 1º  Grupo: A        //
//                             //
//  "ConectaN"                 //
//                             //
/////////////////////////////////

#include<iostream>
#include<fstream>
#include<string.h>
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

int TopeTurnos(int fichas){
	return fichas-2;
}

bool Cargar(char* archivo, Jugador &j1, Jugador &j2, Tablero &t){
	ifstream f(archivo, ios::in);
	if (f){
		char dato;
		const char* cabecera = "#MP-CONECTAN-1.0";
	
		while (f.peek() != '#')
			f.ignore();
		
		for (unsigned int i=0; i < strlen(cabecera); i++){
			f >> dato;
			if (dato != cabecera[i])
				return false;
		}
		f.ignore();
		f >> j1;
		f.ignore();
		f >> j2;
		f.ignore();
		f >> t;

		f.close();
	}
	
	return f.good();
}

bool Salvar(char* archivo, Jugador j1, Jugador j2, Tablero t){
	ofstream f(archivo);
	if (f){
		f << "#MP-CONECTAN-1.0" << endl;
		f << j1 << endl;
		f << j2 << endl;
		f << t;

		f.close();
	}
	
	return f.good();
}


int main(int argc, char* argv[]){
	if (argc == 1){
		int filas, columnas, fichas, fichas_turno;
		char nombre1[50], nombre2[50], revancha;

		cout << "Introduzca filas: ";
		cin >> filas;
		while (filas <= 3){
			cout << "El numero de filas debe ser 4 o superior: ";
			cin >> filas;
		}
	 
		cout << "Introduzca columnas: ";
		cin >> columnas;
		while (columnas <= 3){
	 		cout << "El numero de columnas debe ser 4 o superior: ";
			cin >> columnas;
		}
	 
		cout << "Introduzca fichas a alinear (3-" << TopeFichas(filas, columnas) << "): ";
		cin >> fichas;
		while (fichas < 3 || fichas > TopeFichas(filas,columnas)){
	 		cout << "El numero de fichas debe estar entre 3 y " << TopeFichas(filas, columnas) << ": ";
	 		cin >> fichas;
		}

		cout << "Introduzca fichas por turno (1-" << TopeTurnos(fichas) << "): ";
		cin >> fichas_turno;
		while (fichas_turno < 1 || fichas_turno > TopeTurnos(fichas)){
	 		cout << "El numero de fichas debe estar entre 1 y " << TopeTurnos(fichas) << ": ";
	 		cin >> fichas_turno;
		}
	 
		cout << "Introduzca nombre del primer jugador: ";
		cin.ignore();
		cin.getline(nombre1, 50);

		cout << "Introduzca nombre del segundo jugador: ";
		cin.getline(nombre2, 50);
	
		Jugador jugador1(nombre1), jugador2(nombre2);
		Tablero tablero(filas, columnas, fichas, fichas_turno);

		do{
			do{	
				if (tablero.TurnoActual()%2 != 0){
					if(!jugador1.escogeColumna(tablero)){
						char decision, fichero[50];
						cout << "Error en la seleccion de la columna. Quiere guardar la partida?";
						cin >> decision;
						if (decision == 's'){
							cout << "Introduzca nombre de archivo: ";
							cin.ignore();
							cin.getline(fichero, 50);
							Salvar(fichero, jugador1, jugador2, tablero);
						}
					}
					else{
						jugador1.AumentaTurno();
					}
					
				}
				else{
					if(!jugador2.escogeColumna(tablero)){
						char decision, fichero[50];
						cout << "Error en la seleccion de la columna. Quiere guardar la partida?";
						cin >> decision;
						if (decision == 's'){
							cout << "Introduzca nombre de archivo: ";
							cin.ignore();
							cin.getline(fichero, 50);
							Salvar(fichero, jugador1, jugador2, tablero);
						}
					}
					else{
						jugador2.AumentaTurno();
					}
					
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
			if (revancha == 'S'){
				tablero.VaciarTablero();
				jugador1.InicializarTurno();
				jugador2.InicializarTurno();
			}
		}while(revancha == 'S');
	
		cout << "Resultados finales:" << endl;
		cout << jugador1.GetNombre() << ": " << jugador1.GetGanadas() << " ganadas que acumulan " << jugador1.GetPuntuacion() << " puntos" << endl;
		cout << jugador2.GetNombre() << ": " << jugador2.GetGanadas() << " ganadas que acumulan " << jugador2.GetPuntuacion() << " puntos" << endl;
		cout << jugador1.GetEmpatadas() << " empatadas" << endl;
	}
	else{
		char revancha;
		Jugador jugador1, jugador2;
		Tablero tablero;
		
		if(Cargar(argv[1], jugador1, jugador2, tablero)){
			cout << "Partida cargada." << endl;
		
			do{
				do{	
					if (tablero.TurnoActual()%2 != 0){
						if(!jugador1.escogeColumna(tablero)){
							char decision, fichero[50];
							cout << "Error en la seleccion de la columna. Quiere guardar la partida?";
							cin >> decision;
							if (decision == 's'){
								cout << "Introduzca nombre de archivo: ";
								cin.ignore();
								cin.getline(fichero, 50);
								Salvar(fichero, jugador1, jugador2, tablero);
							}
						}
						else{
							jugador1.AumentaTurno();
						}
					}
					else{
						if(!jugador2.escogeColumna(tablero)){
							char decision, fichero[50];
							cout << "Error en la seleccion de la columna. Quiere guardar la partida?";
							cin >> decision;
							if (decision == 's'){
								cout << "Introduzca nombre de archivo: ";
								cin.ignore();
								cin.getline(fichero, 50);
								Salvar(fichero, jugador1, jugador2, tablero);
							}
						}
						else{
							jugador2.AumentaTurno();
						}
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
				if (revancha == 'S'){
					tablero.VaciarTablero();
					jugador1.InicializarTurno();
					jugador2.InicializarTurno();
				}
			}while(revancha == 'S');
	
			cout << "Resultados finales:" << endl;
			cout << jugador1.GetNombre() << ": " << jugador1.GetGanadas() << " ganadas que acumulan " << jugador1.GetPuntuacion() << " puntos" << endl;
			cout << jugador2.GetNombre() << ": " << jugador2.GetGanadas() << " ganadas que acumulan " << jugador2.GetPuntuacion() << " puntos" << endl;
			cout << jugador1.GetEmpatadas() << " empatadas" << endl;
		}
		else
			cout << "No se ha cargado la partida." << endl;
	}
}
