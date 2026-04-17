#include <iostream>
#include <string>
#include "LZ78_ALL.h"
#include "RLE_ALL.h"
#include "ENCRI_DESIN.h"
#include "Archivos.h"
using namespace std;

int main() {
    int opcion;
    int bits;
    char archivoEntrada[100];
    char archivoSalida[100];

    cout << "Presione alguno de los siguientes numeros para empezar el programa: " << endl;
    cout << "1. RLE" << endl;
    cout << "2. LZ78" << endl;
    cin >> opcion;

    while(true){
        cout<<"Ingrese la cantidad de bits a rotar los datos encriptados (de 1 a 7): "<<endl;
        cin>>bits;
        if(bits>0 && bits<8){
            break;
        }
        else{
            cout<<"Valor invalido. "<<endl;
        }
    }


    cout << "Nombre del archivo de entrada: ";
    cin >> archivoEntrada;

    cout << "Nombre del archivo de salida: ";
    cin >> archivoSalida;

    try {
        switch (opcion) {
        case 1:
            cout << "Usando RLE" << endl;
            integrador_RLE(archivoEntrada, archivoSalida, bits);
            break;

        case 2:
            cout << "Usando LZ78:" << endl;
            integrador_LZ78(archivoEntrada, archivoSalida, bits);
            break;

        default:
            cout << "Opción inválida" << endl;
        }
    } catch (const char* e) {
        cerr << "ERROR: " << e << endl;
        return 1;
    }

    return 0;
}
