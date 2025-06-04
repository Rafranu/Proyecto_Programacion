#pragma once
#include <iostream>
#include <string>
#include "Persona_Universidad.h"

using namespace std;



class Estudiante : virtual public Persona_Universidad { 
protected:
    //Atributos. 
    
    string seccion;

public:
	
	//Constructor. 
	Estudiante(string nombre_e = "", string cedula_e = "", string seccion_e = "") : Persona_Universidad{nombre_e, cedula_e}, seccion(seccion_e) {}


    string getSeccion() const { return seccion; }

    
    void setSeccion(string& nueva_seccion) {
        seccion = nueva_seccion;
    } 
   \
    
    
    void mostrarEstudianteDetalle(){
        Persona_Universidad::mostrarInformacion();
        cout << "Seccion de Estudiante: " << seccion << endl;
    }
    
};
