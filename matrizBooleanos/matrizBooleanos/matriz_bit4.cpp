#include "matriz_bit4.h"
#include <iostream>
using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols){

	if(fils*cols<=128){
		int contador = 0;
      m.filcol = 0;
      m.filcol = (fils << 8) + cols;

      for(int i = 0; i < fils; i++){
         for(int j = 0; j < cols; j++){
            if ((i * cols + j) > 31 * (contador + 1))
               contador++;
            m.matriz[contador] = 0;
         }
	}
		return true;
   }
	else
		return false;

}

int Filas (const MatrizBit& m){
	return m.filcol>>8;
}


int Columnas(const MatrizBit& m){
	return m.filcol & 0x00FF;
}

bool Get(const MatrizBit& m, int f, int c){

	int posicion = f * Columnas(m) + c;
	unsigned int comprobante = 1;
	comprobante = comprobante << posicion;
	int contador = posicion / 32;
	unsigned int devolver = m.matriz[contador] & comprobante;

	devolver = devolver >> posicion;

	return devolver;
}

void Set(MatrizBit& m, int f, int c, bool v){

	int posicion = f * Columnas(m) + c;
	unsigned int comprobante = 1;
	int contador = posicion / 32;

	comprobante = comprobante << posicion;

	if(v == true)
		m.matriz[contador] = m.matriz[contador] | comprobante;
	else
		m.matriz[contador] = m.matriz[contador] & ~comprobante;

}

