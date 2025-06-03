#include <iostream>
#include <string>
#include <fstream>
#include "Cruze_horarios.h"

// Guardar estudiantes de una sección
void guardarEstudiantes(const string& filename, Estudiante* estudiantes, int cantidad) {
    ofstream archivo(filename);
    for (int i = 0; i < cantidad; ++i) {
        archivo << estudiantes[i].getNombre() << "," << estudiantes[i].getCedula() << "," << estudiantes[i].getSeccion() << endl;
    }
    archivo.close();
}

// Cargar estudiantes de una sección
int cargarEstudiantes(const string& filename, Estudiante* estudiantes, int capacidad) {
    ifstream archivo(filename);
    string linea, nombre, cedula, seccion;
    int cantidad = 0;
    while (getline(archivo, linea) && cantidad < capacidad) {
        size_t p1 = linea.find(',');
        size_t p2 = linea.find(',', p1+1);
        if (p1 == string::npos || p2 == string::npos) continue;
        nombre = linea.substr(0, p1);
        cedula = linea.substr(p1+1, p2-p1-1);
        seccion = linea.substr(p2+1);
        estudiantes[cantidad] = Estudiante(nombre, cedula, seccion);
        cantidad++;
    }
    archivo.close();
    return cantidad;
}
void guardarProfesores(const string& filename, Profesor* profesores, int cantidad) {
    ofstream archivo(filename);
    for (int i = 0; i < cantidad; ++i) {
        archivo << profesores[i].getNombre() << "," << profesores[i].getCedula() << endl;
    }
    archivo.close();
}

int cargarProfesores(const string& filename, Profesor* profesores, int capacidad) {
    ifstream archivo(filename);
    string linea, nombre, cedula;
    int cantidad = 0;
    while (getline(archivo, linea) && cantidad < capacidad) {
        size_t p1 = linea.find(',');
        if (p1 == string::npos) continue;
        nombre = linea.substr(0, p1);
        cedula = linea.substr(p1+1);
        profesores[cantidad] = Profesor(nombre, cedula); // Use copy assignment
        cantidad++;
    }
    archivo.close();
    return cantidad;
}
// Guarda todos los horarios de una sección
void guardarHorariosSeccion(const string& filename, Cruse_horarios* horarios, int cantidad) {
    ofstream archivo(filename);
    for (int k = 0; k < cantidad; ++k) {
        // Guardar cédula para identificar a quién pertenece el horario
        archivo << horarios[k].getCedula();
        // Guardar la matriz de horario (5x4)
        const int (&matriz)[5][4] = horarios[k].getHorarioFinalCombinado();
        for (int i = 0; i < 5; ++i) {
            archivo << (i == 0 ? "," : ";"); // Separador de filas
            for (int j = 0; j < 4; ++j) {
                archivo << matriz[i][j];
                if (j < 3) archivo << ",";
            }
        }
        archivo << endl;
    }
    archivo.close();
}
void cargarHorariosSeccion(const string& filename, Cruse_horarios* horarios, int cantidad) {
    ifstream archivo(filename);
    string linea;
    int k = 0;
    while (getline(archivo, linea) && k < cantidad) {
        size_t pos = linea.find(',');
        if (pos == string::npos) continue;
        string cedula = linea.substr(0, pos);
       // Debes tener un método setCedula en Cruse_horarios o usar el constructor

        size_t fila_ini = pos + 1;
        for (int i = 0; i < 5; ++i) {
            size_t fila_fin = linea.find(';', fila_ini);
            string fila = (fila_fin == string::npos) ? linea.substr(fila_ini) : linea.substr(fila_ini, fila_fin - fila_ini);
            size_t prev = 0, curr;
            int j = 0;
            while ((curr = fila.find(',', prev)) != string::npos && j < 4) {
                horarios[k].setHorarioValor(i, j, stoi(fila.substr(prev, curr - prev))); // Debes tener setHorarioValor
                prev = curr + 1;
                ++j;
            }
            if (j < 4 && prev < fila.size())
                horarios[k].setHorarioValor(i, j, stoi(fila.substr(prev)));
            fila_ini = (fila_fin == string::npos) ? string::npos : fila_fin + 1;
        }
        ++k;
    }
    archivo.close();
}

