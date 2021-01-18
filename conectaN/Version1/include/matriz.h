#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <assert.h>

class Matriz{
	private:
		int datos[20][20];
		int filas, columnas;
	public:
		Matriz();

		Matriz(int fil, int col);
		
		int Filas() const;
		
		int Columnas() const;

		int GetValor (int f, int c) const;
		
		void SetFilas(int fils);
		
		void SetColumnas(int cols);
		
		void SetValor (int f, int c, int valor);
};

#endif
