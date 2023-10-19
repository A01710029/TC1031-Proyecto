/*
* Proyecto Archivo de Tiendas Starbucks
* Paulina Almada Martínez
* A01710029
* 9/18/2023
* Esta clase define las funciones necesarias para manejar
* la estructura de las listas doblemente ligadas.
*/

#ifndef DLIST_H_
#define DLIST_H_

#include <iostream>
#include <sstream>

using namespace std;

template <class T> class DList;

/* Clase Link */
template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

public:
	T	    value;
	DLink<T> *previous;
	DLink<T> *next;
	DLink<T> *element;

	friend class DList<T>;
};

//Constructores
template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

/* Clase Double Linked List */
template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&);
	~DList();

    void addFirst(T);
    bool empty() const;
    void clear();

    void insertion(T val);
    T search(T val);
    void update(T pos, T val);
    T deleteAt(T pos);
	int index(DLink<T> *element) const;

    string toString() const;

    int get_size();

	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;
};

template <class T>
DList<T>::DList(const DList<T>& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    
    // Perform a deep copy of the list
    DLink<T> *current = other.head;
    
    while (current != nullptr) {
        insertion(current->value);
        current = current->next;
    }
}

//Constructor y destructor
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
int DList<T>::get_size() {
    return size;
}

//Clases para procesos internos
template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next; 
		delete p; 
		p = q;
	}

	head = 0; 
	tail = 0;
	size = 0;
}

template <class T>
void DList<T>::addFirst(T val){
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty()) { 
		head = newLink;
		tail = newLink;
	} else {
		newLink->next = head;
		head->previous = newLink; 
		head = newLink;
	}
	size++;
}

template <class T>
string DList<T>::toString() const {
	stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

// Insertar un elemento 
template <class T>
void DList<T>::insertion(T val){
    DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty()) {
		addFirst(val);
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

// Encontrar el elemento y devolver su posición
// Devolver -1 si no se encuentra
template <class T>
T DList<T>::search(T val){
    DLink<T> *p;
    int index = 0;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return index;
		} 
		p = p->next;
        index++;
	}
	return -1;
}

// Reemplazar un elemento en una posición específica con el valor dado
template <class T>
void DList<T>::update(T pos, T val){
    DLink<T> *p;
    int index = 0;

	p = head;
	while (p != 0) {
		if (index == pos) {
			p->value = val;
		} 
		p = p->next;
        index++;
	}
}

// Borrar un elemento segun su posición
// Regresar el valor numérico eliminado
template <class T>
T DList<T>::deleteAt(T pos){ 
    T  val;
    int index = 0;

    DLink<T> *p = head;
	DLink<T> *prev = 0;

	while (p != 0 && index != pos) {
		prev = p;
		p = p->next;
		index++;
	}

	val = p->value;

	if(prev == 0){
		head = p->next;
	} else {
		prev->next = p->next;
	}

	if(p->next != 0){
		p->next->previous = prev;
	} else {
		tail = prev;
	}

	delete p;
	size--;
    
	return val;
}

//Regresar la posición de un valor en la lista
template <class T>
int DList<T>::index(DLink<T> *element) const {
  int index = 0;
  DLink<T> *current = head;

  while (current != nullptr) {
    if (current == element) {
      return index; 
    }
    current = current->next;
    index++;
  }

  return -1;
}

#endif // DLIST_H_
