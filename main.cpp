/*
* Proyecto Archivo de Tiendas Starbucks
* Paulina Almada Martínez
* A01710029
* 11/28/2023
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
    cout << "6. Imprime las tiendas en un estado \n";
    cout << "7. Imprime las tiendas que están por encima o por debajo de una meta \n";
    cout << "8. Agrega una tienda \n";
    cout << "9. Generar reporte de todas las tiendas \n";
    cout << "10. Salir \n";

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
    string meta;

    //Variables para Tienda
    string nom;
    string est;
    int ven;
    float gan;
    float conex;
    int ica;

    //Ciclo para que el menu funcione hasta que se escoga salir
    while(opcion < 10 && opcion > -1){
        //Imprime menu
        menu();
        
        cout << "Seleccione un número: ";

        //Pedir al usuario una opción
        cin >> opcion;

        //Acciones para opciones del menu
        switch(opcion){
            //Opción 1: Imprime tiendas
            case 1:
                tiendasMex.imprimeTiendas(tiendasList);
            break;
            //Opción 2: Imprime tiendas de mayor a menor
            //filtradas basado en el número de ventas
            case 2:
                cout << "Nombres de tiendas de mayor a menor número de ventas: " << endl;
                tiendasMex.tiendasPorVentas(tiendasList);
                tiendasMex.guardarArchivo("reporte_ventas.txt", tiendasList);
            break;
            //Opción 3: Imprime tiendas de mayor a menor
            //filtradas basado en el número de ganancia
            case 3:
                cout << "Nombres de tiendas de mayor a menor número de ganancia: " << endl;
                tiendasMex.tiendasPorGanancia(tiendasList);
                tiendasMex.guardarArchivo("reporte_ganancia.txt", tiendasList);
            break;
            //Opción 4: Imprime tiendas de mayor a menor
            //filtradas basado en el índice de conexión
            case 4:
                cout << "Nombres de tiendas de mayor a menor índice de conexión: " << endl;
                tiendasMex.tiendasPorConexion(tiendasList);
                tiendasMex.guardarArchivo("reporte_conexion.txt", tiendasList);
            break;
            //Opción 5: Imprime tiendas de mayor a menor
            //filtradas basado en el índice ICA
            case 5:
                cout << "Nombres de tiendas de mayor a menor índice ICA: " << endl;
                tiendasMex.tiendasPorICA(tiendasList);
                tiendasMex.guardarArchivo("reporte_ica.txt", tiendasList);
            break;
            //Opción 6: Buscar tiendas por estado
            case 6:
                cout << "Ingrese el estado: ";
                cin >> est;
                tiendasMex.buscarTiendasEstado(est);
            break;
            //Opción 7: Buscar tiendas por meta
            case 7:
                cout << "Ingrese el tipo de meta ('ventas', 'ganancia', 'conexion', 'ICA'): ";
                cin >> meta;
                tiendasMex.buscarTiendasPorMeta(meta);
            break;
            //Opción 8: Agregar una tienda
            case 8: 
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
            //Opción 9: Generar archivo de todas las tiendas (sin sortear)
            case 9: 
                cout << "Reporte de todas las tiendas guardadas." << endl;
                tiendasMex.guardarArchivo("reporte_tiendas.txt");
            break;
        }
    }
}
