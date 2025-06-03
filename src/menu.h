#pragma once
#include <iostream>
#include <string>
#include "Persona_Universidad.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Asignatura.h"
#include "Horarios.h"
#include "Cruze_horarios.h"
#include "Validaciones.h"
#include "Archivos.h"
#include <fstream>
#include "raylib.h"
using namespace std;

//Variables constantes.



// Aquí va la función del menú principal y submenús
void menuPrincipal(
    Estudiante Estudiante_3d1[], Estudiante Estudiante_3d2[], int& capacidad_3d1, int& capacidad_3d2,
    Profesor profesores[], int& contador_profesores,
    Asignatura asignaturas_profesor[], Asignatura asignaturas_estudiante_3d1[], Asignatura asignaturas_estudiante_3d2[],
    Horario H_Estudiantes_3d1[], Horario H_Estudiantes_3d2[], Cruse_horarios H_Profesor[],
    int capacidad_seccion, int capacidad_profesores
) {
    int opcion;
    do {
       cout<<"------Modulos TERNA------"<<endl; 
    	cout<<"1.Modulo Estudiante."<<endl;
    	cout<<"2.Modulo Profesor."<<endl;
    	cout<<"3.Salir del programa."<<endl;
    	opcion = leerOpcionMenu("Opcion: ", 1, 3);
    	
    	//Casos. 
    	
    	        switch(opcion){
    	        case 1: { //Modulo estudiante
    		  
			   int opcion_estudiante;
			   //Opciones. 
               do{
			   cout<<"------ESTUDIANTES------"<<endl; 
    	       cout<<"1.Ingresar."<<endl;
    	       cout<<"2.Eliminar."<<endl;
    	       cout<<"3.Actualizar."<<endl;
    	       cout<<"4.Mostrar."<<endl;
               cout<<"5.Llenar materias"<<endl;
               cout<<"6.Horarios"<<endl;
    	       cout<<"7.Volver al menu principal."<<endl;
    	       opcion_estudiante= leerOpcionMenu("Opcion: ", 1, 7);

              
    	       //Casos. 
    	         switch(opcion_estudiante) {
                case 1: { // Ingresar
             string seccion = leerSeccionValida("Ingrese la sección (3D1 o 3D2): ");
            
            if ((seccion == "3D1")||(seccion=="3d1")) {
                cout << "Ingresando estudiante a 3D1..." << endl;
                if (capacidad_3d1 < capacidad_seccion) {
                        Estudiante_3d1[capacidad_3d1].solicitarDatos();
                       Estudiante_3d1[capacidad_3d1].setSeccion(seccion);
                        capacidad_3d1++;
               
                cout << "Estudiante ingresado correctamente." << endl;
            } else {
                cout << "No hay espacio para más estudiantes en 3D1." << endl;
            }
                } else if ((seccion == "3D2")||(seccion=="3d2")) {
                cout << "Ingresando estudiante a 3D2..." << endl;
                if (capacidad_3d2 < capacidad_seccion) {
                    Estudiante_3d2[capacidad_3d2].solicitarDatos();
                    Estudiante_3d2[capacidad_3d2].setSeccion(seccion);
                    capacidad_3d2++;
                    cout << "Estudiante ingresado correctamente." << endl;
                } else {
                    cout << "No hay espacio para más estudiantes en 3D2." << endl;
                }
            } else {
                cout << "Sección inválida. Debe ser 3D1 o 3D2." << endl;
            }
            break;
        }          
                case 2: { // Eliminar
                string cedula_eliminar = leerCedulaValida("Ingrese la cedula del estudiante a eliminar ");
                
                string seccion_eliminar = leerSeccionValida("Ingrese la sección (3D1 o 3D2): ");

                bool encontrado = false;
                if ((seccion_eliminar == "3D1")||(seccion_eliminar=="3d1")) {
                   for (int i = 0; i < capacidad_3d1; ++i) {
                   if (Estudiante_3d1[i].getCedula() == cedula_eliminar) {
                    for (int j = i; j < capacidad_3d1 - 1; ++j) {
                            Estudiante_3d1[j] = Estudiante_3d1[j + 1];
                            asignaturas_estudiante_3d1[j]= asignaturas_estudiante_3d1[j+1];
                                                                }
                            capacidad_3d1--;
                            encontrado = true;
                            cout << "Estudiante eliminado." << endl;
                            break;
                             }
                                                        }
                } else if ((seccion_eliminar == "3D2")||(seccion_eliminar=="3d2")) {
                    for (int i = 0; i < capacidad_3d2; ++i) {
                        if (Estudiante_3d2[i].getCedula() == cedula_eliminar) {
                            for (int j = i; j < capacidad_3d2 - 1; ++j) {
                                Estudiante_3d2[j] = Estudiante_3d2[j + 1];
                                asignaturas_estudiante_3d2[j] = asignaturas_estudiante_3d2[j + 1];
                            }
                            capacidad_3d2--;
                            encontrado = true;
                            cout << "Estudiante eliminado." << endl;
                            break;
                        }
                    }
                }
                if (!encontrado) {
                    cout << "Alumno no encontrado." << endl;
                }
            break;
        }
                case 3: { // Actualizar

                                  

             string seccion_actualizar = leerSeccionValida("Ingrese la sección del estudiante a actualizar (3D1 o 3D2): ");
             string cedula_actualizar = leerCedulaValida("Ingrese la cédula del estudiante a actualizar: ");
             bool encontrado = false;
             if (seccion_actualizar == "3D1" || seccion_actualizar == "3d1") {
                 for (int i = 0; i < capacidad_3d1; ++i) {
                     if (Estudiante_3d1[i].getCedula() == cedula_actualizar) {
                         string nuevo_nombre = leerCadenaNoVacia("Ingrese el nuevo nombre: ");
                         string nueva_cedula = leerCedulaValida("Ingrese la nueva cédula: ");
                        Estudiante_3d1[i].actualizarDatos(nuevo_nombre, nueva_cedula);
                        cout << "Datos actualizados." << endl;
                        encontrado = true;
                        break;
                }
                }
                }
                    if (seccion_actualizar == "3D2" || seccion_actualizar == "3d2") {
                     for (int i = 0; i < capacidad_3d2; ++i) {
                        if (Estudiante_3d2[i].getCedula() == cedula_actualizar) {
                       string nuevo_nombre = leerCadenaNoVacia("Ingrese el nuevo nombre: ");
                         string nueva_cedula = leerCedulaValida("Ingrese la nueva cédula: ");
                        Estudiante_3d2[i].actualizarDatos(nuevo_nombre, nueva_cedula);
                        cout << "Datos actualizados." << endl;
                        encontrado = true;
                        break;
                }
                }
                }
                if (!encontrado) cout << "Estudiante no encontrado." << endl;
                    break;
                      }
                case 4: { // Mostrar
           cout << "--- Estudiantes 3D1 ---" << endl;
        for (int i = 0; i < capacidad_3d1; ++i) {         
        Estudiante_3d1[i].mostrarInformacion();
        asignaturas_estudiante_3d1[i].mostrar();
        H_Estudiantes_3d1[i].mostrarHorarioFinalCombinado(Estudiante_3d1[i]);

}
        cout << "--- Estudiantes 3D2 ---" << endl;
        for (int i = 0; i < capacidad_3d2; ++i) {
        Estudiante_3d2[i].mostrarInformacion();
        asignaturas_estudiante_3d2[i].mostrar();
        H_Estudiantes_3d2[i].mostrarHorarioFinalCombinado(Estudiante_3d2[i]);
        }
            break;
}
                case 5: { //Llenar materias
                string seccionE = leerSeccionValida("Ingrese la sección (3D1 o 3D2): ");
                string cedulaE=leerCedulaValida("Ingrese la cedula del estudiante: ");
               
                if (seccionE == "3D1" || seccionE == "3d1") {
                    for (int i = 0; i < capacidad_3d1; ++i) {
                        if (Estudiante_3d1[i].getCedula() == cedulaE) {
                            asignaturas_estudiante_3d1[i].llenar_materias_estudiante();
                            cout << "Materias ingresadas correctamente." << endl;
                            break;
                        }
                    }
                } else if (seccionE == "3D2" || seccionE == "3d2") {
                    for (int i = 0; i < capacidad_3d2; ++i) {
                        if (Estudiante_3d2[i].getCedula() == cedulaE) {
                            asignaturas_estudiante_3d2[i].llenar_materias_estudiante();
                            cout << "Materias ingresadas correctamente." << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Sección inválida. Debe ser 3D1 o 3D2." << endl;

                }
                break;
            }
                case 6: {//Horarios
                      string seccion = leerSeccionValida("Ingrese la sección (3D1 o 3D2): ");
                string cedula=leerCedulaValida("Ingrese la cedula del estudiante: ");
                    if((seccion=="3d1")||(seccion=="3D1")){
                                  for (int i = 0; i < capacidad_3d1; ++i) {
                                     if (Estudiante_3d1[i].getCedula() == cedula) {
                                        H_Estudiantes_3d1[i].funcion_horario_estudiante(Estudiante_3d1[i]);
                                      
                                        cout<<"Horario agragado"<<endl;
                                   }    break;
                                     }
                            }
                            else if((seccion=="3d2")||(seccion=="3D2")){
                                  for (int i = 0; i < capacidad_3d2; ++i) {
                                     if (Estudiante_3d2[i].getCedula() == cedula) {
                                        H_Estudiantes_3d2[i].funcion_horario_estudiante(Estudiante_3d2[i]);
                                     
                                        cout<<"Horario agragado"<<endl;
                                   }    break;
                                     }
                            }
                            else{
                                cout<<"Seccion no valida"<<endl;
                            }



                   break; }
                case 7: {
                // Volver al menu principal
                break;
            }
                default:
                cout << "Opcion no valida..." << endl;
                break;
                                         }     
            }while (opcion_estudiante!=7); 
            break;
            }
    		    case 2: { //Modulo profesor
			     //Variables.
			    int opcion_profesor=0;
			    //Opciones. 
                do{
			   cout<<"------PROFESORES------"<<endl; 
    	       cout<<"1.Ingresar."<<endl;
    	       cout<<"2.Eliminar."<<endl;
    	       cout<<"3.Actualizar."<<endl;
    	       cout<<"4.Mostrar."<<endl;
    	       cout<<"5.Agregar materias"<<endl;
               cout<<"6.Horarios."<<endl;
               cout<<"7.Cruze Horario"<<endl;
               cout<<"8.Volver al menu"<<endl;         
    	      opcion_profesor = leerOpcionMenu("Opcion: ", 1, 8);

    	       //Casos. 
    	       switch(opcion_profesor){
    	       	   
    case 1: { // Ingresar
         if (contador_profesores < capacidad_profesores) {
                    cout << "Ingresando profesor..." << endl;
                     string nuevo_nombre = leerCadenaNoVacia("Ingrese el nuevo nombre: ");
                    string nueva_cedula = leerCedulaValida("Ingrese la nueva cédula: ");
                 profesores[contador_profesores].actualizarDatos(nuevo_nombre, nueva_cedula);
                    contador_profesores++;
                    cout << "Profesor ingresado correctamente." << endl;
                } else {
                    cout << "No hay espacio para más profesores." << endl;
                }
                break;
    }
    case 2: { // Eliminar
         string cedula_eliminar = leerCedulaValida("Ingrese la cédula Profesor: ");
       
        if (contador_profesores == 0) {
            cout << "No hay profesores registrados." << endl;
            break;
        }
        bool encontrado = false;
        for (int i = 0; i < contador_profesores; ++i) {
            if (profesores[i].getCedula() == cedula_eliminar) {
                for (int j = i; j < contador_profesores - 1; ++j) {
                    profesores[j] = profesores[j + 1];
                }
                contador_profesores--;
                encontrado = true;
                cout << "Profesor eliminado." << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "Profesor no encontrado." << endl;
        }
        break;
    }
    case 3: { // Actualizar
         string cedula_actualizar = leerCedulaValida("Ingrese la cédula Profesor: ");
        bool encontrado = false;
        for (int i = 0; i < contador_profesores; ++i) {
            if (profesores[i].getCedula() == cedula_actualizar) {
                string nuevo_nombre = leerCadenaNoVacia("Ingrese el nuevo nombre: ");
                string nueva_cedula = leerCedulaValida("Ingrese la nueva cédula: ");
                profesores[i].actualizarDatos(nuevo_nombre, nueva_cedula);
                cout << "Datos actualizados." << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) cout << "Profesor no encontrado." << endl;
        break;
    }
    case 4: { // Mostrar
        for (int i = 0; i < contador_profesores; ++i) {
            cout << "Profesor #" << i+1 << endl;
            profesores[i].mostrarInformacion();
            cout<< "Materia: "<<asignaturas_profesor[i].get_materia()<<endl;
        }
        break;
    }
    case 5: {
        // Agregar materias profesor
        string cedula_profesor = leerCedulaValida("Ingrese la cédula del profesor: ");
        bool encontrado = false;
        for (int i = 0; i < capacidad_profesores; ++i) {
            if (profesores[i].getCedula() == cedula_profesor) {
                asignaturas_profesor[i].agregar_materias();
                encontrado = true;
                break;
           }
       }
       if (!encontrado) {
           cout << "Profesor no encontrado." << endl;
       }
       break;
   }
    case 6:{ // Horarios
        string cedula = leerCedulaValida("Ingrese su cédula: ");
        for(int i=0; i<capacidad_profesores;i++){
            if(cedula==profesores[i].getCedula()){
                H_Profesor[i].ingresarHorarioProfesor(profesores[i]);
            }
        }

        break;
    }
   case 7:{//Cruze Horarios
    string cedula = leerCedulaValida("Ingrese su cédula: ");
    for(int i=0; i<capacidad_profesores;i++){
        if(cedula==profesores[i].getCedula()){
            H_Profesor[i].compararHorariosYGenerarReprogramacion();
            break;
        }
    }

    break;
   } 
   case 8:{ //Volver al menu
    break;
   }
    default:
        cout << "Opcion no valido..." << endl;
        break;
    	 
			   }}while(opcion_profesor!=6);
               break;
            }
    		    case 3: cout<<"Saliendo del programa..."<<endl;break; 
    		    default:cout<<"Opcion no valido..."<<endl;break; 
            
                }
    	
	    }while(opcion!=3); 
    
guardarEstudiantes("estudiantes_3d1.csv", Estudiante_3d1, capacidad_3d1);
guardarEstudiantes("estudiantes_3d2.csv", Estudiante_3d2, capacidad_3d2);
guardarProfesores("profesores.csv", profesores, contador_profesores);
    //Fin del programa.
    
}