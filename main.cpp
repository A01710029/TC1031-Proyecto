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
    cout << "3. Imprime las tiendas de mayor a menor ganancia \n";
    cout << "4. Imprime las tiendas de mayor a menor índice de conexión \n";
    cout << "5. Imprime las tiendas de mayor a menor índice ICA \n";
    cout << "6. Agrega una tienda \n";
    cout << "7. Salir \n";

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
    while(opcion < 8 && opcion > -1){

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
                tiendasMex.guardarArchivo("reporte_ventas.txt", tiendasList);
            break;
            //Opcion 3: Imprime tiendas de mayor a menor
            //filtradas basado en el número de ganancia
            case 3:
                cout << "Nombres de tiendas de mayor a menor número de ganancia: " << endl;
                tiendasMex.tiendasPorGanancia(tiendasList);
                tiendasMex.guardarArchivo("reporte_ganancia.txt", tiendasList);
            break;
            //Opcion 4: Imprime tiendas de mayor a menor
            //filtradas basado en el indice de conexion
            case 4:
                cout << "Nombres de tiendas de mayor a menor índice de conexión: " << endl;
                tiendasMex.tiendasPorConexion(tiendasList);
                tiendasMex.guardarArchivo("reporte_conexion.txt", tiendasList);
            break;
            //Opcion 5: Imprime tiendas de mayor a menor
            //filtradas basado en el indice ICA
            case 5:
                cout << "Nombres de tiendas de mayor a menor índice ICA: " << endl;
                tiendasMex.tiendasPorICA(tiendasList);
                tiendasMex.guardarArchivo("reporte_ica.txt", tiendasList);
            break;
            //Opcion 6: Agregar una tienda
            case 6: 
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
            break;
            //Opcion 7: Generar archivo de todas las tiendas (sin sortear)
            case 7: 
                cout << "Reporte de todas las listas generado." << endl;
                tiendasMex.guardarArchivo("reporte_tiendas.txt");
            break;
        }
    }
}
