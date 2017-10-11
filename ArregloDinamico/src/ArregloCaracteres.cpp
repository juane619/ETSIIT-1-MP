#include "ArregloCaracteres.h"
#include <stdio.h>
/// Constante del caracter nulo
const char caracter_nulo = 0;

// Funcion de utilidad
int ArregloCaracteres::calcular_longitud_cadena(const char * cad)
{
    int i = 0;
    while(cad[i]!= 0)
    {
        i++;
    }
    return i;
}


ArregloCaracteres::ArregloCaracteres()
{
    m_buffer = NULL;
    m_longitud = 0;
    m_capacidad = 0;
}

ArregloCaracteres::ArregloCaracteres(int capacidad_inicial)
{
    reservar_memoria(capacidad_inicial);
    m_buffer[0] = 0;
    m_longitud = 0;
}

ArregloCaracteres::ArregloCaracteres(const char * constante_cadena)
{
    m_buffer = NULL;
    m_longitud = 0;
    m_capacidad = 0;
    asignar(constante_cadena);
}

ArregloCaracteres::ArregloCaracteres(const ArregloCaracteres & otro)
{
    m_buffer = NULL;
    m_longitud = 0;
    m_capacidad = 0;
    asignar(otro);
}

ArregloCaracteres::~ArregloCaracteres()
{
    vaciar(true);
}

bool ArregloCaracteres::esta_vacia()  const
{
    if(m_buffer==NULL) return true;
    if(m_buffer[0] == 0) return true;
    return false;
}
const char * ArregloCaracteres::c_ptr() const
{
    /// Si no hay buffer retornamos una referencia al caracter nulo
    if(m_buffer==NULL) return &caracter_nulo;
    return m_buffer;
}

char * ArregloCaracteres::ptr()
{
    return m_buffer;
}

/// para obtener caracter
char ArregloCaracteres::operator[](int posicion) const
{
    return m_buffer[posicion];
}

/// para asignar caracter
char & ArregloCaracteres::operator[](int posicion)
{
    /// retorna la referencia
    return m_buffer[posicion];
}

ArregloCaracteres & ArregloCaracteres::operator=(const char * cad)
{
    asignar(cad);
    return *this;
}


    /// largo de la cadena
int ArregloCaracteres::largo() const
{
    return m_longitud;
}


int ArregloCaracteres::memoria_reservada() const
{
    return m_capacidad;
}


void ArregloCaracteres::asignar(const char *  cad)
{
    // calculamosn la longitud con la funcion de utilidad
    int len = ArregloCaracteres::calcular_longitud_cadena(cad);
    asignar(cad,len);
}


void ArregloCaracteres::asignar(const ArregloCaracteres & obj)
{
    asignar(obj.c_ptr(),obj.largo());
}

void ArregloCaracteres::asignar(const char *  cad, int num_caracteres)
{
    reservar_memoria(num_caracteres+1);

    /// copiar
    for (int i = 0;i<num_caracteres ;i++ )
    {
        m_buffer[i] = cad[i];
    }
    /// en la posicion final, asignar caracter nulo
    m_buffer[num_caracteres] = 0;
    m_longitud = num_caracteres;
}


void ArregloCaracteres::copiar_cadena(int posicion_destino, const char *  cad, int num_caracteres)
{
    int final = posicion_destino+num_caracteres;
    // verificar cota
    if(final> m_longitud)
    {
        // redimensionar
        cambiar_longitud(final);
    }

    // copiar

    int i = posicion_destino;
    while(i<final)
    {
        m_buffer[i] = cad[i-posicion_destino];
        i++;
    }
}

void ArregloCaracteres::reservar_memoria(int num_caracteres)
{
    if(m_capacidad>=num_caracteres)
    {
        return;// no hay necesidad de reservar
    }


    // crear un nuevo arreglo
    char * nuevobuffer = new char[num_caracteres];


    // copiar los caracteres de la antigua cadena
    if(m_longitud>0)
    {
        for (int i = 0;i<m_longitud ; i++)
        {
        	nuevobuffer[i] = m_buffer[i];
        }
        nuevobuffer[m_longitud]  = 0;
    }

    // destruir antiguo buffer
    delete [] m_buffer;

    m_buffer = nuevobuffer;
    m_capacidad = num_caracteres;
}

