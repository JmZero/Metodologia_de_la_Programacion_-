#include<iostream>
#include"matriz.h"
#include"tablero.h"

using namespace std;

Tablero::Tablero(): tablero(){
	fichas_objetivo = 1;
	turno = 1;
	fichas_turno = 1;
}

Tablero::Tablero(int fils, int cols, int fichas, int f_turn, int f_intro, int turn): tablero(fils, cols){
	fichas_objetivo = fichas;
	fichas_turno = f_turn;
	fichas_introducidas = f_intro;
	turno = turn;

}

void Tablero::SetTablero(Matriz m){
	tablero = m;
}	
		
int Tablero::Filas() const{
	return tablero.Filas();
}
		
int Tablero::Columnas() const{
	return tablero.Columnas();
}
		
int Tablero::FichasAlineadas() const{
	return fichas_objetivo;
}

int Tablero::GetValor(int fil, int col) const{
	return tablero.GetValor(fil, col);
}

int Tablero::TurnoActual() const{
	return turno;
}

int Tablero::FichasTurno()const{
	return fichas_turno;
}

int Tablero::FichasRestantes() const{
	return fichas_introducidas;
}

Matriz Tablero::GetTablero(){
	return tablero;
}

void Tablero::InicializaIntroducidas(){
	fichas_introducidas=0;
}

void Tablero::AumentaIntroducidas(){
	fichas_introducidas++;
}

int Tablero::Puntuacion(){
	int p_tablero = Filas()*Columnas();
	int p_fichas = p_tablero/2 - turno/2;
	int p_longitud = FichasAlineadas();
			
	return p_tablero + p_fichas + p_longitud;
}

void Tablero::AumentaTurno(){
	turno++;
}
	
int Tablero::Ganador(){
	int jugador;
	int contador = 0;
	int pos_der, pos_izq, f_actual, c_actual;
			
	for (int i = Filas()-1; i >= 0 && contador < fichas_objetivo; i--){
		for (int j = 0; j < Columnas() && contador < fichas_objetivo; j++){
			if (GetValor(i,j) == 1)
				jugador = 1;
			else if (GetValor(i,j) == 2)
				jugador = 2;
			else
				jugador = 0;
								
			for (int k = i; k >= i-1 && contador < fichas_objetivo && jugador != 0 && k >=0; k--){
				for (int l = j-1; l <= j+1 && contador < fichas_objetivo && l < Columnas(); l++){
					contador = 1;
					if ((k == i-1 || l == j+1) && l >= 0){
						pos_der=k-i;
						pos_izq=l-j;
						f_actual=k;
						c_actual=l;
						while (contador != fichas_objetivo && f_actual >= 0 && GetValor(f_actual, c_actual) == jugador && c_actual < Columnas()){
							f_actual+=pos_der;
							c_actual+=pos_izq;
							contador++;
						}
					}
				}
			}
		}
	}
			
	if (contador == fichas_objetivo)
		return jugador;
	else 
		return 0;
}

bool Tablero::Finalizada(){
	bool final = true;
	if (Ganador() == 1 || Ganador() == 2)
		final = true;
	else{ 
		for (int i=0; i < Columnas() && final; i++){
			if (GetValor(0,i) != 0)
				final = true;
			else{
				final = false;
			}
		}
	}
	return final;
}
									
bool Tablero::Inserta(char caracter){
	int col = caracter - 'a';
	int fila;
			
	for (fila = Filas()-1; fila >= 0 && GetValor(fila, col) != 0; fila--);
			
	if (fila < 0 || 'a' > caracter || caracter > ('a'+ Columnas()-1))
		return false;
	else{
		if(turno%2 != 0)
			tablero.SetValor(fila, col, 1);
		else
			tablero.SetValor(fila, col, 2);

		return true;
	}
}
		
void Tablero::VaciarTablero(){
	if (TurnoActual()%2 == 0)
		turno = 2;
	else 
		turno = 1;

	for (int i=0; i < Filas(); i++){
		for (int j=0; j < Columnas(); j++){
			tablero.SetValor(i, j, 0);
		}
	}
}
				
void Tablero::Imprimir(ostream& os){
	char letra;
	char ficha;
	for (int i=0; i < Columnas(); i++){
		letra = 'a' + i;
		os << " " << letra;
	}
	os << endl;
			
	for (int j=0; j < Filas(); j++){
		for (int k=0; k < Columnas(); k++){
			if (GetValor(j,k) == 1)
				ficha = 'x';
			else if (GetValor(j,k) == 2)
				ficha = 'o';
			else
				ficha = ' ';
			os << "|" << ficha;
		}
		os << "|" << endl;
	}
			
	for (int k=0; k < Columnas(); k++){
		os << "==";
	}
	os << "=" << endl;
}

istream& operator >> (istream& is, Tablero& t){
	Matriz m;	
	int fichas, turno, f_turno, f_intro;

	is >> m;

	is.ignore();

	is >> fichas >> turno >> f_turno >> f_intro;
	
	Tablero nuevo(m.Filas(), m.Columnas(), fichas, f_turno, f_intro, turno);
	nuevo.SetTablero(m);
	
	t=nuevo;

	return is;
}
				
ostream& operator << (ostream& os, Tablero& t){
	Matriz m=t.GetTablero();
	os << m;
	os << endl;
	
	os << t.FichasAlineadas() << " " << t.TurnoActual() << " " << t.FichasTurno() << " " << t.FichasRestantes() << endl;
	
	return os;
}
