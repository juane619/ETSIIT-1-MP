#include <iostream>
#include <cstring>
#include <fstream> // ifstream
using namespace std;

// FIXME 5: añadir un nuevo campo
struct VecDin {
   int *datos;
   int usados;
   int reservados;
};

// FIXME 1: Redimensions v para que se quede con "nuevo" elementos
// FIXME 5: tener en cuenta un nuevo campo en v
void ReSize(VecDin& vec,int nuevo)
{
	if(nuevo>0){
		if(nuevo<=vec.reservados)
				vec.usados= nuevo;	
		else if(nuevo>vec.reservados){
			vec.reservados= nuevo;
			int *aux= new int[vec.reservados];
			
			if(vec.datos!=NULL){
				for(int a=0; a<vec.usados; a++)
					aux[a]= vec.datos[a];
				delete vec.datos;
			}
			vec.datos= aux;
			vec.usados= nuevo;
		}
	}
	else{
		delete vec.datos;
		vec.datos= NULL;
		vec.usados= 0;
	}
}
void Add(VecDin& v,int dato);
// FIXME 2: Lee objetos int hasta final de flujo y devuelve VecDin con los datos (usa ReSize)
VecDin LeerVecDin(istream& flujo)
{
	VecDin aux={0,0,0};
	int i;
	
	while(flujo>>i){
		Add(aux, i);
	}
	
	return aux;
}

// FIXME 3: Muestra en un flujo de salida los datos enteros de un VecDin (ver main)

void Mostrar(VecDin v, ostream &os){
	os << "\n\n";
	for(int a=0; a<v.usados; a++)
		os << v.datos[a] << " ";
	os << "\n\n";
}

// FIXME 3: Libera la memoria reservada en un VecDin (ver main)

void Liberar(VecDin &v){
	delete v.datos;
}


// FIXME 4: Añade un dato al final del vector
// FIXME 6: Mejora de eficiencia con reservados
void Add(VecDin& v,int dato)
{
	if(v.reservados==0)
		ReSize(v, 1);
	else if(v.usados<v.reservados)
		ReSize(v, v.usados+1);
	else if(v.usados=v.reservados){
		ReSize(v, v.usados*2);
		ReSize(v, v.usados/2+1);
	}
	v.datos[v.usados-1]= dato;
}

// FIXME 7: Ordena v con "Selección" implementado recursivo
void Intercambiar(int* p1, int* p2){
	int auxx=*p1;
	*p1= *p2;
	*p2= auxx;
}

void SeleccionRecursivo(int *v, int n)
{
	if(n>1){
		int aux;
		int pos_min=0;
		
		for(int i=1; i<n; i++)
			if(v[i] <= v[pos_min])
				pos_min= i;
		aux=v[0];
		v[0]= v[pos_min];
		v[pos_min]=aux;
		SeleccionRecursivo(v+1, n-1);
	}
}

// FIXME 7: Usa SeleccionRecursivo para ordenar v
void Ordenar(VecDin& v)
{
	SeleccionRecursivo(v.datos, v.usados);
}


int main(int argc, char *argv[])
{
   VecDin v= {0,0,0};
   
   if (argc==1){
      v= LeerVecDin(cin);
      Mostrar(v, cout);
      Ordenar(v);
	}
   else{
   	if(argc==2){
	      ifstream f(argv[1]);
	      if (!f) {
	         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
	         return 1;
      	}
      	v= LeerVecDin(f);
		}
		else if(argc==3){
	      ifstream f(argv[1]);
	      if (!f) {
	         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
	         return 1;
      	}
      	v= LeerVecDin(f);
      	Ordenar(v);
      	string par=argv[2];
			
			if(par=="-s"){
				cout << "Entrando en el if";
				Ordenar(v);
			}
		}
   }
   
	Mostrar(v, cout);
   Liberar(v); // Libera la memoria reservada
}  
