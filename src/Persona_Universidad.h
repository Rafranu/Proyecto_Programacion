#pragma once
#include <iostream>
#include <string>
#include "Validaciones.h"
using namespace std;
//Funciones de validacion.
string leerCedulaValida(const string& mensaje);
string leerCadenaNoVacia(const string& mensaje);

//Clase Base.
class Persona_Universidad {
   protected:
    //Atributos. 
	
    string nombre;
    string cedula;

    public:
	
    //Constructores.
    
    Persona_Universidad(string nombre_p = "", string cedula_p = "") : nombre(nombre_p), cedula(cedula_p) {}

    //Funciones.

    string getNombre() const { return nombre; }
    string getCedula() const { return cedula; }

    string setCedula(string& nueva_cedula) { cedula = nueva_cedula; return cedula; }
    string setNombre(string& nuevo_nombre) { nombre = nuevo_nombre; return nombre; }
    
    //Ingresar. 
    void solicitarDatos() {
    nombre=leerCadenaNoVacia("Ingrese el nombre: ");
    cedula=leerCedulaValida("Ingrese la cédula: ");
    }

    //Actualizar. 
    
    void actualizarDatos(string nuevo_nombre,string nueva_cedula) {
        nombre = nuevo_nombre;
        cedula = nueva_cedula;
    }
    
    //Resetear.
    
    void resetearDatos() {
        nombre = "";
        cedula = "";
    }

    //Mostrar.
    
    void mostrarInformacion() {
        cout << "--- Informacion de la Persona ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Cedula: " << cedula << endl;
    }
};
