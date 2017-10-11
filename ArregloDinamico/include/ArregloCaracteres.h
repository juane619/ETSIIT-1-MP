#ifndef ARREGLOCARACTERES_H
#define ARREGLOCARACTERES_H


/// Clase para manipular texto en arreglos de caracteres
/*!
En c++, las cadenas de texto se representan con arreglos de caracteres. Estos caracteres son representados en memoria como valores enteros ASCII.
Vease http://es.wikipedia.org/wiki/ASCII
Los arreglos de caracteres deben tener en la ultima posición el caracter nulo (0 en código ASCII).
Un arreglo como el siguiente:
 \code
 char cadena[200];
 cadena[0] = 0;
 \endcode

Es equivalente a una cadena vacia, a pesar de que tiene asignado un buffer de memoria de 200. El caracter 0 marca el final de esa cadena.
Una constante como "" es también equivalente a una cadena vacia de longitud 0.

En el siguiente ejemplo se representa una cadena de texto de 5 caracteres:
 \code
 char cadena[100] = {'c', 'a', 'm', 'p', 'o', 0};
 \endcode

Notese que cada letra está delimitada por comillas simples ('). Y aunque la palabra "campo" tiene 5 caracteres, el arreglo se asignado con una mayor capacidad de caracteres.
En el siguiente fragmento, se modifica el anterior arreglo para componer una cadena mas larga:
 \code
 cadena[5] = ' ';
 cadena[6] = 's';
 cadena[7] = 'a';
 cadena[7] = 'n';
 cadena[7] = 't';
 cadena[7] = 'o';
 cadena[7] = 0;// fin de cadena
 \endcode

La forma anterior de declarar arreglos limita el tamaño del arreglo de forma predefinida sin posibilidad de cambiar sus dimensiones.
Por eso existe un mecanismo para declarar arreglos dinámicos cuyo tamañó no es constante sino mas bien depende de algún parametro o variable:
 \code
 char * cadena_dinamica = NULL; // arreglo vacio.

 int cantidad = 0;

 //obtenemos un valor de cantidad capturado de consola
 cout<< "Por favor digite el tamaño del arreglo ";
 cin>>cantidad;

 // creamos el arreglo dinámico con el parametro capturado
 cadena_dinamica = new char[cantidad];
 \endcode

En el codigo anterior creamos un arreglo dinámico cuyo numéro de elementos es especificado como usuario. Notese que cadena dinámica se declara como un apuntador de memoria, el cual hará referencia al espacio de memorio creado con la instrucción "new char[cantidad]".

Sin embargo, se requiere liberar la memoria asignada del arreglo cuando finalize nuestra aplicación o cuando el arreglo no tenga más utilidad. Recurrimos entonces a la siguiente rutina de liberación de recursos:
 \code
 delete [] cadena_dinamica; // liberamos la memoria de la cadena
 cadena_dinamica = NULL;
 \endcode

Esta clase ArregloCaracteres tiene mecanismos para manipular una cadena con un tamaño variable de forma segura y controlada. Como invariante se tiene que la cadena de este objeto siempre estará terminada en null

*/
class ArregloCaracteres
{
protected:
    char * m_buffer;///< Arreglo dinámico de caracteres
    int m_longitud;///< Longitud de la cadena de caracteres
    int m_capacidad;///< Capacidad de la memoria del arreglo de caracteres

public:
    /// Constructor simple
    ArregloCaracteres();

    /// Constructor con parametro de capacidad inicial
    /*!
    \param capacidad_inicial numero de elementos reservados en el buffer de memoria
    */
    ArregloCaracteres(int capacidad_inicial);

    /// Constructor con parametro de asignación de cadena
    /*!
    \param constante_cadena cadena constante de caracteres como "esta cadena entre corchetes"
    */
    ArregloCaracteres(const char * constante_cadena);

    /// Constructor copia, el que hace posible asignar con =
    /*!
    \param otro Otro objeto del cual asignaremos la cadena
    */
    ArregloCaracteres(const ArregloCaracteres & otro);

    /// Destructor, se encarga de limpiar la memoria despues de utilizar este objeto
    ~ArregloCaracteres();

    /// obtiene una referencia constante a la cadena
    const char * c_ptr() const;

    /// obtiene una referencia a la memoria de esta cadena
    char * ptr();

    /// largo de la cadena
    int largo() const;

