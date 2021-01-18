#include<iostream>
#include<cstdlib>
#include"jugador.h"

using namespace std;

Jugador::Jugador(){
	nombre = new char[0];
	InicializarTurno(1);
	puntuacion = 0;
	ganadas = 0;
	perdidas = 0;
	empatadas = 0;
	tamanio_nombre = 0;
}

Jugador::Jugador (char vector[], int tam, int turno, int puntos, int ganado, int perdido, int empates){
	if (tam == 0)	
		for (tam=0; vector[tam] != '\0'; tam++);

	nombre = new char[tam];
	for (int i=0; i < tam; i++)
		nombre[i] = vector[i];
	
	InicializarTurno(turno);
	puntuacion = puntos;
	ganadas = ganado;
	perdidas = perdido;
	empatadas = empates;
	tamanio_nombre = tam;
}

Jugador::Jugador (const Jugador &jugador){
	nombre = new char [jugador.tamanio_nombre];	
	for (int i=0; i < jugador.tamanio_nombre; i++)
		nombre[i] = jugador.nombre[i];
	
	turno = jugador.turno;
	puntuacion = jugador.puntuacion;
	ganadas = jugador.ganadas;
	perdidas = jugador.perdidas;
	empatadas = jugador.empatadas;
	tamanio_nombre = jugador.tamanio_nombre;
}

Jugador::~Jugador(){
	delete[] nombre;
}

Jugador& Jugador::operator=(const Jugador &jugador){
	delete[] this->nombre;

	this->turno = jugador.turno;
	this->puntuacion = jugador.puntuacion;
	this->ganadas = jugador.ganadas;
	this->perdidas = jugador.perdidas;
	this->empatadas = jugador.empatadas;
	this->tamanio_nombre = jugador.tamanio_nombre;
	this->nombre = new char [tamanio_nombre];

	for (int i=0; i < tamanio_nombre; i++)
		this->nombre[i] = jugador.nombre[i];
	
	return *this;
}
		
char* Jugador::GetNombre(){
	char* n = &nombre[0];
	return n;
}

int Jugador::GetTamanio() const{
	return tamanio_nombre;
}

int Jugador::GetTurno() const{
	return turno;
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

void Jugador::AumentaTurno(){
	turno++;
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

void Jugador::InicializarTurno(int turn){
	turno = turn;
}
		
void Jugador::Puntuacion (Tablero& tablero){
	puntuacion+=tablero.Puntuacion();
}

char Jugador::JugadorAutomatico(const char tope){
	int limite = tope - 'a' + 1;
	int valor = rand() % limite;
	char pos = 'a' + valor;

	return pos;
}	
		
bool Jugador::escogeColumna (Tablero& tablero){
	const char caracter = 'a'+tablero.Columnas()-1;
	char columna;
	bool bien_insertado;

	do{	
		tablero.Imprimir();
			
		if (tablero.TurnoActual()% 2 == 0)
			cout << "\nTurno: jugador 2: (o)" << endl;
		else
			cout << "\nTurno: jugador 1: (x)" << endl;
			
		if (nombre[0] != '@'){
			cout << nombre << ", escoja una columna (letra a-" << caracter << "): ";
			cin >> columna;
		}
		else 
			columna = JugadorAutomatico(caracter);

		if((bien_insertado=tablero.Inserta(columna)))
			tablero.AumentaIntroducidas();

	}while(bien_insertado && tablero.FichasRestantes() < tablero.FichasTurno() && !tablero.Finalizada());
		
	if (bien_insertado && (tablero.FichasRestantes() == tablero.FichasTurno() || tablero.Finalizada())){
		tablero.AumentaTurno();
		tablero.InicializaIntroducidas();
		return true;
	}
	else 
		return false;
}

std::istream& operator >> (std::istream &is, Jugador& j){
	char* nombre = new char[0];
	int tamanio, turno, puntuacion, ganado, perdido, empates;

	if (is.peek() == '#')
		is.ignore();

	
	is >> nombre >> tamanio >> turno >> puntuacion >> ganado >> perdido >> empates;
	
	Jugador nuevo(nombre, tamanio, turno, puntuacion, ganado, perdido, empates);
	j=nuevo;
	
	return is;
}

std::ostream& operator << (std::ostream &os, Jugador& j){
	os << "#" << j.GetNombre() << " " << j.GetTamanio() << " " << j.GetTurno() << " " << j.GetPuntuacion() << " " << j.GetGanadas() << " " << j.GetPerdidas() << " " << j.GetEmpatadas();

	return os;
}
