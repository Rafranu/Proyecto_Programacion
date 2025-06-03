#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
#include "Profesor.h"
using namespace std;




class Asignatura :virtual public Estudiante, virtual public Profesor {

    string materias;

public:
    
    // Constructor de Asignatura: 
    
    Asignatura(string nombre_p = "", string cedula_p = "", string seccion_e = "", string materias_asig = ""): Persona_Universidad(nombre_p, cedula_p), Estudiante(nombre_p, cedula_p, seccion_e), Profesor(nombre_p, cedula_p),materias(materias_asig) {}
    
    string get_materia(){return materias;}
    //Ingresar. 

    void ingresar() {
        Estudiante::Persona_Universidad::solicitarDatos();
        cout << "Seccion del Estudiante (si aplica): ";
        string temp_seccion;
        getline(cin, temp_seccion);
        Estudiante::setSeccion(temp_seccion);
    }

    //Actualizar.
    void actualizar(string& nuevo_nombre,string& nueva_cedula) { 
        Estudiante::Persona_Universidad::actualizarDatos(nuevo_nombre, nueva_cedula);
    }

    //Resetear.
    void resetear() {
        Persona_Universidad::resetearDatos();
        materias = "";
        cout << "Datos y materias reseteados." << endl;
    }

    //Mostrar.
    void mostrar() {
        cout << "Materias: " << (materias.empty() ? "(Ninguna)" : materias) << endl;
        cout << "------------------------------------" << endl;
    }

    // Llenar materia del profesor.
    void agregar_materias(){
        string temp_materia;
        cout<<"Materia (single): ";
       
        getline(cin,temp_materia);
        materias = temp_materia;
        cout << "Materia asignada: " << materias << endl;
    }

    // Llenar materias del estudiante.
    void llenar_materias_estudiante() {
        materias = "";
        cout << "Ingrese las 6 materias para el Estudiante:" << endl;
        for (int i = 0; i < 6; ++i) {
            string temp_materia;
            cout << "Materia " << (i + 1) << ": ";
            if (i == 0) {
                cin.ignore();
            }
            getline(cin, temp_materia);
            if (!materias.empty()) {
                materias += ", ";
            }
            materias += temp_materia;
        }
        cout << "Las 6 materias han sido registradas." << endl;
    }

};