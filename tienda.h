/*
* Proyecto Archivo de Casos
* Paulina Almada Martínez
* A01710029
* 9/18/2023
* Esta clase define el objeto Tienda que contiene la
* información sobre las tiendas Starbucks
*/

#ifndef TIENDA_H_
#define TIENDA_H_

#include <string>
#include <sstream>

using namespace std;
//Declaración de clase Tienda
class Tienda {
    //Variables de instancia
    protected:
    //
    int id;
    string nombre;
    int ventas;
    float ganancia;
    float conexion; // números del 1 - 10
    int ica; // porcentajes del 1 - 100

    //Métodos
    public:
    //Constructores
    //Default
    Tienda(): id(0), nombre(""), ventas(0), ganancia(0.0), conexion (0.0), ica (0) {};

    //Con parametros
    Tienda(int id_num, string nom, int ven, float gan, float conex, int ica_num): \
    id(id_num), nombre(nom), ventas(ven), ganancia(gan), conexion(conex), ica(ica_num) {};

    //Metodos
        //Getters
        int get_id(){
            return id;
        }

        string get_nombre(){
            return nombre;
        }

        int get_ventas(){
            return ventas;
        }

        float get_ganancia(){
            return ganancia;
        }

        float get_conexion(){
            return conexion;
        }

        int get_ica(){
            return ica;
        }

        //possibly add setters to modify (most) values ?

        //Otras funciones
        string toString();
};

/**
* toString convierte atributos a string
* concatena todos los valores de los atributos en un string
* para imprimirlos
*
* @param
* @return string con los valores y texto
*/

//sobreescritura de toString en Criminal (padre)
string Tienda::toString(){
    stringstream aux;
    
    aux << "Nombre: " << nombre << "\n" << "Ventas: " << ventas << "\n" \
    "Ganancia: " << ganancia << "\n" << "Indice de Conexion: " << conexion << "\n" \
    "Indice de ICA: " << ica << "\n";
    
    return aux.str();
}

#endif // TIENDA_H_
