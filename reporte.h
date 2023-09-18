/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 9/18/2023
* Esta clase define el objeto Reporte que contiene las
* operaciones para crear perfiles de tiendas y 
* calcular su rendimiento utilizadas por el menu main.
*/

#ifndef REPORTE_H_
#define REPORTE_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "tienda.h" //biblioteca con objetos Tienda

using namespace std;

const int MAX = 1000; //constante de tamaño de arreglo

template <class T>
class Reporte {
    //Variables de instancia
    private:
    Tienda * tienda[MAX]; //apuntador para objetos Tienda
    int index;
    void swap(vector<T> &v, int i, int j);

    public:
    //Constructor
    Reporte(): index(0) {};
    
    //Metodos
    //Para crear ejemplos
    void creaEjemplos();

    //Para imprimir objetos (general)
    void imprimeTiendas(vector<T> &v);

    //Para imprimir objetos (ordenados)
    void tiendasPorVentas(vector<T> &v);

    //Para crear objetos
    void agregaTienda(string nombre, int ventas, float ganancia, float conexion, int ica);
};

// para poder ordenar el arreglo
template <class T>
void Reporte<T>::swap(vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

/**
 * imprimeTiendas imprime las tiendas guardadas en el orden
 * en el que se agregaron al programa (sin ordenamiento)
 * utiliza el vector y el index para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método toString().
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::imprimeTiendas(vector<T> &v) {
  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < index; i++)
    cout << v[i].toString();
}

template <class T>
void Reporte<T>::tiendasPorVentas(vector<T> &v) {
  int gap = v.size() / 2;

	while (gap > 0) {
		for(int i = gap; i < v.size(); i++){
			for(int j = i; j >= gap && v[j].get_ventas() < v[j-gap].get_ventas(); j = j-gap){
				swap(v,j,j-gap);
			}
		}
		gap = gap / 2;
	}
}

/**
 * agregaTienda crea un objeto Tienda y lo agrega al arreglo tienda[]
 *
 * crea un objeto Tienda y lo agrega a arreglo de tiendas usando
 * como indice el número de index, el cuál después incrementa en 1.
 *
 * @param 
 * @return
 */
template <class T>
void Reporte<T>::agregaTienda(string nombre, int ventas, float ganancia, float conexion, int ica) {
    //new crea el objeto para usar polimorfismo
    tienda[index] = new Tienda(index, nombre, ventas, ganancia, conexion, ica);
    index++;
}

#endif // REPORTE_H_