    bool esta_vacia() const;


    /// obtienen la cantidad de memoria reservada
    int memoria_reservada() const;

    /// función para asignar de un objeto
    void asignar(const ArregloCaracteres & obj);

    /// función para asignar de una constante de cadena con terminacion 0
    void asignar(const char *  cad);



    /// función para copiar n caracteres de la cadena
    void asignar(const char *  cad, int num_caracteres);

    /// función para copiar n caracteres de la cadena en alguna posicion de la cadena de este objeto
    void copiar_cadena(int posicion_destino, const char *  cad, int num_caracteres);

    /// reserva la memoria para esta cadena
    /*!
    Solo asigna la memoria, pero no cambia el tamaño de la cadena
    */
    void reservar_memoria(int num_caracteres);

    /// Cambia la longitud de la cadena, y reserva memoria suficiciente
    /*!
    La cadena es redimensionada, y el caracter final se asignará a null
    Rellena con espacios el espacio asignado
    */
    void cambiar_longitud(int newlongitud, char caracter_relleno = ' ');

    /// Crea una cadena vacia, y opcionalmente libera la memoria
    void vaciar(bool limpiar_memoria = true);

    /// anexa una cadena
    void concatenar(const char * cad);
    /// anexa la cadena del objeto
    void concatenar(const ArregloCaracteres & otro);

    /// anexa la cadena copiando un cierto numero de caracteres
    void concatenar(const char *  cad, int num_caracteres);

    /// agrega un caracter al final
    void agregar_caracter(char c);

    /// inserta un caracter en la posicion dada
    void insertar_caracter(char c, int posicion);

    /// inserta un objeto de cadena en la posicion dada
    void insertar_cadena(const ArregloCaracteres & obj, int posicion);

    /// inserta una cadena terminada en null en la posicion dada
    void insertar_cadena(const char * cad, int posicion);
    /// inserta una cadena con n caracteres en la posicion dada
    void insertar_cadena(const char * cad, int ncaracteres, int posicion);

    /// ELimina una cantidad de caracteres a partir de la posicion especificada
    void eliminar_caracteres(int posicion, int cantidad);

    /// Busca la posicion del caracter encontrado
    /*!
    \return Un numero positivo indicando la posicion del caracter encontrado, o -1 si no existe ninguno
    */
    int encontrar_caracter(char c, int posicion_inicial = 0);


    /// Busca la posicion del caracter encontrado que coincida con cualquier caracter en la lista
    /*!
    \return Un numero positivo indicando la posicion del caracter encontrado, o -1 si no existe ninguno
    */
    int encontrar_cualquiera(const char * conjunto_caracteres, int posicion_inicial = 0);


    /// Busca la posicion del caracter encontrado que no coincida con cualquier caracter en la lista
    /*!
    \return Un numero positivo indicando la posicion del caracter encontrado, o -1 si no existe ninguno
    */
    int encontrar_ninguno(const char * conjunto_caracteres, int posicion_inicial = 0);



    /// Busca la posicion donde se encontro la cadena especificada
    /*!
    \return Un numero positivo indicando la posicion encontrada, o -1 si no existen coincidencias
    */
    int encontrar_palabra(const char * palabra, int posicion_inicial = 0);


    /// Reemplaza cualquier caracter del conjunto
    /*!
    \return retorna el numero de reemplazos
    */
    int reemplazar_cualquiera(char reemplazo, const char * conjunto_caracteres, int posicion_inicial = 0);

    /// Copia la cadena reemplazando la coincidencia especificada
    /*!
    \return retorna el numero de reemplazos
    */
    int reemplazar_palabra(const char * fuente, const char * palabra_a_reemplazar, const char * reemplazo);

    /// Lee la cadena de archivo
    bool leer_de_archivo(const char * nombrearhcivo);

    /// compara con otro texto
    bool es_igual(const ArregloCaracteres & otro);


    /// Funciones de utilidad
    ///@{

    /// Esta funcion puede utilizarse sin ninguna instancia
    static int calcular_longitud_cadena(const char * cad);
    ///@}


    /// Operadores para manejar este objeto como un arreglo
    ///@{

    /// para obtener caracter
    char operator[](int posicion) const;

    /// para asignar caracter
    char & operator[](int posicion);

    ArregloCaracteres & operator=(const char * cad);

    ///@}


};





#endif // ARREGLOCARACTERES_H
