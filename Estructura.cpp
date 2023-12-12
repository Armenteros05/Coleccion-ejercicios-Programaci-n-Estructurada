#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    const int MAX_ESTUDIANTES = 5;
    Estudiante* listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;
    int opcion;

    while (true) {
        cout << "\nSeleccione una opcion:\n1. Agregar estudiante\n2. Mostrar estudiantes\n3. Buscar estudiante\n4. Salir\n";
        cout << "Ingrese el numero correspondiente a su eleccion: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Error: Por favor, ingrese un numero." << endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                if (cantidadEstudiantes < MAX_ESTUDIANTES) {
                    listaEstudiantes[cantidadEstudiantes] = new Estudiante;
                    cout << "Ingrese el nombre del estudiante: ";
                    limpiarBuffer();
                    cin.getline(listaEstudiantes[cantidadEstudiantes]->nombre, 50, '\n');
                    cout << "Ingrese la edad del estudiante: ";
                    cin >> listaEstudiantes[cantidadEstudiantes]->edad;
                    if (cin.fail()) {
                        cout << "Error: Ingrese una edad valida." << endl;
                        limpiarBuffer();
                        continue;
                    }
                    cout << "Ingrese el promedio de notas del estudiante: ";
                    cin >> listaEstudiantes[cantidadEstudiantes]->promedio;
                    if (cin.fail()) {
                        cout << "Error: Ingrese un promedio valido." << endl;
                        limpiarBuffer();
                        continue;
                    }
                    cantidadEstudiantes++;
                } else {
                    cout << "La lista de estudiantes esta llena." << endl;
                }
                break;
            case 2:
                cout << "Lista de estudiantes:\n";
                for (int i = 0; i < cantidadEstudiantes; ++i) {
                    cout << "Nombre: " << listaEstudiantes[i]->nombre << ", Edad: " << listaEstudiantes[i]->edad
                         << ", Promedio: " << listaEstudiantes[i]->promedio << endl;
                }
                break;
            case 3:
                // Buscar estudiante por nombre
            {
                string nombreBuscar;
                cout << "Ingrese el nombre del estudiante a buscar: ";
                limpiarBuffer();
                getline(cin, nombreBuscar);

                bool encontrado = false;
                for (int i = 0; i < cantidadEstudiantes; ++i) {
                    if (nombreBuscar == listaEstudiantes[i]->nombre) {
                        cout << "Estudiante encontrado:\n";
                        cout << "Nombre: " << listaEstudiantes[i]->nombre << ", Edad: " << listaEstudiantes[i]->edad
                             << ", Promedio: " << listaEstudiantes[i]->promedio << endl;
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Estudiante no encontrado." << endl;
                }
            }
                break;
            case 4:
                // Liberar memoria antes de salir
                for (int i = 0; i < cantidadEstudiantes; ++i) {
                    delete listaEstudiantes[i];
                }
                return 0;
            default:
                cout << "Error: Opcion no valida. Intente de nuevo." << endl;
                limpiarBuffer();
                break;
        }
    }

    return 0;
}
