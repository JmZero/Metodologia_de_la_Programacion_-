#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include<assert.h>
#include<iostream>

class Matriz{
	private:
		int *datos;
		int filas, columnas;
	public:
		Matriz();

		Matriz(int fil, int col);
		
		Matriz(const Matriz &m);
		
		~Matriz();

		Matriz& operator=(const Matriz &m);

		int Filas() const;
		
		int Columnas() const;

		int GetValor (int f, int c) const;
		
		void SetFilas(int fils);
		
		void SetColumnas(int cols);
		
		void SetValor (int f, int c, int valor);
};

std::istream& operator >> (std::istream &is, Matriz& m);

std::ostream& operator << (std::ostream &os, Matriz& m);
#endif
