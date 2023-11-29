/*
* Proyecto Archivo de Tiendas Starbucks
* Paulina Almada Martínez
* A01710029
* 11/28/2023
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
    
    //Métodos
    //Para cargar datos del archivo de datos
    void cargarArchivo(string nomArchivo);

    //Para guardar datos en un archivo nuevo
    void guardarArchivo(string nomArchivo);
    void guardarArchivo(string nomArchivo,DList<Tienda> &list);

    //Para imprimir objetos (general)
    void imprimeTiendas(DList<Tienda> &list);

    //Para imprimir objetos (nombres)
    void imprimeTiendasNombres(DList<Tienda> &list);

    //Para imprimir objetos (ordenados)
    void tiendasPorVentas(DList<Tienda> &list);
    void tiendasPorGanancia(DList<Tienda> &list);
    void tiendasPorConexion(DList<Tienda> &list);
    void tiendasPorICA(DList<Tienda> &list);

    //Para buscar tiendas
    //Para consultar tiendas por estado
    void buscarTiendasEstado(string estado);

    //Para consultar tiendas que sean mayor / menor a una meta (cualquier atributo)
    void buscarTiendasPorMeta(string metaTipo);

    //Para crear objetos
    void agregaTienda(string nombre, string estado, int ventas, float ganancia, float conexion, int ica);

    //Para que el main pueda acceder a las Tiendas
    DList<Tienda> getTiendas() const;
};

/**
 * cargarArchivo carga los archivos del archivo txt con los datos de las Tiendas
 * 
 * Recorre el archivo guardando cada objeto en la 
 * lista doblemente ligada con agregaTienda()
 *
 * @param
 * @return
 */
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

/**
 * guardarArchivo guarda los datos de la lista doblemente ligada en un archivo txt
 * 
 * Recorre la lista doblemente ligada guardando cada objeto en el archivo
 *
 * @param 
 * @return
 */
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

/**
 * guardarArchivo guarda los datos de la lista doblemente ligada en un archivo txt
 * 
 * Recorre la lista doblemente ligada (la lista previamente ordenada) 
 * guardando cada objeto en el archivo
 * 
 * Recibe el nombre para el archivo y una lista de Tiendas ordenadas
 *
 * @param 
 * @return
 */
template<class T>
void Reporte<T>::guardarArchivo(string nomArchivo, DList<Tienda>& list){
  ofstream archivo(nomArchivo);

  if(!archivo.is_open()){
    cerr << "No se pudo abrir el archivo para escritura" << endl;
    return;
  }

  DLink<Tienda> *current = list.head;

  while (current != 0){
    archivo << current->value.get_nombre() << " " << current->value.get_estado() << " "
                << current->value.get_ventas() << " " << current->value.get_ganancia() << " "
                << current->value.get_conexion() << " " << current->value.get_ica() << endl;

    current = current->next;
  }

  archivo.close();
}

/**
 * swap es una función interna para facilitar el Shell Sort del programa
 * 
 * Maneja los apuntadores al cambiar de lugar dos elementos 
 * de la lista doblemente ligada
 *
 * @param
 * @return
 */
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
 * de ventas, conexión e ICA (los atributos del objeto)
 * 
 * Recorre la lista imprimiendo cada uno de los objetos con toStringTotal().
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
 * 
 * Recorre la lista imprimiendo cada uno de los objetos 
 * con toStringNombres().
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

