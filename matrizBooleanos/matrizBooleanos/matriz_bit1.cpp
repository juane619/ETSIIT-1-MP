#include "matriz_bit1.h"

bool Inicializar(MatrizBit& m, int fils, int cols){

	if(fils <= 10 && cols <= 10){
		m.filas = fils;
		m.columnas = cols;
		for(int i=0; i<fils; i++)
			for(int j=0; j<cols; j++)
				m.matriz[i][j]= 0;
		return true;
	}
	else
		return false;
}

int Filas (const MatrizBit& m){
	return m.filas;
}


int Columnas( const MatrizBit& m){
	return m.columnas;
}


bool Get(const MatrizBit& m, int f, int c){
	return m.matriz[f][c];
}


void Set(MatrizBit& m, int f, int c, bool v){
	m.matriz[f][c]= v;
}

