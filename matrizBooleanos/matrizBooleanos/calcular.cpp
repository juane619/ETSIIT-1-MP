#include <iostream>
#include <cstring>
#include "matriz_bit.h"
#include "matriz_operaciones.h"
using namespace std;

int main(int argc, char* argv[]){
    if(argc==1){
        cout << "Especifica alguna de las operaciones a realizar: NOT, TRS, OR, AND." << endl;
    }

    else if(argc >= 2){
        bool op_not, op_trs, op_and, op_or;
        bool unaria= false, binaria= false;
        bool error_lectura=false;
        char *param1;
        char *archivo1, *archivo2;
        MatrizBit res, m1, m2;

        op_not= op_trs= op_and= op_or= false;
        param1 = argv[1];

        unaria = !strcmp(param1, "NOT") || !strcmp(param1, "TRS");
        binaria = !strcmp(param1, "AND") || !strcmp(param1, "OR");

        if(unaria){
            if(argc == 2){
                if(!Leer(cin, m1))
                    error_lectura = true;
            }
            else if(argc == 3){
                archivo1= argv[2];
                if(!Leer(archivo1, m1)){
                cout << "Intentando leer";
                    error_lectura = true;
                }
            }
                if(!strcmp(param1, "NOT"))
                    op_not = true;
                else
                    op_trs = true;
        }
        else if(binaria){
            if(argc== 2){
                if(!Leer(cin, m1) || !Leer(cin, m2))
                    error_lectura = true;
            }
            else if(argc== 3){
                archivo2= argv[2];
                if(!Leer(archivo2, m2) || !Leer(cin, m1))
                    error_lectura = true;
            }
            else if(argc== 4){
                archivo1= argv[2];
                archivo2= argv[3];
                if(!Leer(archivo1, m1) || !Leer(archivo2, m2))
                  error_lectura = true;
            }
            if(!strcmp(param1, "AND"))
                op_and = true;
            else
                op_or = true;
        }

        if(!error_lectura){
            if(op_not)
                Not(res, m1);
            else if(op_trs)
                Traspuesta(res, m1);
            else if(op_and)
                And(res, m1, m2);
            else if(op_or)
                Or(res, m1, m2);

            Escribir(cout, res);
        }
        else
            cout << "Error de lectura de matrices." << endl;

    }
}
