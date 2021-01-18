#include"matriz.h"
#include<iostream>

using namespace std;

Matriz::Matriz(){
	filas = columnas = 0;
	datos=new int[0];
}

Matriz::Matriz(int fil, int col){
	assert (fil >= 4 && col >= 4);
	datos=new int[fil*col];

	SetFilas(fil);
	SetColumnas(col);
}

Matriz::Matriz(const Matriz &m){
	datos=new int[m.Filas()*m.Columnas()];

	for (int i=0; i<m.Filas(); i++)
		for (int j=0; j<m.Columnas(); j++)
			datos[j+i*m.Columnas()]=m.datos[j+i*m.Columnas()];

	SetFilas(m.Filas());
	SetColumnas(m.Columnas());
}

Matriz::~Matriz(){	
	delete[] datos;
}

Matriz& Matriz::operator=(const Matriz &m){	
	delete[] this->datos;

	this->filas=m.Filas();
	this->columnas=m.Columnas();
	this->datos=new int[this->filas * this->columnas];

	for (int i=0; i<this->filas; i++)
		for (int j=0; j<this->columnas; j++)
			this->datos[j+i*this->columnas]=m.datos[j+i*m.Columnas()];

	return *this;
}
		
int Matriz::Filas() const {
	return filas;
}
		
int Matriz::Columnas() const {
	return columnas;
}

int Matriz::GetValor(int f, int c) const {
	return datos[c+f*Columnas()];
}
		
void Matriz::SetFilas(int fils){
	filas = fils;
}
		
void Matriz::SetColumnas(int cols){
	columnas = cols;
}
		
void Matriz::SetValor(int f, int c, int valor){
	datos[c+f*Columnas()] = valor;
}

istream& operator >> (istream& is, Matriz& m){
	int filas, columnas, dato;
	is >> filas >> columnas;

	Matriz nueva(filas, columnas);

	for (int i=0; i < nueva.Filas(); i++)
		for (int j=0; j < nueva.Columnas(); j++){
				is >> dato;
				nueva.SetValor(i, j, dato);
		}
	
	m = nueva;
	
	return is;
}
				
ostream& operator << (ostream& os, Matriz& m){
	os << m.Filas() << " " << m.Columnas() << endl;
	for (int i=0; i < m.Filas(); i++)
		for (int j=0; j < m.Columnas(); j++)
			os << m.GetValor(i, j) << " ";

	return os;
}