/**
 * tiendasPorVentas ordena las Tiendas de mayor a menor número de
 * ventas utilizando el algoritmo de ordenamiento Shell Sort
 * e imprimiendo la lista ordenada con imprimeTiendasNombres()
 *
 * @param
 * @return
 */
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
 * tiendasPorGanancia ordena las Tiendas de mayor a menor número de
 * ganancia utilizando el algoritmo de ordenamiento Shell Sort
 * e imprimiendo la lista ordenada con imprimeTiendasNombres()
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::tiendasPorGanancia(DList<Tienda> &list) {
  int gap = list.get_size() / 2;

	while (gap > 0) {
    DLink<Tienda> *current = list.head;

    while(current != 0){
      DLink<Tienda> *cicloCurrent = current;
      int currentIndex = list.index(cicloCurrent);

      while(cicloCurrent->previous != 0 && cicloCurrent->previous->value.get_ganancia() < current->value.get_ganancia()){
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
 * tiendasPorConexion ordena las Tiendas de mayor a menor índice de
 * conexión utilizando el algoritmo de ordenamiento Shell Sort
 * e imprimiendo la lista ordenada con imprimeTiendasNombres()
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::tiendasPorConexion(DList<Tienda> &list) {
  int gap = list.get_size() / 2;

	while (gap > 0) {
    DLink<Tienda> *current = list.head;

    while(current != 0){
      DLink<Tienda> *cicloCurrent = current;
      int currentIndex = list.index(cicloCurrent);

      while(cicloCurrent->previous != 0 && cicloCurrent->previous->value.get_conexion() < current->value.get_conexion()){
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
 * tiendasPorICA ordena las Tiendas de mayor a menor índice de
 * ICA utilizando el algoritmo de ordenamiento Shell Sort
 * e imprimiendo la lista ordenada con imprimeTiendasNombres()
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::tiendasPorICA(DList<Tienda> &list) {
  int gap = list.get_size() / 2;

	while (gap > 0) {
    DLink<Tienda> *current = list.head;

    while(current != 0){
      DLink<Tienda> *cicloCurrent = current;
      int currentIndex = list.index(cicloCurrent);

      while(cicloCurrent->previous != 0 && cicloCurrent->previous->value.get_ica() < current->value.get_ica()){
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
 * buscarTiendasEstado busca todas las Tiendas que se ubican
 * en un estado dado por el usuario
 * 
 * Recorre la lista de Tiendas, comparando el valor de estado
 * al valor dado por el usuario y las imprime con imprimeTiendas()
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::buscarTiendasEstado(string estado){
  DList<Tienda> tiendasEnEstado;

  DLink<Tienda> *current = tiendas.head;

  while (current != 0){
    if(current->value.get_estado() == estado) {
      tiendasEnEstado.insertion(current->value);
    }
    current = current->next;
  }

  if(tiendasEnEstado.get_size() == 0){
    cout << "No se encontraron tiendas en ese estado" << endl;
  } else {
    cout << "Tiendas en el estado \"" << estado << "\":\n";
    imprimeTiendas(tiendasEnEstado);
  }
}

/**
 * buscarTiendasPorMeta busca todas las Tiendas que estén por encima
 * o por debajo de una meta definida por el usuario en un atributo
 * (ventas, ganancia, conexion o ICA) definido por el usuario
 * 
 * El usuario define el atributo, la meta, si se quieren las tiendas por encima
 * o por debajo de la meta y se recorre la lista de Tiendas, comparando el valor de 
 * al valor dado por el usuario y las imprime con imprimeTiendas()
 *
 * @param
 * @return
 */
template <class T>
void Reporte<T>::buscarTiendasPorMeta(string metaTipo) {
    float meta;
    cout << "Ingrese la meta de " << metaTipo << ": ";
    cin >> meta;

    char direccion;
    cout << "Ingrese 'a' para tiendas con puntaje arriba de la meta o 'b' para tiendas abajo: ";
    cin >> direccion;

    DList<Tienda> tiendasCumplenMeta;

    DLink<Tienda> *current = tiendas.head;

    while (current != 0) {
        float currentScore = 0;

        if (metaTipo == "ventas") {
            currentScore = static_cast<float>(current->value.get_ventas());
        } else if (metaTipo == "ganancia") {
            currentScore = current->value.get_ganancia();
        } else if (metaTipo == "conexion") {
            currentScore = current->value.get_conexion();
        } else if (metaTipo == "ICA") {
            currentScore = static_cast<float>(current->value.get_ica());
        }

        if ((direccion == 'a' && currentScore >= meta) || (direccion == 'b' && currentScore <= meta)) {
            tiendasCumplenMeta.insertion(current->value);
        }
        current = current->next;
    }

    if (tiendasCumplenMeta.get_size() == 0) {
        cout << "No se encontraron tiendas que cumplan con la meta de " << metaTipo << ".\n";
    } else {
        cout << "Tiendas que cumplen con la meta de " << metaTipo << ":\n";
        imprimeTiendas(tiendasCumplenMeta);
    }
}

/**
 * agregaTienda crea un objeto Tienda y lo agrega a la lista tiendas
 *
 * Crea un objeto Tienda y lo agrega a la lista de Tiendas
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
