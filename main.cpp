/*
* Proyecto Archivo de Tiendas Starbucks
* Paulina Almada Martínez
* A01710029
* 9/18/2023
* Un programa para guardar y comparar el desempeño
* de las tiendas Starbucks de un distrito
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>

#include "tienda.h" //biblioteca con objetos Tienda
#include "reporte.h" //biblioteca con operaciones del menu
#include "dlist.h" //biblioteca con estructura de Double Linked List

using namespace std;

//Menu
void menu(){
    //Imprime las opciones del programa
    cout << "Menu:\n";
    cout << "1. Imprime las tiendas guardadas \n";
    cout << "2. Imprime las tiendas de mayor a menor ventas \n";
    cout << "3. Agrega una tienda \n";
    cout << "4. Salir \n";

    cout << endl;
}

int main(int argc, char * argv[]) {
    //Declarar objeto Reporte para acceder operaciones
    Reporte<Tienda> tiendasMex;

    //Cargar datos del archivo para popular lista
    tiendasMex.cargarArchivo("datos_tiendas.txt");

    DList<Tienda> tiendas = tiendasMex.getTiendas();
    DList<Tienda> tiendasList(tiendas);

    //Variables para el ciclo
    int opcion = 0;

    //Variables para Tienda
    string nom;
    string est;
    int ven;
    float gan;
    float conex;
    int ica;

    //Imprime menu
    menu();

    //ciclo para que el menu funcione hasta que se escoga salir
    while(opcion < 4 && opcion > -1){

        cout << "Seleccione un número: ";

        //Pedir al usuario una opcion
        cin >> opcion;

        //Acciones para opciones del menu
        switch(opcion){
            //Opcion 1: Imprime tiendas
            case 1:
                tiendasMex.imprimeTiendas(tiendasList);
            break;
            //Opcion 2: Imprime tiendas de mayor a menor
            //filtradas basado en el número de ventas
            case 2:
                cout << "Nombres de tiendas de mayor a menor número de ventas: " << endl;
                tiendasMex.tiendasPorVentas(tiendasList);
            break;
            //Opcion 3: Agregar una tienda
            case 3: 
                cout << "Nombre de la tienda: ";
                cin >> nom;
                cout << "Estado: ";
                cin >> est;
                cout << "Número de ventas: ";
                cin >> ven;
                cout << "Ganancias: ";
                cin >> gan;
                cout << "Indice de Conexión (decimal 1 - 10): ";
                cin >> conex;
                cout << "Indice de ICA (porcentaje sin decimal 1-100): ";
                cin >> ica;
                tiendasMex.agregaTienda(nom, est, ven, gan, conex, ica);
                cout << endl;
        }
    }
}
