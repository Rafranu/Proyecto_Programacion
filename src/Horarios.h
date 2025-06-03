
#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;
const int capacidad_seccion = 3;




class Horario :virtual public Estudiante {
    // Atributos.
    protected:
    int dias = 5;
    int hora = 4;

    // Definir dias de las semanas.
    string dias_semana[5] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES"};

    // Definir horas de clases.
    string horas_clase[4] = {"8-9", "9-10", "10-11", "11-12"};

    // Horario individual del estudiante.
    int horario_contenido[5][4];

    // Matriz Final donde se acumulará la combinación.
    int horario_final_combinado[5][4];
    int capacidad_seccion_local; 

public:
  
    Horario(string nombre_h = "", string cedula_h = "", string seccion_h = ""): Estudiante(nombre_h, cedula_h, seccion_h), capacidad_seccion_local( capacidad_seccion) {
        for (int i = 0; i < dias; ++i) {
            for (int j = 0; j < hora; ++j) {
                horario_final_combinado[i][j] = 0;
            }
        }
    }

    // Setter para la capacidad de la sección local
    void setCapacidadSeccion(int cap) {
        capacidad_seccion_local = cap;
    }

    const int (&getHorarioFinalCombinado() const)[5][4] {
    return horario_final_combinado;
}
 void setHorarioValor(int i, int j, int valor) { horario_final_combinado[i][j] = valor; }

    void funcion_horario_estudiante(Estudiante estudiante) {

        for (int i = 0; i < dias; ++i) {
            for (int j = 0; j < hora; ++j) {
                horario_final_combinado[i][j] = 0;
            }
        }

       
       
            cout << "\n-------------------Llenado de horario para Estudiante " <<estudiante.getNombre() << "----------------------" << endl;
            cout << "Ingrese 1, si esta ocupado por una materia, 0 si esta libre :)" << endl;

            for (int i = 0; i < dias; i++) {
                cout << "\n--- " << dias_semana[i] << " ---" << endl;
                for (int j = 0; j < hora; j++) {
                    cout << "  Hora " << horas_clase[j] << ": ";
                    cin >> horario_contenido[i][j];
                    // Validacion.
                    while (horario_contenido[i][j] != 1 && horario_contenido[i][j] != 0) {
                        cout << "Entrada invalida. 1 = Ocupado, 0 = Libre" << endl;
                        cout << "  Hora " << horas_clase[j] << ": ";
                        cin >> horario_contenido[i][j];
                    }
                    // Logica de combinacion.
                    if (horario_contenido[i][j] == 1) {
                        horario_final_combinado[i][j] = 1;
                    }
                }
            }
            

            // IMPRIMIR HORARIO INDIVIDUAL.
            cout << "\n-------------------HORARIO INGRESADO (Estudiante " << estudiante.getNombre() << ")------------------- " << endl;
            cout << "------------------------------------------------------" << endl;

            // horas.
            cout << "Dia/Hora\t";
            for (int k = 0; k < hora; k++) {
                cout << horas_clase[k] << "\t";
            }
            cout << endl;
            cout << "------------------------------------------------------" << endl;

            // Imprimir.
            for (int i = 0; i < dias; i++) {
                cout << dias_semana[i] << "\t";
                for (int j = 0; j < hora; j++) {
                    cout << horario_contenido[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "------------------------------------------------------" << endl;
        

       
    }

    // Nueva función para mostrar el horario final combinado.
    void mostrarHorarioFinalCombinado(const Estudiante& estudiante) const { 
        cout << "\n\n-------------HORARIO FINAL COMBINADO DE ESTUDIANTES (Seccion: " << estudiante.getSeccion() << ")---------------- " << endl;
        cout << "------------------------------------------------------" << endl;

        // Imprimir las horas de clase en la cabecera
        cout << "Dia/Hora\t";
        for (int k = 0; k < hora; k++) {
            cout << horas_clase[k] << "\t";
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;

        // Imprimir la matriz final del horario
        for (int i = 0; i < dias; i++) {
            cout << dias_semana[i] << "\t";
            for (int j = 0; j < hora; j++) {
                cout << horario_final_combinado[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
};