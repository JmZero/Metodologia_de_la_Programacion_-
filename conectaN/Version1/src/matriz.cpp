#include"matriz.h"

using namespace std;

Matriz::Matriz(){
	filas = columnas = 0;
}

Matriz::Matriz(int fil, int col){
	assert (fil >= 4 && col >= 4 && fil <= 20 && col <= 20);
	SetFilas(fil);
	SetColumnas(col);
}
		
int Matriz::Filas() const {
	return filas;
}
		
int Matriz::Columnas() const {
	return columnas;
}
		
int Matriz::GetValor (int f, int c) const {
	return datos[f][c];
}
		
void Matriz::SetFilas(int fils){
	filas = fils;
}
		
void Matriz::SetColumnas(int cols){
	columnas = cols;
}
		
void Matriz::SetValor (int f, int c, int valor){
	datos[f][c] = valor;
}
