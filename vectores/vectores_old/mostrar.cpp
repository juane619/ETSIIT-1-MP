#include <iostream>
#include <fstream> // ifstream
#include <cstring>
using namespace std;

// FIXME 5: añadir un nuevo campo
struct VecDin {
   int *datos;
   int usados;
   int reservados;
};

// FIXME 1: Redimensions v para que se quede con "nuevo" elementos
// FIXME 5: tener en cuenta un nuevo campo en v
void ReSize(VecDin& v, int nuevo)
{
	if(nuevo > v.reservados){
		v.reservados = nuevo;
		int *aux = new int[nuevo];
		
		for(int i=0; i<v.usados; i++)
			aux[i] = v.datos[i];
			
		delete[] v.datos;
		v.datos = aux;	
	}
	
	v.usados = nuevo;
}
void Add(VecDin& v,int dato);
// FIXME 2: Lee objetos int hasta final de flujo y devuelve VecDin con los datos (usa ReSize)
VecDin LeerVecDin(istream& flujo)
{
	VecDin vec= {0,0,0};
	int i=0, datos;
	
	while(flujo>>datos){
		Add(vec, datos);
	}

	return vec;
}

// FIXME 3: Muestra en un flujo de salida los datos enteros de un VecDin (ver main)

void Mostrar(const VecDin& v){
	for(int i=0; i<v.usados; i++)
		cout << v.datos[i] << " ";
}

// FIXME 3: Libera la memoria reservada en un VecDin (ver main)

void Liberar(VecDin& v){
	delete[] v.datos;
}


// FIXME 4: Añade un dato al final del vector
// FIXME 6: Mejora de eficiencia con reservados
void Add(VecDin& v,int dato)
{
	if(v.usados<v.reservados || v.usados == 0)
		ReSize(v, v.usados+1);
		
	else if(v.usados == v.reservados){
		ReSize(v, v.reservados*2);
		ReSize(v, v.reservados/2+1);
	}
	
	v.datos[v.usados-1]= dato;
}

// FIXME 7: Ordena v con "Seleccion" implementado recursivo
void SeleccionRecursivo(int *v, int n)
{
	int aux, pos_min=0;
	for(int i=0; i<n; i++){
		if(v[i]<v[0])
			pos_min = i;
	}
	aux = v[0];
	v[0] = v[pos_min];
	v[pos_min]= aux;
}

// FIXME 7: Usa SeleccionRecursivo para ordenar v
void Ordenar(VecDin& v)
{
	int *vec=v.datos;
	for(int i=0; i<v.usados; i++){
		SeleccionRecursivo(vec, v.usados-i);
		vec++;
	}
}


int main(int argc, char *argv[])
{
   VecDin v= {0,0,0};
   
   if (argc==1){
      v= LeerVecDin(cin);      
   }
   else {
   	if(argc==2){
	      ifstream f(argv[1]);
	      if (!f) {
	         cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
	         return 1;
	      }
	      v= LeerVecDin(f);
   	}
      else if(argc == 3){
			ifstream f(argv[2]);
	      if (!f) {
	         cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
	         return 1;
	      }
	      v= LeerVecDin(f);
			if(!strcmp(argv[1], "-s"))
				Ordenar(v);
		}
   }
   Mostrar(v);

   Liberar(v); // Libera la memoria reservada
   
}  
