#include <iostream>
#pragma once
#include <string>
#include "Persona_Universidad.h"


using namespace std;
//Profesor.
class Profesor : virtual public Persona_Universidad { 

public:
    Profesor(string nombre_prof = "", string cedula_prof = "") : Persona_Universidad(nombre_prof, cedula_prof) {}

    void mostrarProfesorDetalle(){ 
        Persona_Universidad::mostrarInformacion();
        cout << "Rol: Profesor" << endl;
    }

    
    void impartirClase(string& nombre_clase){ 
        cout << getNombre() << " esta impartiendo la clase: " << nombre_clase << endl;
    }
};