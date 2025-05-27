
#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;
const int capacidad_seccion = 3;




class Horario: public Estudiante{

    //Atributos.

    int dias = 5;
    int hora = 4;

    //Definir dias de las semanas.
    string dias_semana[5] = {"LUNES","MARTES","MIERCOLES","JUEVES","VIERNES"};

    //Definir horas de clases.
    string horas_clase[4] = {"8-9","9-10","10-11","11-12"}; 

    //Horario.
    int horario_contenido[5][4];

    // Matriz Final donde se acumulará la combinación.
    int horario_final_combinado[5][4];

public:
    // Constructor de Horario: llama al constructor de Estudiante
    Horario(string nombre_h = "", string cedula_h = "", string seccion_h = ""): Estudiante(nombre_h, cedula_h, seccion_h) {}

 
    void funcion_horario_estudiante(){

        for(int i = 0; i < dias; ++i) {
            for(int j = 0; j < hora; ++j) {
                horario_final_combinado[i][j] = 0; 
            }
        }

        
        for (int c = 1; c <= capacidad_seccion; ++c) {
            cout << "\n-------------------Llenado de horario para Estudiante " << c << "----------------------" << endl;
            cout << "Ingrese 1, si esta ocupado por una materia, 0 si esta libre :)" << endl;

            for(int i = 0; i < dias; i++){
                cout << "\n--- " << dias_semana[i] << " ---" << endl;
                for(int j = 0; j < hora; j++){
                    cout << "  Hora " << horas_clase[j] << ": ";
                    cin >> horario_contenido[i][j];
                    // Validacion.
                    while(horario_contenido[i][j] != 1 && horario_contenido[i][j] != 0){
                        cout << "Entrada invalida. 1 = Ocupado, 0 = Libre" << endl;
                        cout << "  Hora " << horas_clase[j] << ": ";
                        cin >> horario_contenido[i][j];
                    }
                    // Logica de combinacion.
                    if(horario_contenido[i][j] == 1){
                        horario_final_combinado[i][j] = 1;
                    }
                }
            }

            // IMPRIMIR HORARIO INDIVIDUAL.
            cout << "\n-------------------HORARIO INGRESADO (Estudiante " << c << ")------------------- "<< endl;
            cout << "------------------------------------------------------" << endl;

            // horas.
            cout << "Dia/Hora\t";
            for(int k = 0; k < hora; k++){
                cout << horas_clase[k] << "\t";
            }
            cout << endl;
            cout << "------------------------------------------------------" << endl;

            // Imprimir.
            for(int i = 0; i < dias; i++){
                cout << dias_semana[i] << "\t";
                for(int j = 0; j < hora; j++){
                    cout << horario_contenido[i][j] << "\t";
                }
                cout << endl;
            }
            cout << "------------------------------------------------------" << endl;
        }

        // IMPRIMIR HORARIO FINAL COMBINADO

        cout << "\n\n-------------HORARIO FINAL COMBINADO---------------- "<< endl;
        cout << "------------------------------------------------------" << endl;

        // horas.
        cout << "Dia/Hora\t";
        for(int k = 0; k < hora; k++){
            cout << horas_clase[k] << "\t";
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;

        // Imprimir Matriz Final.
        for(int i = 0; i < dias; i++){
            cout << dias_semana[i] << "\t";
            for(int j = 0; j < hora; j++){
                cout << horario_final_combinado[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
     
};
