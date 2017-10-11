#include <iostream>
#include <fstream>
#include "matriz_operaciones.h"
using namespace std;

int Longitud(char v[]){
    int i=0;
    while(v[i] != '\0')
        i++;
    return i;
}
/*
int Colum(std::istream is){
    int colum = 0;
    char car;
    while(!is.eof()){
                is.get(car);
                if(car == '\n')
                    colum++;
            }
    return colum;
}*/

bool Leer(std::istream& is, MatrizBit& m){
	char c;
	int filas, columnas;

	is >> filas;
	is >> columnas;

	if(is){
        if(Inicializar(m, filas, columnas)){
            for(int i=0; i<filas; i++)
                for(int j=0; j<columnas; j++){
                    is >> c;
                    Set(m, i, j, c=='1');
                }
            return true;
      }
      else
         return false;
   }
	else
      return false;
}

bool Leer(const char nombre[], MatrizBit& m){
	ifstream f(nombre), f2(nombre);
	char fila[100]={'\0'};
    char car;
	if(f){
        if(f.peek() == 'X' || f.peek() == '.'){
            cout << "leyendo matriz con X y ." << endl;
            int columnas=0, filas=0;
            f.getline(fila, 100);
            columnas = Longitud(fila);
            while(!f.eof()){
                f.get(car);
                if(car == '\n')
                    filas++;
            }
            cout << "filas " << filas << "columnas " << columnas << endl;
            Inicializar(m, filas, columnas);
            for(int i=0; i<filas; i++)
                for(int j=0; j<columnas; j++){
                    f2>>car;
                    Set(m, i, j, car=='X');
                }
            return 1;
        }
        else{
            cout << "NO leyendo matriz con X y .";
            if(Leer(f, m)){
             f.close();
             return 1;
            }
            else
                return 0;
		}
	}
	else{
        cout << "ERROR LECTURA";
		return 0;
    }
}

bool Escribir(std::ostream& os, const MatrizBit& m){
	cout << Filas(m)<< " " << Columnas(m) << endl;
	for(int i=0; i<Filas(m); i++){
		for(int j=0; j<Columnas(m); j++)
			os << Get(m, i, j) << ' ';
		os << '\n';
	}
	return 1;
}

bool Escribir(const char nombre[], const MatrizBit& m){
	ofstream s(nombre);
	if(Escribir(s, m)){
      s.close();
      return 1;
   }
   else
      return 0;
}

void Not(MatrizBit& res, const MatrizBit& m){
   Inicializar(res, Filas(m), Columnas(m));
   for(int i=0; i<Filas(res); i++)
      for(int j=0; j<Columnas(res); j++)
         Set(res, i, j, !Get(m, i, j));

}

void Traspuesta(MatrizBit& res, const MatrizBit& m){
   Inicializar(res, Columnas(m), Filas(m));
   for(int i=0; i<Filas(res); i++)
      for(int j=0; j<Columnas(res); j++)
         Set(res, i, j, Get(m, j, i));
}

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
   bool elm1, elm2, elres;
   Inicializar(res, Filas(m1), Columnas(m1));
   for(int i=0; i<Filas(res); i++){
      for(int j=0; j<Columnas(res); j++){
         elm1 = Get(m1, i, j);
         elm2 = Get(m2, i, j);
         elres = elm1 && elm2;
         Set(res, i, j, elres);
      }
   }
}


void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2){
   int filas_res = Filas(m1);
   int columnas_res= Columnas(m1);
   bool elm1, elm2, elres;
   Inicializar(res, filas_res, columnas_res);
   for(int i=0; i<filas_res; i++){
      for(int j=0; j<columnas_res; j++){
         elm1 = Get(m1, i, j);
         elm2 = Get(m2, i, j);
         elres = elm1 && elm2;
         Set(res, i, j, elres);
      }
   }
}



