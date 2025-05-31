
//Librerias.

#include <iostream>
#include <string>
#include "Persona_Universidad.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Asignatura.h"
#include "Horarios.h"
#include "Cruze_horarios.h"
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
Cruse_horarios H_Estudiantes_3d1 [capacidad_seccion];
Cruse_horarios H_Estudiantes_3d2 [capacidad_seccion];
Cruse_horarios H_Profesor [capacidad_profesores];
int capacidad_3d1 = 0;
int capacidad_3d2 = 0;
int contador_profesores = 0;
int contador_asignaturas = 0;
int opcion;
    

cout<<"Hola mundo!";

    do{
    	//Opciones.
    	
    	cout<<"------Modulos TERNA------"<<endl; 
    	cout<<"1.Modulo Estudiante."<<endl;
    	cout<<"2.Modulo Profesor."<<endl;
    	cout<<"3.Salir del programa."<<endl;
    	cout<<"Opcion: "<<endl;
    	cin>>opcion; 
        cin.ignore();
    	
    	//Casos. 
    	
    	        switch(opcion){
    	        case 1: { //Modulo estudiante
    		   //Variables.
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
    	       cout<<"6.Volver al menu principal."<<endl;
    	       cout<<"Opcion: "<<endl;
    	       cin>>opcion_estudiante;
               cin.ignore(); 
    	       //Casos. 
    	         switch(opcion_estudiante) {
                case 1: { // Ingresar
            cout << "Ingrese la sección (3D1 o 3D2): ";
            string seccion; 
            getline(cin >> ws, seccion);
            if ((seccion == "3D1")||(seccion=="3d1")) {
                cout << "Ingresando estudiante a 3D1..." << endl;
                if (capacidad_3d1 < capacidad_seccion) {
                        Estudiante_3d1[capacidad_3d1].solicitarDatos();
                        capacidad_3d1++;
               
                cout << "Estudiante ingresado correctamente." << endl;
            } else {
                cout << "No hay espacio para más estudiantes en 3D1." << endl;
            }
                } else if ((seccion == "3D2")||(seccion=="3d2")) {
                cout << "Ingresando estudiante a 3D2..." << endl;
                if (capacidad_3d2 < capacidad_seccion) {
                    Estudiante_3d2[capacidad_3d2].solicitarDatos();
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
                string cedula_eliminar;
                string seccion_eliminar;
               cout << "Ingrese la cédula del estudiante a eliminar: ";
                getline(cin >> ws, cedula_eliminar);
                cout << "Ingrese la seccion del estudiante a eliminar (3D1, 3D2): ";
                getline(cin >> ws, seccion_eliminar);

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

                string seccion_actualizar, cedula_actualizar;                    

             cout << "Ingrese la sección del estudiante a actualizar (3D1, 3D2): ";
              getline(cin >> ws, seccion_actualizar);
                 cout << "Ingrese la cédula del estudiante a actualizar: ";
                 getline(cin >> ws, cedula_actualizar);
                    bool encontrado = false;
                     if (seccion_actualizar == "3D1" || seccion_actualizar == "3d1") {
                     for (int i = 0; i < capacidad_3d1; ++i) {
                        if (Estudiante_3d1[i].getCedula() == cedula_actualizar) {
                        string nuevo_nombre, nueva_cedula;
                        cout << "Nuevo nombre: ";
                         getline(cin, nuevo_nombre);
                        cout << "Nueva cédula: ";
                        getline(cin, nueva_cedula);
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
                        string nuevo_nombre, nueva_cedula;
                        cout << "Nuevo nombre: ";
                         getline(cin, nuevo_nombre);
                        cout << "Nueva cédula: ";
                        getline(cin, nueva_cedula);
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

}
        cout << "--- Estudiantes 3D2 ---" << endl;
        for (int i = 0; i < capacidad_3d2; ++i) {
        Estudiante_3d2[i].mostrarInformacion();
        asignaturas_estudiante_3d2[i].mostrar();
        }
            break;
}
                case 5: { //Llenar materias
                string cedulaE, seccionE;
                cout<<"Ingrese su cedula para ingresar sus materias"<<endl;
                    getline(cin>>ws, cedulaE);
                cout<<"Ingrese su seccion (3D1 o 3D2): "<<endl;
                getline(cin>>ws, seccionE);
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
                        string cedula;
                        string seccion;
                    cout<<"Ingresa su cedula"<<endl;
                    getline(cin>>ws,cedula );
                    cout<< "ingrese su seccion"<<endl;
                    getline(cin>>ws, seccion);
                            if((seccion=="3d1")||(seccion=="3D1")){
                                  for (int i = 0; i < capacidad_3d1; ++i) {
                                     if (Estudiante_3d1[i].getCedula() == cedula) {
                                        H_Estudiantes_3d1[i].funcion_horario_estudiante();
                                        H_Estudiantes_3d1[i].compararHorariosYGenerarReprogramacion();
                                        cout<<"Horario agragado"<<endl;
                                   }    break;
                                     }
                            }
                            else if((seccion=="3d2")||(seccion=="3D2")){
                                  for (int i = 0; i < capacidad_3d2; ++i) {
                                     if (Estudiante_3d2[i].getCedula() == cedula) {
                                        H_Estudiantes_3d2[i].funcion_horario_estudiante();
                                        H_Estudiantes_3d2[i].compararHorariosYGenerarReprogramacion();
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
			    int opcion_profesor;
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
    	       cout<<"Opcion: "<<endl;
    	       cin>>opcion_profesor; 
    	       cin.ignore();
    	       //Casos. 
    	       switch(opcion_profesor){
    	       	   
    case 1: { // Ingresar
         if (contador_profesores < capacidad_profesores) {
                    cout << "Ingresando profesor..." << endl;
                    profesores[contador_profesores].solicitarDatos();
                    contador_profesores++;
                    cout << "Profesor ingresado correctamente." << endl;
                } else {
                    cout << "No hay espacio para más profesores." << endl;
                }
                break;
    }
    case 2: { // Eliminar
        string cedula_eliminar;
        cout << "Ingrese la cédula del profesor a eliminar: ";
        getline(cin >> ws, cedula_eliminar);
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
        string cedula_actualizar;
        cout << "Ingrese la cédula del profesor a actualizar: ";
        getline(cin >> ws, cedula_actualizar);
        bool encontrado = false;
        for (int i = 0; i < contador_profesores; ++i) {
            if (profesores[i].getCedula() == cedula_actualizar) {
                string nuevo_nombre, nueva_cedula;
                cout << "Nuevo nombre: ";
                getline(cin, nuevo_nombre);
                cout << "Nueva cédula: ";
                getline(cin, nueva_cedula);
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
        string cedula_profesor;
        cout << "Ingrese la cédula del profesor: ";
        getline(cin >> ws, cedula_profesor);
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
        string cedula;
        cout<<"Ingrese su cedula"<<endl;
        getline(cin>>ws, cedula);
        for(int i=0; i<capacidad_profesores;i++){
            if(cedula==profesores[i].getCedula()){
                H_Profesor[i].ingresarHorarioProfesor();
            }
        }

        break;
    }
   case 7:{//Cruze Horarios
    string cedula;
    cout<<"Ingrese su cedula: "<<endl;
    getline(cin>>ws, cedula);
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
    
    
    //Fin del programa.
    return 0;
}