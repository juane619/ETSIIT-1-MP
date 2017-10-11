#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
using namespace std;

struct Celda {
  int dato;
  Celda* sig;
};

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
  double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
  return minimo+(maximo-minimo+1)*u01;
}


// FIXME 1: Añadir un elemento a una lista. Se añade como primer elemento
void Add(Celda*& l, int e){
	Celda *nodo= new Celda;
	nodo->dato= e;
	nodo->sig= NULL;
	
	if(l == NULL)
		l= nodo;
	else{
		nodo->sig= l;
		l=nodo;
	}
}


// FIXME 2: Liberar todas las celdas de una lista y dejarla a cero
void Liberar(Celda*& lista){
	Celda* aux= new Celda;
	
	
	while(lista != NULL){
		aux= lista;
		lista=aux->sig;
		delete aux;
	}
}


// FIXME 3: Listar los elementos de una lista entre llaves y separados por comas
void Listar(Celda* lista){
	cout << "{";
	
	while(lista != NULL){
		cout << lista->dato << ",";
		lista=lista->sig;
	}
	cout << "}";
}


// FIXME 4: Crear función Size para calcular el número de elemento de la lista
int Size(Celda* lista){
	int size=0;
	
	while(lista != NULL){
		size++;
		lista= lista->sig;
	}
	
	return size;
}


// FIXME 5: Crear una función Buscar que devuelva la celda donde está un dato. Puntero nulo si no está.

Celda* BuscarCelda(Celda* lista, int v){
	Celda* elemento;
	bool encontrado=false;
	
	while(lista != NULL && !encontrado){
		if(lista->dato == v){
			elemento=lista;
			encontrado= true;
		}
		else lista=lista->sig;
	}
	if(!encontrado)
		elemento= NULL;
	
	return elemento;
}

// FIXME 6: Crear una función BuscarPuntero que devuelve un puntero a puntero.
Celda** BuscarPuntero(Celda*& lista, int v){
	Celda **sig_anterior;
	Celda *aux=lista;
	bool encontrado=false, primero= true;
	
	while(aux->sig != NULL && !encontrado){
		if(primero && aux->dato == v){
			sig_anterior= &lista;
			encontrado= true;
			}
		primero= false;
		
		if(!encontrado && !primero && aux->sig->dato == v){
			sig_anterior= &aux->sig;	
			encontrado= true;		
		}
		
		if(!encontrado)
			aux=aux->sig;
	}
	
	if(!encontrado)	
		sig_anterior= NULL;
	
	return sig_anterior;
}

// FIXME 7: Recibe un puntero a celda, la desengancha, y la devuelve como resultado
Celda* Descolgar(Celda**& cx){
	Celda *aux=*cx;
	
	if((*cx)->sig == NULL)
		(*cx)= NULL;
	else
		*cx=(*cx)->sig;
	
	return aux;
}
    
void EliminarDato(Celda *&lista, int v){
	Celda **el_busc= BuscarPuntero(lista, v);
	
	while(el_busc != NULL){
		Celda* c= Descolgar(el_busc);
		delete c;
		el_busc=BuscarPuntero(lista, v);
	}
}

// FIXME 8: Implementar Begin, Next, End

// FIXME 9: Añada una función Imprimir que recibe un rango e imprime todos los elementos del rango

int main(int argc, char* argv[])
{
  srand(time(0)); // Inicializamos generador de números
  
  int n=5, max=8;
    
    Celda* lista1= 0; // Listas vacías
    Celda* lista2= 0;
    Celda* celda_buscada;
    Celda** puntero_buscada;

    for (int i=0; i<n; ++i){
      Add(lista1, Uniforme(1,max)); // Añadimos un elemento al principio de la lista
      Listar(lista1);
}
      
    // FIXME 3: Llamar a listar los elementos
    Listar(lista1);
    
    // FIXME 4: Indicar el tamaño de la lista
   
   cout << "\nLa lista tiene " << Size(lista1) << " elementos.";
   
	 // FIXME 5: Pregunte un dato a buscar e indique si está en la lista
	int d_buscar;
	cout << "\n\nIndique que dato desea buscar: ";
	cin >> d_buscar;
	
	celda_buscada= BuscarCelda(lista1, d_buscar);
	
	puntero_buscada= BuscarPuntero(lista1, d_buscar);
	
	if(celda_buscada != NULL)
		cout << "\n\nBuscar celda: El dato esta en la lista.";
	else
		cout << "\nBuscar celda: El dato no esta en la lista.";
   
	 // FIXME 6: Buscar el mismo dato con un puntero a puntero en cada lista
	if(puntero_buscada != NULL)
		cout << "\n\nBuscar PUNTERO: El dato esta en la lista. \n";
	else
		cout << "\nBuscar PUNTERO: El dato no esta en la lista.\n\n";
		
	
    // FIXME 7: Mientras que exista el dato, lo desengancha, lo destruye y busca el siguiente
   //Descolgar(puntero_buscada);
   EliminarDato(lista1, d_buscar);
	Listar(lista1);
	
    // FIXME 9: Listado repetido pero con Imprimir
	
    // FIXME 2: Llamar a liberar los elementos de la lista
    Liberar(lista1);

  }  