void ArregloCaracteres::cambiar_longitud(int newlongitud, char caracter_relleno)
{
    // verificar memoria suficiente
    reservar_memoria(newlongitud+1);

    if(newlongitud>m_longitud)
    {
        //  rellenar
        int i = m_longitud;
        while(i<newlongitud)
        {
            m_buffer[i] = caracter_relleno;
            i++;
        }
    }
    m_buffer[newlongitud] = 0; // al final colocar el caracter nulo
    m_longitud = newlongitud;
}


void ArregloCaracteres::vaciar(bool limpiar_memoria)
{
    m_longitud = 0;
    if(m_buffer)
    {
        if(limpiar_memoria)
        {
            delete [] m_buffer;
            m_capacidad = 0;
            m_buffer = 0;
        }
        else
        {
            // solamente asignar nulo
            m_buffer[0] = NULL;
        }
    }
}

void ArregloCaracteres::concatenar(const char * cad)
{
    int len = ArregloCaracteres::calcular_longitud_cadena(cad);
    concatenar(cad,len);
}

void ArregloCaracteres::concatenar(const ArregloCaracteres & otro)
{
    concatenar(otro.c_ptr(),otro.largo());
}


void ArregloCaracteres::concatenar(const char *  cad, int num_caracteres)
{
    int final = m_longitud+num_caracteres;
    reservar_memoria(final+1);
    int i=0;
    // copiar caracters
    while(m_longitud<final)
    {
        m_buffer[m_longitud] = cad[i];
        m_longitud++;
        i++;
    }
    m_buffer[m_longitud] = 0;
}


void ArregloCaracteres::agregar_caracter(char c)
{
    // agrandar el arreglo
    if(m_capacidad==0)
    {
        reservar_memoria(4);
    }
    else if(m_longitud>=m_capacidad-1)
    {
        reservar_memoria((m_capacidad+1)*2);
    }


    m_buffer[m_longitud] = c;
    m_longitud++;
    m_buffer[m_longitud] = 0;
}


void ArregloCaracteres::insertar_caracter(char c, int posicion)
{
    int nuevo_largo = m_longitud+1;
    if(posicion>m_longitud-1)
    {
        nuevo_largo = posicion+1;
    }

    cambiar_longitud(nuevo_largo);

    // mover los caracteres una posicion hacia adelante
    int i = m_longitud-1;
    while(i>posicion)
    {
        m_buffer[i] = m_buffer[i-1];
        i--;
    }
    m_buffer[posicion] = c;
    m_buffer[m_longitud] = 0;
}

void ArregloCaracteres::insertar_cadena(const ArregloCaracteres & obj, int posicion)
{
    insertar_cadena(obj.c_ptr(),obj.largo(),posicion);
}

void ArregloCaracteres::insertar_cadena(const char * cad, int posicion)
{
    int len = ArregloCaracteres::calcular_longitud_cadena(cad);
    insertar_cadena(cad,len,posicion);
}

void ArregloCaracteres::insertar_cadena(const char * cad, int ncaracteres, int posicion)
{
    int nuevo_largo = m_longitud+ncaracteres;
    if(posicion>m_longitud-1)
    {
        nuevo_largo = posicion+ncaracteres;
    }

    cambiar_longitud(nuevo_largo);

    // mover los caracteres n caracteres hacia adelante
    int i = m_longitud-1;
    int final = posicion+ncaracteres;
    while(i>=final)
    {
        m_buffer[i] = m_buffer[i-ncaracteres];
        i--;
    }

    // copiar los caracteres en esa posicion reservada
    i = posicion;
    while(i<final)
    {
        m_buffer[i] = cad[i-posicion];
        i++;
    }
    m_buffer[m_longitud] = 0;
}

void ArregloCaracteres::eliminar_caracteres(int posicion, int cantidad)
{
    // mover los caracteres de adelante una cierta cantidad de caracteres
    if(posicion>m_longitud-1) return; // nada que hacer
    int pos = posicion + cantidad;
    if(pos >=m_longitud)
    {
        m_longitud = posicion;
        m_buffer[m_longitud] = 0;
        return;// truncamiento al final
    }

    // mover los caracteres hacia atras
    while(pos<m_longitud)
    {
        m_buffer[pos-cantidad] = m_buffer[pos];
        pos++;
    }
    m_longitud-=cantidad;
    m_buffer[m_longitud] = 0;
}

int ArregloCaracteres::encontrar_caracter(char c, int posicion_inicial)
{
    int i = posicion_inicial;
    while(i<m_longitud)
    {
        if(m_buffer[i]==c)
        {
            return i;
        }
        i++;
    }
    return -1;// no encontrado
}

