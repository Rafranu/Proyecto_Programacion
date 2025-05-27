#pragma once
#include <iostream>
#include <string>
using namespace std;

//Clase Base.
class Persona_Universidad {
	
	//Atributos. 
	
    string nombre;
    string cedula;

public:
	
    //Constructores.
    
    Persona_Universidad(string nombre_p = "", string cedula_p = "") : nombre(nombre_p), cedula(cedula_p) {}

    //Funciones.

    string getNombre() const { return nombre; }
    string getCedula() const { return cedula; }

    //Ingresar. 
    
    void solicitarDatos() {
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Cedula: ";
        getline(cin, cedula);
    }

    //Actualizar. 
    
    void actualizarDatos(string& nuevo_nombre,string& nueva_cedula) {
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
