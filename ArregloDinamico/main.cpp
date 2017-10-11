#include <iostream>
#include <stdlib.h>
#include <ArregloCaracteres.h>

using namespace std;

int main()
{
    ArregloCaracteres cadena1("campo");
    cadena1.concatenar(" santo");
    cout<<"La cadena es : "<<cadena1.c_ptr()<<"\n";

    cadena1 = "me la mato de pena";
    cout<<"\n Cadena inicial : "<<cadena1.c_ptr();
    // reemplazar vocales
    cadena1.reemplazar_cualquiera('e',"aeiou",0);
    cout<<"\n Reemplazando vocales : "<<cadena1.c_ptr();

    cadena1.insertar_caracter('-',5);
    cout<<"\n Insertando caracter: "<<cadena1.c_ptr();

    cadena1.eliminar_caracteres(5,1);
    cout<<"\n Eliminando caracter: "<<cadena1.c_ptr();

    // borremosle una palabra
    ArregloCaracteres cadena2;
    cadena2.reemplazar_palabra(cadena1.c_ptr(),"pene", "pito");
    cout<<"\n Cadena modificada : "<<cadena2.c_ptr();

    // eliminar
    cadena2.eliminar_caracteres(5,8);
    cout<<"\n Cadena recortada : "<<cadena2.c_ptr()<<"\n";

    // insertar
    cadena2.insertar_cadena("sueno un ",6);
    cout<<"\n Cadena con insercion : "<<cadena2.c_ptr()<<"\n";

    // cargar archivo
    cout<<"\n lee de archivo 'carta.txt' ";
    if(cadena1.leer_de_archivo("carta.txt")==false)
    {
        cout<<"\n No se pudo abrir la carta!!";
    }
    else
    {
        cout<<"\n la carta dice asi: \n";
        cout<<cadena1.c_ptr();
    }




    system("PAUSE");



    return 0;
}
