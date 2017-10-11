#include "util_celdas.h"
using namespace std;

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
	cout << "\n{";
	
	while(lista != NULL){
		
		
		if(lista->sig!= NULL) 
			cout << lista->dato << ","; 
		else
			cout << lista->dato;
			
		lista=lista->sig;
	}
	cout << "}\n\n";
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

//BUSCAR MAXIMO
Celda** BuscarMaximo(Celda*& lista){
	Celda* aux=lista;
	Celda** sig_anterior_mayor= &lista;
	
	while(aux != NULL){
		if(aux->sig!= NULL && aux->sig->dato >= (*sig_anterior_mayor)->dato)
			sig_anterior_mayor= &(aux->sig);
			
			aux=aux->sig;
	}
	
	return sig_anterior_mayor;
}

//ORDENAR POR SELECCION
void OrdenaSeleccion(Celda*& lista){
	Celda *aux=NULL;
	Celda **maximo_actual= BuscarMaximo(lista);
	
	while(lista != NULL){
		Add(aux, (*maximo_actual)->dato);
		delete Descolgar(maximo_actual);
		maximo_actual= BuscarMaximo(lista);
	}
	lista=aux;
}

//MEZCLA
//A�adir celda al final
void AddFinal(Celda*& lista, Celda* add, Celda*& final){
	if(lista == NULL){
		lista= add;
		add->sig= NULL;
	}
	else{
		final->sig= add;
		add->sig= NULL;
	}
	final= add;
}

Celda* Mezcla(Celda*& l1, Celda*& l2){
	Celda *lista_ordenada=NULL, *ultima_celda=lista_ordenada;
	Celda *primer_peq=NULL;
	Celda** a_desc_l1= &l1;
	Celda** a_desc_l2= &l2;
	
	while(l1 != NULL || l2 != NULL){
		if(l1 == NULL)
			while(l2 != NULL){
				primer_peq= Descolgar(a_desc_l2);
				AddFinal(lista_ordenada, primer_peq, ultima_celda);
			}
		else if(l2 == NULL)
			while(l1 != NULL){
				primer_peq= Descolgar(a_desc_l1);
				AddFinal(lista_ordenada, primer_peq, ultima_celda);
			}
		else{
			if(l1->dato <= l2->dato){
				primer_peq=Descolgar(a_desc_l1);
				AddFinal(lista_ordenada, primer_peq, ultima_celda);
			}
			else if(l2->dato <= l1->dato){
				primer_peq=Descolgar(a_desc_l2);
				AddFinal(lista_ordenada, primer_peq, ultima_celda);
			}
		}
	}
	l1= lista_ordenada;
	return l1;
}

//MERGESORT
Celda* Mergesort(Celda*& lista){
	Celda *l1= NULL, *l2= NULL;
	int tam_lista= Size(lista);
	
	if(tam_lista<=1){
		return lista;
	}
	else{
		l1= lista;
		for(int i=0; i<tam_lista/2-1; i++){
			l1= l1->sig;
		}
		
		l2=l1->sig;
		l1->sig=NULL;
		
		l1= Mergesort(lista);
		l2= Mergesort(l2);
		//cout << "mezclando";
		return Mezcla(l1,l2);
	}
}

//ORDENA ESPECIAL
void OrdenarEspecial(Celda*& l)
{
	Celda* vec[32]= {0};
	Celda** tope= &(vec[0]);
	
	while (l) {
		Celda* acarreo= l;
		l= l->sig;
		acarreo->sig= 0;
		Celda** aux= &(vec[0]);
		
		while(*aux != 0) {
			acarreo= Mezcla(acarreo,*aux);
			aux++;
		}
		*aux= acarreo;
		
		if(aux==tope)
			++tope;
	}
	
	for (Celda** p=&(vec[0]); p!=tope; ++p) {
		l= Mezcla(l,*p);
	}
}


