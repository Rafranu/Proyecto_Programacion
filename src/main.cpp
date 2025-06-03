//Librerias.
#include <iostream>
#include <string>
#include "menu.h"
#include <fstream>
#include "raylib.h"
using namespace std;

//Variables constantes.

//Estudiantes por seccion.
//Profesores y asignaturas.
const int capacidad_profesores = 5;
const int capacidad_asignaturas = 6;



//Funcion principal.
int main() {
//Variables
Estudiante Estudiante_3d1[capacidad_seccion];
Estudiante Estudiante_3d2[capacidad_seccion];
Profesor profesores[capacidad_profesores];
Asignatura asignaturas_profesor[capacidad_asignaturas];
Asignatura asignaturas_estudiante_3d1[capacidad_asignaturas];
Asignatura asignaturas_estudiante_3d2[capacidad_asignaturas];
Horario H_Estudiantes_3d1 [capacidad_seccion];
Horario H_Estudiantes_3d2 [capacidad_seccion];
Cruse_horarios H_Profesor [capacidad_profesores];
int capacidad_3d1 = 0;
int capacidad_3d2 = 0;
int contador_profesores = 0;
int contador_asignaturas = 0;
int opcion;
capacidad_3d1 = cargarEstudiantes("estudiantes_3d1.csv", Estudiante_3d1, capacidad_seccion);
cargarHorariosSeccion("horario_estudiantes_3d1.csv", H_Estudiantes_3d1, capacidad_3d1);
capacidad_3d2 = cargarEstudiantes("estudiantes_3d2.csv", Estudiante_3d2, capacidad_seccion);
contador_profesores = cargarProfesores("profesores.csv", profesores, capacidad_profesores);  


    menuPrincipal(
        Estudiante_3d1, Estudiante_3d2, capacidad_3d1, capacidad_3d2,
        profesores, contador_profesores,
        asignaturas_profesor, asignaturas_estudiante_3d1, asignaturas_estudiante_3d2,
        H_Estudiantes_3d1, H_Estudiantes_3d2, H_Profesor,
        capacidad_seccion, capacidad_profesores
    );

    guardarEstudiantes("estudiantes_3d1.csv", Estudiante_3d1, capacidad_3d1);
    guardarEstudiantes("estudiantes_3d2.csv", Estudiante_3d2, capacidad_3d2);
    guardarProfesores("profesores.csv", profesores, contador_profesores);

    return 0;
}