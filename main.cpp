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
#include <vector>
#include <cstring>

#include "tienda.h" //biblioteca con objetos Tienda
#include "reporte.h" //biblioteca con operaciones del menu

using namespace std;

//para utilizar vectores
template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	
    aux << "]";
	return aux.str();
}

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
    Reporte<Tienda> tiendasQro;

    //Declarar vector para realizar operaciones
    vector<Tienda> tiendasList;
    
    //Crear ejemplos
    Tienda itesm_ex = Tienda(0, "ITESM", 253, 1627.87, 8.5, 97);
    Tienda jurica_ex = Tienda(1, "Jurica", 620, 2151.31, 9.6, 82);
    tiendasList.push_back(itesm_ex);
    tiendasList.push_back(jurica_ex);
    cout << endl;

    //Variables para el ciclo
    int opcion = 0;

    //Variables para Tienda
    string nom;
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
                tiendasQro.imprimeTiendas(tiendasList);
                cout << endl;
            break;
            //Opcion 2: Imprime tiendas de mayor a menor
            //filtradas basado en el número de ventas
            case 2:
                tiendasQro.tiendasPorVentas(tiendasList);
                cout << endl;
            break;
            //Opcion 3: Agregar una tienda
            case 3: 
                cout << "Nombre de la tienda: ";
                cin >> nom;
                cout << "Número de ventas: ";
                cin >> ven;
                cout << "Ganancias: ";
                cin >> gan;
                cout << "Indice de Conexión (decimales 1 - 10): ";
                cin >> conex;
                cout << "Indice de ICA (porcentaje completo 1-100): ";
                cin >> ica;
                tiendasQro.agregaTienda(nom, ven, gan, conex, ica);
                cout << endl;
        }
    }
}

