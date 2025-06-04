#pragma once
#include <iostream>
#include <string>
#include "Horarios.h"
#include "Profesor.h"
#include "Estudiante.h"
#include "Validaciones.h"
using namespace std;




class Cruse_horarios : public Horario, public Profesor {
    // Atributos.
    string materia_impartida;
    string seccion_reprogramacion_solicitada; 

    int dias = 5;
    int hora = 4;

    // Definir dias de las semanas.
    string dias_semana[5] = {"LUNES", "MARTES", "MIERCOLES", "JUEVES", "VIERNES"};

    // Definir horas de clases.
    string horas_clase[4] = {"8-9", "9-10", "10-11", "11-12"};

    // Horario del profesor (contenido).
    int horario_profesor[5][4];

    // Horario combinado de los estudiantes (para la comparación)
    int horario_estudiantes_combinado[5][4];

    // Matriz final de disponibilidad para reprogramación (0 = libre, 1 = ocupado)
    int horario_reprogramacion_final[5][4];

public:
    // Constructor de Cruse_horarios\
    
    Cruse_horarios(
        string nombre_p = "", string cedula_p = "", string seccion_e = "",
        string materia_p = "", string seccion_rep = ""
    ) :
        Persona_Universidad(nombre_p, cedula_p),
        Horario(nombre_p, cedula_p, seccion_e),
        Profesor(nombre_p, cedula_p),
        materia_impartida(materia_p),
        seccion_reprogramacion_solicitada(seccion_rep)
    {
        for (int i = 0; i < dias; ++i) {
            for (int j = 0; j < hora; ++j) {
                horario_profesor[i][j] = 0;
                horario_estudiantes_combinado[i][j] = 0;
                horario_reprogramacion_final[i][j] = 0;
            }
        }
    }
    
     void setHorarioEstudiantesCombinado(const int (&horario_comb)[5][4]) {
        for (int i = 0; i < dias; ++i) {
            for (int j = 0; j < hora; ++j) {
                horario_estudiantes_combinado[i][j] = horario_comb[i][j];
                horario_final_combinado[i][j] = horario_comb[i][j]; // <- Añade esto
            }
        }
    }
    
    const int (&getHorarioFinalCombinado() const)[5][4] { return horario_final_combinado; }
    void setHorarioValor(int i, int j, int valor) { horario_final_combinado[i][j] = valor; }
    void ingresarHorarioProfesor(Profesor profesor) {
        
        cout << "Ingrese la materia que imparte el profesor: ";
        getline(cin >> ws, materia_impartida);
        cout << "Materia asignada al profesor " << profesor.getNombre() << ": " << materia_impartida << endl;

        cout << "Ingrese la seccion de estudiantes para la cual se hara la reprogramacion: ";
        getline(cin >> ws, seccion_reprogramacion_solicitada);

        cout << "\n-------------------Llenado de horario del Profesor----------------------" << endl;
        cout << "Ingrese 1, si la hora esta ocupada por la materia, 0 si esta libre :)" << endl;

        for (int i = 0; i < dias; i++) {
            cout << "\n--- " << dias_semana[i] << " ---" << endl;
            for (int j = 0; j < hora; j++) {
                cout << "  Hora " << horas_clase[j] << ": ";
                cin >> horario_profesor[i][j];
                while (horario_profesor[i][j] != 1 && horario_profesor[i][j] != 0) {
                    cout << "Entrada invalida. 1 = Ocupado, 0 = Libre" << endl;
                    cout << "  Hora " << horas_clase[j] << ": ";
                    cin >> horario_profesor[i][j];
                }
            }
        }
        cin.ignore(); 

        mostrarHorarioProfesor();
    }
   

    void compararHorariosYGenerarReprogramacion(Cruse_horarios& horario_estudiantes, string seccion_reprogramacion_solicitada) {
        cout << "\n--- Realizando Comparacion de Horarios para Reprogramacion ---" << endl;
        cout << "Comparando horario del profesor con el horario combinado de la seccion " << seccion_reprogramacion_solicitada << endl;

        
        cout << "\n-------------HORARIO COMBINADO DE ESTUDIANTES (Seccion: " << seccion_reprogramacion_solicitada << ")---------------- " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Dia/Hora\t";
        for (int k = 0; k < hora; k++) {
            cout << horas_clase[k] << "\t";
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < dias; i++) {
            cout << dias_semana[i] << "\t";
            for (int j = 0; j < hora; j++) {
                cout << horario_estudiantes_combinado[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;


        for (int i = 0; i < dias; ++i) {
            for (int j = 0; j < hora; ++j) {
                
                if (horario_profesor[i][j] == 0 && horario_estudiantes_combinado[i][j] == 0) {
                    horario_reprogramacion_final[i][j] = 0;
                } else {
                    
                    horario_reprogramacion_final[i][j] = 1;
                }
            }
        }

        // Muestra la matriz final de reprogramación
        cout << "\n-------------HORARIO FINAL PARA REPROGRAMACION (0=Libre, 1=Ocupado)---------------- " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Dia/Hora\t";
        for (int k = 0; k < hora; k++) {
            cout << horas_clase[k] << "\t";
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < dias; i++) {
            cout << dias_semana[i] << "\t";
            for (int j = 0; j < hora; j++) {
                cout << horario_reprogramacion_final[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
        cout << "Los espacios marcados con '0' son los horarios disponibles para la reprogramacion." << endl;
    }

    // Método para mostrar el horario del profesor
    void mostrarHorarioProfesor() const {
        cout << "\n-------------HORARIO del Profesor " << Profesor::getNombre() << "---------------- " << endl;
        cout << "Materia: " << materia_impartida << endl;
        cout << "Seccion de Reprogramacion Solicitada: " << seccion_reprogramacion_solicitada << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Dia/Hora\t";
        for (int k = 0; k < hora; k++) {
            cout << horas_clase[k] << "\t";
        }
        cout << endl;
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < dias; i++) {
            cout << dias_semana[i] << "\t";
            for (int j = 0; j < hora; j++) {
                cout << horario_profesor[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }
};