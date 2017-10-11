#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
#include <iomanip> // setw

using namespace std;

void Intercambiar(int& el1, int& el2){
	int aux = el1;
	el1 = el2;
	el2 = aux;
}

void Intercambiar(const int*& el1, const int*& el2){
	const int* aux = el1;
	el1 = el2;
	el2 = aux;
}

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand() / (RAND_MAX+1.0); // Uniforme01
   return minimo + (maximo-minimo+1) * u01;
}

void Generar(int *v, int n, int max)
{
   for (int i=0;i<n;++i) 
      v[i]=i%max+1;
   
   int pos1,pos2;
   for (int i=0; i<10*n; ++i) {
      pos1= Uniforme(0,n-1);
      pos2= Uniforme(0,n-1);
      Intercambiar(v[pos1], v[pos2]);
   }
}

// FIXME 1: Mejora el algoritmo de burbuja para el caso de vector casi-ordenado
// FIXME 2: Modificar el algoritmo anterior para realizar una ordenación bidireccional
// FIXME 5: Parametrizar el método de ordenación. Generar el último listado con otro orden.
int OrdenHabitual(int l, int r)
{
	return l-r;
}

int OrdenHabitualInversa(int l, int r)
{
	return r-l;
}

void OrdenarBurbuja (int vec[], int n, int (*orden) (int a, int b))
{
	bool algun_cambio= true;
   for (int i=n-1; i>0 && algun_cambio; --i){
   	algun_cambio=false;
      for (int j=0; j<i; ++j)
         if ((*orden)(vec[j], vec[j+1])>=1) {
            Intercambiar(vec[j], vec[j+1]);
            algun_cambio = true;
         }
      }
}

int Orden(int l, int r)
{
return (l&1 && r&1)||((l&1)==0 && (r&1)==0) ? r-l : (l&1)-(r&1);
}

void OrdenarBurbujaBi (int vec[], int n)
{
	bool algun_cambio;
	int actual=0, direccion=1;
	int comienzo=1, fin=n-1;
	do {
		algun_cambio=false;
		while (((direccion==1) && (actual<fin)) || ((direccion==-1) && (actual>comienzo))) {
			actual += direccion;
			if (vec[actual]<vec[actual-1]) {
				Intercambiar(vec[actual], vec[actual-1]);
				algun_cambio=true;
			}
		}
		if (direccion==1) 
			fin--; 
		else 
			comienzo++;
			
		direccion = -direccion;
	} while (algun_cambio);
}

// FIXME 5: Añadir posibles formas de ordenación para parámetro de OrdenarBurbuja

// FIXME 3: Incluir función que ordena punteros a los datos
void OrdenarVecp (const int** v, const int * const vec, int n)
{
	bool algun_cambio;
	int actual=0, direccion=1;
	int comienzo=1, fin=n-1;
	do {
		algun_cambio=false;
		while (((direccion==1) && (actual<fin)) || ((direccion==-1) && (actual>comienzo))) {
			actual += direccion;
			if (*v[actual]<*v[actual-1]) {
				Intercambiar(v[actual], v[actual-1]);
				algun_cambio=true;
			}
		}
		if (direccion==1) 
			fin--; 
		else 
			comienzo++;
			
		direccion = -direccion;
	} while (algun_cambio);
}

void IniVecPun(const int** v, const int* const vec, int n){
	for(int i=0; i<n; i++)
		v[i] = &vec[i];
}

int main(int argc, char *argv[])
{
   //argc =3;
	if (argc!=3) {
      cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
      return 1;
   }
   
   srand(time(0)); // Inicializamos generador de números
   
   int n= atoi(argv[1]);
   //int n=15;
   
   if (n<5) {
      cerr << "Debería especificar al menos 5 elementos" << endl;
      return 2;
   }
   else {
      int max= atoi(argv[2]);
      //int max = 20;
      if (max<5) {
         cerr << "Debería especificar un max de al menos 5" << endl;
         return 3;
      }
      int (*orden_mayor) (int a, int b);
      const int** v_p= new const int*[n];
		int *v= new int[n];
		
		int* v_saltos= new int[n];
      
      Generar(v,n,max);
      
      // FIXME 4: Imprimir los generados ordenados usando punteros
      IniVecPun(v_p, v, n);
      OrdenarVecp(v_p, v, n);
		
		cout << "Ordenados: ";
      for (int i=0; i<n; ++i)
         cout <<  setw(3) << *v_p[i] << " "; 
      cout << endl;
      
      cout << "Generados: ";
      for (int i=0; i<n; ++i)
         cout <<  setw(3) << v[i] << " "; 
      cout << endl;
      
      OrdenarBurbuja(v,n, OrdenHabitualInversa);
      
      cout << "Ordenados: ";
      for (int i=0; i<n; ++i)
         cout <<  setw(3) << v[i] << " "; 
      cout << endl;
		
   
      // FIXME 5: Cambiar la llamada para usar el parámetro
      
      
      //FIXME 4: Imprimir el salto en posiciones de cada elemento
      cout << "Saltos:    ";
		for(int i=0; i<n; i++)
			cout <<  setw(3) << &v[i]-v_p[i] << " ";
      
      cout << endl << Orden(0,2);
      delete[] v;
      
   }
}
  
  
