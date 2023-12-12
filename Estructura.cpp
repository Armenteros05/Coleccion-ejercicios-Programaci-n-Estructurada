#include <iostream>
#include <cstdlib> // Necesario para malloc y free
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    // a. Instanciación normal
    Estudiante estudiante1;
    Estudiante estudiante2;
    Estudiante estudiante3;

    int respuesta;

    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(estudiante1.nombre, 50, '\n');
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante1.edad;
    cout << "Ingrese el promedio de notas del estudiante: ";
    cin >> estudiante1.promedio;
    cout << "\nNombre del estudiante: " << estudiante1.nombre << endl;
    cout << "Edad del estudiante: " << estudiante1.edad << endl;
    cout << "Promedio de notas del estudiante: " << estudiante1.promedio << endl;

    // b. Instanciación con el operador malloc
    Estudiante* estudiante4 = static_cast<Estudiante*>(malloc(sizeof(Estudiante)));

    // c. Punteros y estructuras
    Estudiante* estudiante5 = new Estudiante;

    // d. Inicialización del puntero
    cout << "Ingrese el nombre del estudiante 2: ";
    cin.ignore(); // Ignora el salto de línea pendiente
    cin.getline(estudiante5->nombre, 50, '\n');
    cout << "Ingrese la edad del estudiante 2: ";
    cin >> estudiante5->edad;
    cout << "Ingrese el promedio de notas del estudiante 2: ";
    cin >> estudiante5->promedio;
    cout << "\nNombre del estudiante 5: " << estudiante5->nombre << endl;
    cout << "Edad del estudiante 5: " << estudiante5->edad << endl;
    cout << "Promedio de notas del estudiante 5: " << estudiante5->promedio << endl;

    // e. Aplicación que crea, añade, muestra y elimina estudiantes
    const int MAX_ESTUDIANTES = 5;
    Estudiante* listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;

    while (true) {
        cout << "\nSeleccione una opción:\n1. Agregar estudiante\n2. Mostrar estudiantes\n3. Salir\n";
        cin >> respuesta;

        switch (respuesta) {
            case 1:
                if (cantidadEstudiantes < MAX_ESTUDIANTES) {
                    listaEstudiantes[cantidadEstudiantes] = new Estudiante;
                    cout << "Ingrese el nombre del estudiante: ";
                    cin.ignore(); // Ignora el salto de línea pendiente
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
                // Liberar memoria antes de salir
                for (int i = 0; i < cantidadEstudiantes; ++i) {
                    delete listaEstudiantes[i];
                }
                // Liberar memoria para el estudiante4
                free(estudiante4);
                // Liberar memoria para el estudiante5
                delete estudiante5;
                return 0;
            default:
                cout << "Opcion no válida. Intentelo de nuevo." << endl;
        }
    }

    return 0;
}
