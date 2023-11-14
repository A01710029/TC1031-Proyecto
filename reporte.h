/*
* Proyecto Archivo de Tiendas Starbucks
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

#include "tienda.h" //biblioteca con objetos Tienda
#include "dlist.h" //biblioteca con estructura de Double Linked List

using namespace std;

template <class T>
class Reporte {
    //Variables de instancia
    private:
    DList<Tienda> tiendas;

    //Para otras funciones
    void swap(DList<T> &list, int i, int j);

    public:
    Reporte() {};
    
    //Metodos
    //Para cargar datos del archivo de datos
    void cargarArchivo(string nomArchivo);

    //Para guardar datos en un archivo nuevo
    void guardarArchivo(string nomArchivo);

    //Para imprimir objetos (general)
    void imprimeTiendas(DList<Tienda> &list);

    //Para imprimir objetos (nombres)
    void imprimeTiendasNombres(DList<Tienda> &list);

    //Para imprimir objetos (ordenados)
    void tiendasPorVentas(DList<Tienda> &list);

    //Para crear objetos
    void agregaTienda(string nombre, string estado, int ventas, float ganancia, float conexion, int ica);

    //Para que el main pueda acceder a las Tiendas
    DList<Tienda> getTiendas() const;
};

//Función para cargar datos desde un archivo
template <class T>
void Reporte<T>::cargarArchivo(string nomArchivo){
    ifstream archivo(nomArchivo);

    if(!archivo.is_open()){
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    //Variables
    string nom;
    string est;
    int ven;
    float gan;
    float conex;
    int ica;

    while (archivo >> nom >> est >> ven >> gan >> conex >> ica){
      agregaTienda(nom, est, ven, gan, conex, ica);
    }

    archivo.close();
}

//Función para guardar datos en un archivo nuevo
template<class T>
void Reporte<T>::guardarArchivo(string nomArchivo){
  ofstream archivo(nomArchivo);

  if(!archivo.is_open()){
    cerr << "No se pudo abrir el archivo para escritura" << endl;
    return;
  }

  DLink<Tienda> *current = tiendas.head;

  while (current != 0){
    archivo << current->value.get_nombre() << " " << current->value.get_estado() << " "
                << current->value.get_ventas() << " " << current->value.get_ganancia() << " "
                << current->value.get_conexion() << " " << current->value.get_ica() << endl;

    current = current->next;
  }

  archivo.close();
}

//Para poder ordenar la lista
template <class T>
void Reporte<T>::swap(DList<T> &list, int i, int j) {
  DLink<T> *p = list.head;
  DLink<T> *q = list.head;

  for(int k = 0; k < i && p != 0; k++){
    p = p->next;
  }

  for(int k = 0; k < j && q != 0; k++){
    q = q->next;
  }

  T temp = p->value;
  p->value = q->value;
  q->value = temp;
}

template <class T>
DList<Tienda> Reporte<T>::getTiendas() const{
  return tiendas;
}

/**
 * imprimeTiendas imprime las tiendas con toda su información
 * de ventas, conexión e ICA
 * recorre la lista imprimiendo cada uno de los objetos con toStringTotal().
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::imprimeTiendas(DList<Tienda> &list) {
  DLink<Tienda> *current = list.head;

  while(current != 0){
    cout << current->value.toStringTotal() << "\n";
    current = current->next;
  }
}

/**
 * imprimeTiendasNombres imprime las tiendas con solo su nombre
 * recorre la lista imprimiendo cada uno de los objetos con toStringNombres().
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::imprimeTiendasNombres(DList<Tienda> &list) {
  DLink<Tienda> *current = list.head;

  while(current != 0){
    cout << current->value.toStringNombres() << "\n";
    current = current->next;
  }
}

//shell sort de tiendas de mayor a menor numero de ventas
template <class T>
void Reporte<T>::tiendasPorVentas(DList<Tienda> &list) {
  int gap = list.get_size() / 2;

	while (gap > 0) {
    DLink<Tienda> *current = list.head;

    while(current != 0){
      DLink<Tienda> *cicloCurrent = current;
      int currentIndex = list.index(cicloCurrent);

      while(cicloCurrent->previous != 0 && cicloCurrent->previous->value.get_ventas() < current->value.get_ventas()){
        int previousIndex = list.index(cicloCurrent->previous);
        swap(list, currentIndex, previousIndex);
        cicloCurrent = cicloCurrent->previous;
      }
      current = current->next;
    }
    gap = gap / 2;
  }

  imprimeTiendasNombres(list);
}

/**
 * agregaTienda crea un objeto Tienda y lo agrega a la lista tiendas
 *
 * crea un objeto Tienda y lo agrega a la lista de Tiendas
 * con el método de insertion de DList
 *
 * @param 
 * @return
 */
template <class T>
void Reporte<T>::agregaTienda(string nombre, string estado, int ventas, float ganancia, float conexion, int ica) {
    Tienda temp_new = Tienda(nombre, estado, ventas, ganancia, conexion, ica);
    tiendas.insertion(temp_new);
}

#endif // REPORTE_H_
