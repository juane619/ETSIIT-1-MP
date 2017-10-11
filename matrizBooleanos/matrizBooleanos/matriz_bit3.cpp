#include "matriz_bit3.h"
using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols){
	if(fils*cols<=100){
		m.filcol= 0;
   	m.filcol=m.filcol|fils;
    	m.filcol=m.filcol<<16;
      m.filcol=m.filcol|cols;
		for(int i=0; i<fils*cols; i++)
			m.matriz[i]='0';
		return true;
	}
	else
		return false;
}

int Filas (const MatrizBit& m){
	return m.filcol>>16;
}


int Columnas(const MatrizBit& m){
	return m.filcol & 0xFFFF;
}


bool Get(const MatrizBit& m, int f, int c){
	return m.matriz[f*Columnas(m)+c];
}


void Set(MatrizBit& m, int f, int c, bool v){
   char va;
   if (v)
      va = '1';
   else
      va = '0';
	m.matriz[f*Columnas(m)+c]= va;
}

