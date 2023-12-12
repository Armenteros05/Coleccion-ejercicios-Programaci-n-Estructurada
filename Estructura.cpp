#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    const int MAX_ESTUDIANTES = 5;
    Estudiante* listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;
    int respuesta;

    while (true) {
        cout << "\nSeleccione una opcion:\n1. Agregar estudiante\n2. Mostrar estudiantes\n3. Buscar estudiante\n4. Salir\n";
        cin >> respuesta;

        switch (respuesta) {
            case 1:
                if (cantidadEstudiantes < MAX_ESTUDIANTES) {
                    listaEstudiantes[cantidadEstudiantes] = new Estudiante;
                    cout << "Ingrese el nombre del estudiante: ";
                    cin.ignore();
                    cin.getline(listaEstudiantes[cantidadEstudiantes]->nombre, 50, '\n');
                    cout << "Ingrese la edad del estudiante: ";
                    cin >> listaEstudiantes[cantidadEstudiantes]->edad;
                    cout << "Ingrese el promedio de notas del estudiante: ";
                    cin >> listaEstudiantes[cantidadEstudiantes]->promedio;
                    cantidadEstudiantes++;
                } else {
                    cout << "La lista de estudiantes está llena." << endl;
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
                cin.ignore();
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
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    }

    return 0;
}
