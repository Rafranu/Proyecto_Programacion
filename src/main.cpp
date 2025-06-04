//Librerias.
#include <iostream>
#include <string>
#include "menu.h"
#include <fstream>
//#include "raylib.h"
using namespace std;


const int capacidad_profesores = 5;
const int capacidad_asignaturas = 6;



int main() {

Estudiante Estudiante_3d1[capacidad_seccion];
Estudiante Estudiante_3d2[capacidad_seccion];
Profesor profesores[capacidad_profesores];
Asignatura asignaturas_profesor[capacidad_asignaturas];
Asignatura asignaturas_estudiante_3d1[capacidad_asignaturas];
Asignatura asignaturas_estudiante_3d2[capacidad_asignaturas];
Horario H_Estudiantes_3d1 [capacidad_seccion];
Cruse_horarios Horario_Final_Combinado_3d1;
Cruse_horarios Horario_Final_Combinado_3d2;
Horario H_Estudiantes_3d2 [capacidad_seccion];
Cruse_horarios H_Profesor [capacidad_profesores];
int capacidad_3d1 = 0;
int capacidad_3d2 = 0;
int contador_profesores = 0;
int contador_asignaturas = 0;
int opcion;


// 1. Cargar estudiantes y obtener la cantidad real de cada sección
capacidad_3d1 = cargarEstudiantes("estudiantes_3d1.csv", Estudiante_3d1, capacidad_seccion);
capacidad_3d2 = cargarEstudiantes("estudiantes_3d2.csv", Estudiante_3d2, capacidad_seccion);

// 2. Cargar horarios SOLO para la cantidad real de estudiantes cargados
cargarHorariosSeccion("horario_estudiantes_3d1.csv", H_Estudiantes_3d1, capacidad_3d1);
cargarHorariosSeccion("horario_estudiantes_3d2.csv", H_Estudiantes_3d2, capacidad_3d2);

// 3. Cargar asignaturas SOLO para la cantidad real de estudiantes cargados
cargarAsignaturas("asignaturas_estudiante_3d1.csv", asignaturas_estudiante_3d1, capacidad_3d1);
cargarAsignaturas("asignaturas_estudiante_3d2.csv", asignaturas_estudiante_3d2, capacidad_3d2);

// 4. Cargar profesores y sus datos
contador_profesores = cargarProfesores("profesores.csv", profesores, capacidad_profesores);
cargarAsignaturas("asignaturas_profesor.csv", asignaturas_profesor, contador_profesores);
cargarHorariosProfesores("horario_profesores.csv", H_Profesor, contador_profesores);

// 5. Cargar horarios combinados (si aplica)
cargarHorariosProfesores("horario_combinado_3d1.csv", &Horario_Final_Combinado_3d1, capacidad_3d1);
cargarHorariosProfesores("horario_combinado_3d2.csv", &Horario_Final_Combinado_3d2, capacidad_3d2);


menuPrincipal(
        Estudiante_3d1, Estudiante_3d2, capacidad_3d1, capacidad_3d2,
        profesores, contador_profesores,
        asignaturas_profesor, asignaturas_estudiante_3d1, asignaturas_estudiante_3d2,
        H_Estudiantes_3d1, H_Estudiantes_3d2, H_Profesor, Horario_Final_Combinado_3d1, Horario_Final_Combinado_3d2,
        capacidad_seccion, capacidad_profesores
    );

  

    return 0;
}