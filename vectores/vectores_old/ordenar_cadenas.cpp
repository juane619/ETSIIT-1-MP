#include <iostream>
#include <fstream>
#include <cstring> // strcmp, strlen

using namespace std;

struct ListadoNombres {
   char** cadenas;
   int ncads;
};


// Suponemos las lineas son como mucho de 1024 caracteres
// Devuelve el puntero nulo si hay error.
// Recuerde que cin.getline "devuelve true" (realmente es el flujo) en caso de exito
// FIXME 1: Crear funcion LeerLinea que lee una linea de un archivo, y devuelve un bloque
//          en memoria dinamica con una copia de la linea
char* LeerLinea(istream& flujo)
{
	char *line;
	line=new char[1024];
	if(flujo.getline(line, 1024))
		return line;
	else
		line = NULL;
	
	return line;
}

// FIXME 5: Crear una función que libera un ListadoNombres (ver main)
void Liberar(ListadoNombres& list){
	for(int i=0; i<list.ncads; i++)
		delete[] list.cadenas[i];
	delete[] list.cadenas;
}

// FIXME 2: Crear una funcion AddLineas 
//          que usa LeerLinea para cargar un flujo en un ListadoNombres (ver main)
void AddLineas(istream& flujo, ListadoNombres& list){
	char *linea;
	
	while(linea=LeerLinea(flujo)){
		if(list.ncads==0){
			list.cadenas = new char*[list.ncads+1];
			list.cadenas[list.ncads]= new char[strlen(linea)+1];
			list.cadenas[list.ncads]=linea;
		}
		else{
			char **aux;
			aux=new char*[list.ncads+1];
			for(int i=0; i<list.ncads; i++){
				aux[i]= new char[strlen(list.cadenas[i])+1];
				aux[i]=list.cadenas[i];
			}
			delete[] list.cadenas;
			
			list.cadenas= aux;
			list.cadenas[list.ncads]= new char[strlen(linea)+1];
			list.cadenas[list.ncads]=linea;
		}
		
		list.ncads++;
	}
}

// Función auxiliar para OrdenarShell
int CalcularSaltoInicial(int n)
{
   int salto= 1;
   while (salto<n/9)
      salto= salto*3+1;
   return salto;
}

// FIXME 3: Implementar la funcion OrdenarShell
// cmp es como strcmp (devuelve un entero negativo, cero o positivo)
// Consultar OrdenarShell para enteros, que se ha entregado resuelta
void OrdenarShell (ListadoNombres& listado, int cmp(const char* s1, const char* s2))
{
	for (int salto= CalcularSaltoInicial(listado.ncads); salto>0; salto= salto/3) {
			for (int i=salto; i<listado.ncads; ++i){
				char *x= listado.cadenas[i];
				int j;
         	for (j=i; j>=salto && cmp(x, listado.cadenas[j-salto])<0; j=j-salto)
         		listado.cadenas[j]= listado.cadenas[j-salto];
         	listado.cadenas[j]= x;
			}
	}
}
/*
void OrdenarShell (int vector[], int n)
{
   for (int salto= CalcularSaltoInicial(n); salto>0; salto= salto/3) {
      // Aplicamos Insercion a cada vector que empieza en v+salto de salto en salto
      for (int i=salto; i<n; ++i) { // Los va procesando todos los v-saltos a la vez
         int x= vector[i];
         int j;
         for (j=i; j>=salto && x<vector[j-salto]; j=j-salto)
         	vector[j]= vector[j-salto];
         vector[j]= x;
      }
   }
}
*/

// FIXME 4: Crear una función que lista las líneas de un ListadoNombres (ver main)

void Mostrar(ostream& os, ListadoNombres& list){
		for(int i=0; i<list.ncads; i++){
			for(int j=0; list.cadenas[i][j]!='\0'; j++)
				os << list.cadenas[i][j];
			os << endl;
			}
}


// La funcion main esta terminada, no se debe tocar
int main(int argc, char* argv[])
{
   ListadoNombres listado= {0,0};
   bool ordenar= false;
   
   if (argc==1){
   	ifstream f("cadenas.txt");
      AddLineas(f, listado);
   }
   else if (argc==2) {
      ifstream f(argv[argc-1]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      AddLineas(f, listado);
   }
   else  
   {
      cerr << "Uso: " << argv[0] << " [<fichero>]" << endl;
      return 1;
   }
   cout << "Original: " << endl;
   Mostrar(cout, listado);
   cout << endl;
   OrdenarShell(listado, strcmp);
   cout << "Resultado: " << endl;
	Mostrar(cout, listado);
   Liberar(listado); // Libera la memoria reservada
}  
