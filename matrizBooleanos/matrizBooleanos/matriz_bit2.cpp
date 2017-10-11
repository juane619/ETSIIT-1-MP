#include "matriz_bit2.h"

bool Inicializar(MatrizBit& m, int fils, int cols){

	if(fils*cols<=100){
		m.filas = fils;
		m.columnas = cols;
		for(int i=0; i<fils*cols; i++)
			m.matriz[i]=0;
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
	return m.matriz[f*m.columnas+c];
}


void Set(MatrizBit& m, int f, int c, bool v){
	m.matriz[f*m.columnas+c]= v;
}