int ArregloCaracteres::encontrar_cualquiera(const char * conjunto_caracteres, int posicion_inicial)
{
    int conjunto_index;
    int i = posicion_inicial;
    while(i<m_longitud)
    {
        conjunto_index=0;
        while(conjunto_caracteres[conjunto_index]!=0)
        {
            if(m_buffer[i]==conjunto_caracteres[conjunto_index])
            {
                return i;
            }
            conjunto_index++;
        }
        i++;
    }
    return -1;// no encontrado
}


int ArregloCaracteres::encontrar_ninguno(const char * conjunto_caracteres, int posicion_inicial)
{
    int conjunto_index;
    int i = posicion_inicial;
    bool alguna_coincidencia;
    while(i<m_longitud)
    {
        conjunto_index=0;
        alguna_coincidencia = false;
        while(conjunto_caracteres[conjunto_index]!=0)
        {
            if(m_buffer[i]==conjunto_caracteres[conjunto_index])
            {
                alguna_coincidencia = true;
            }
            conjunto_index++;
        }
        if(alguna_coincidencia==false)
        {
            return i;
        }
        i++;
    }
    return -1;// no encontrado
}

int ArregloCaracteres::encontrar_palabra(const char * palabra, int posicion_inicial)
{
    int palabra_index=0;
    int i = posicion_inicial;
    while(i<m_longitud)
    {

        if(m_buffer[i]==palabra[palabra_index])
        {
            palabra_index++;
            if(palabra[palabra_index]==0) // fin de palabra
            {
                return i-palabra_index+1;// indice desde el cual inicio la palabra
            }
        }
        else
        {
            palabra_index = 0;// vuelva a empezar la cuenta, no coincide con la palabra
        }

        i++;
    }
    return -1;// no encontrado
}

int ArregloCaracteres::reemplazar_cualquiera(char reemplazo, const char * conjunto_caracteres, int posicion_inicial)
{
    int conjunto_index;
    int i = posicion_inicial;
    int num_reemplazos=0;
    while(i<m_longitud)
    {
        conjunto_index=0;
        while(conjunto_caracteres[conjunto_index]!=0)
        {
            if(m_buffer[i]==conjunto_caracteres[conjunto_index])
            {
                m_buffer[i] = reemplazo;
                num_reemplazos++;
                break;// rompe este ciclo
            }
            conjunto_index++;
        }

        i++;
    }
    return -1;// no encontrado
}




int ArregloCaracteres::reemplazar_palabra(const char * fuente, const char * palabra_a_reemplazar, const char * reemplazo)
{
    vaciar(false);

    ArregloCaracteres palabra_fuente(fuente);
    ArregloCaracteres palabra_reemplazo(reemplazo);

    reservar_memoria(palabra_fuente.memoria_reservada());
    int len_busqueda = ArregloCaracteres::calcular_longitud_cadena(palabra_a_reemplazar);
    int pos_ini = 0;
    int pos;
    int num_reemplazos = 0;
    do
    {
        pos = palabra_fuente.encontrar_palabra(palabra_a_reemplazar,pos_ini);
        if(pos!=-1)
        {
            concatenar(&palabra_fuente[pos_ini],pos-pos_ini);
            concatenar(palabra_reemplazo);
            pos_ini = pos+len_busqueda;
            num_reemplazos++;

        }
        else
        {
            concatenar(&palabra_fuente[pos_ini],palabra_fuente.largo()-pos_ini);
            pos_ini = palabra_fuente.largo();
        }

    }while(pos_ini<palabra_fuente.largo());

    return num_reemplazos;
}

bool ArregloCaracteres::leer_de_archivo(const char * nombrearhcivo)
{
    // abre el archivo de solo lectura
    FILE * fp = fopen(nombrearhcivo,"r");

    if(fp==NULL)
    {
        // el archivo no existe
        return false;
    }

    vaciar(false);

    // leer caracter por caracter
    while(feof(fp)==0)// mientras no se llegue al final
    {
        // agregarle el caracter
        agregar_caracter(fgetc(fp));
    }
    fclose(fp);
    return true;

}



bool ArregloCaracteres::es_igual(const ArregloCaracteres & otro)
{
    if(otro.largo() != m_longitud)
    {
        return false; // son diferentes
    }
    for (int i=0;i<m_longitud ;i++ )
    {
    	if(otro[i]!=m_buffer[i])
    	{
    	    // hay un caracter diferente
    	    return false;
    	}
    }
    return true; // realmente coinciden
}
