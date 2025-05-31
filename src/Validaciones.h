#include <iostream>
#include <string>
using namespace std;

// Función para validar un entero dentro de un rango
int leerEnteroEnRango(const string& mensaje, int min, int max) {
    int valor;
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        try {
            valor = stoi(entrada);
            if (valor >= min && valor <= max) {
                return valor;
            } else {
                cout << "Valor fuera de rango (" << min << "-" << max << "). Intente de nuevo." << endl;
            }
        } catch (...) {
            cout << "Entrada inválida. Intente de nuevo." << endl;
        }
    }
}

// Función para leer una cadena no vacía
string leerCadenaNoVacia(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        if (!entrada.empty()) {
            return entrada;
        } else {
            cout << "La entrada no puede estar vacía. Intente de nuevo." << endl;
        }
    }
}

// Función para leer una opción de menú válida
int leerOpcionMenu(const string& mensaje, int min, int max) {
    return leerEnteroEnRango(mensaje, min, max);
}

// Valida que la sección sea "3D1" o "3D2" (no distingue mayúsculas/minúsculas)
string leerSeccionValida(const string& mensaje) {
    string seccion;
    while (true) {
        cout << mensaje;
        getline(cin >> ws, seccion);
        // Convierte a mayúsculas para comparar
        for (auto& c : seccion) c = toupper(c);
        if (seccion == "3D1" || seccion == "3D2"|| seccion == "3d1" || seccion == "3d2") {  
            return seccion;
        } else {
            cout << "Sección inválida. Debe ser 3D1 o 3D2." << endl;
        }
    }
}

// Valida que la cédula sea numérica y de 6 a 8 dígitos
string leerCedulaValida(const string& mensaje) {
    string cedula;
    while (true) {
        cout << mensaje;
        getline(cin >> ws, cedula);
        bool esNumero = !cedula.empty();
        for (char c : cedula) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }
        if (esNumero && cedula.length() >= 6 && cedula.length() <= 8) {
            return cedula;
        } else {
            cout << "Cédula inválida. Debe ser solo números (6 a 8 dígitos)." << endl;
        }
    }
}