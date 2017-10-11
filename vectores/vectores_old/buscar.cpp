#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
#include <cstring>

using namespace std;

//Funcion Intercambiar 2 elementos
void Intercambiar(int& el1, int& el2){
	int aux = el1;
	el1 = el2;
	el2 = aux;
}

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
   return minimo+(maximo-minimo+1)*u01;
}

// FIXME 1: Rellena el vector con n enteros del 1 a max y los mezcla (ver main)

void Barajar(int* v, int vueltas){
	int indice1, indice2;
	for(int i=0; i<vueltas; i++){
		indice1 = Uniforme(i, vueltas);
		indice2 = Uniforme(i, vueltas);
		Intercambiar(v[indice1], v[indice2]);
	}
}

void Generar(int*& v, int n, int max){
	v= new int[n];
	for(int i=0; i<n; i++)
		v[i] = i%max+1;
	Barajar(v, n-1);
}

// FIXME 4: Cambio de interfaz, devolviendo n si no esta.
int Buscar(const int *v, int desde, int n, int dato)
{
   for (int i=desde;i<n;++i)
      if (v[i]==dato)
         return i;
   return n;
}

// FIXME 5: Implementar busqueda garantizada. Pre: el dato esta�
// FIXME 7: Cambiar la interfaz de la funcion
int* BuscarGarantizada(int* inicial, int dato)
{
	while(*inicial != dato){
		inicial++;
	}
	
   return inicial;
}


// FIXME 8: Incluir algoritmo OrdenarInsercion
void OrdenaInsercion(int*& v, int n){
	//Ponemos en la primera posicion el valor minimo.
	int minimo= 0, j;
	for(int i=0; i<n; i++)
		if(v[i]<v[minimo])
			minimo = i;
	Intercambiar(v[0], v[minimo]);
	
	//De la parte derecha, vemos en que posicion del vector izquierdo, colocariamos el mas peque�o que el ultimo ya ordenado.
	for(int i=1; i<n; i++){
		int x=v[i];
		for(j=i; x<v[j-1]; j--)
			v[j]= v[j-1];
		v[j]= x;
	}
		
}

// FIXME 9: Incluir busqueda binaria recursiva
int BusquedaBinariaRec (const int *vec, int i, int f, int dato)
{
	int der= f, izq= i;
	
   int centro= (izq+der) / 2;
   
  	if(vec[centro] == dato)
  		return centro;
  	else{
	  	if(vec[centro] > dato)
		      return BusquedaBinariaRec(vec, izq, centro-1, dato);
		else if (vec[centro] < dato)
	  			return BusquedaBinariaRec(vec, centro+1, der, dato);
   }
   return -1; 
}

// FIXME 10: Modificar funcion para implementar interpolacion
int BusquedaBinariaInterp (const int *vec, int n, int dato)
{
   int izq= 0, der= n-1;
   
   while (izq<=der) {
	   int centro= izq+((dato-vec[izq])/(vec[der]-vec[izq]))*(der-izq);
	   if (vec[centro] > dato)
	      der= centro-1;
	   else if (vec[centro] < dato)
	            izq= centro+1;
	         else return centro;
   }
   return -1; 
}

void Liberar(int*& v){
	delete[] v;
}

int main(int argc, char *argv[])
{
   argc = 3;
	if (argc!=3) {
      cerr << "Uso: " << argv[0] << " <numero de datos> <maximo dato>" <<endl;
      return 1;
   }
   
   srand(time(0)); // Inicializamos generador de numeros

   int n= atoi(argv[1]);
   
   if (n<5) {
      cerr << "Deberia especificar al menos 5 elementos" << endl;
      return 2;
   }
   else {
   	int dato;
      int *v;
      int *pos_dato;
      int pos_bin;

      // FIXME 1: prepara el vector v
      int max=atoi(argv[2]);
      

      // FIXME 6: reservar una posicion mas para garantizar la busqueda
      Generar(v, n+1, max);
      cout << "Generados: ";

      for (int i=0;i<n;++i)
         cout << v[i] << " "; 

      cout << endl << endl;
      
      // FIXME 8: Ordenar el vector con OrdenarInsercion y listarlos
		OrdenaInsercion(v, n);
		
		for (int i=0;i<n;++i)
         cout << v[i] << " "; 

      cout << endl << endl;
      
      // FIXME 2: Pregunta por dato a buscar y lo localiza
		cout << "Dato a buscar: ";
      cin >> dato;
      cout << endl;
      
      // FIXME 3: Modificacion para localizar todas las ocurrencias
     
		v[n]=dato;
		pos_dato= BuscarGarantizada(v, dato);
 
		if((pos_dato-v) != n){
			do{
				cout << "Encontrado en: " << pos_dato-v << endl;
				pos_dato= BuscarGarantizada(pos_dato+1, dato);
			}while((pos_dato-v) != n);
		}
		else
			cout << "Tamanio vector: " << pos_dato-v << endl;

      // FIXME 6: Colocar el dato en la posición detrás de la última
      
      
      // FIXME 7: Cambiar a la nueva interfaz de la búsqueda

      
      // FIXME 9: Preguntar por búsqueda binaria y resolver la posición
      cout << "Dato a buscar binario: ";
      cin >> dato;
      cout << endl;
      
      pos_bin= BusquedaBinariaInterp(v, n, dato);
 
		cout << "Encontrado en: " << pos_bin << endl;
		
      // FIXME 1: deja de usarse v
     Liberar(v); 
   }
}
  
  
