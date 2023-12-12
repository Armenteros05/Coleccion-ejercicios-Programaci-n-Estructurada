#include <iostream>
using namespace std;

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};
int Estudiantes[5];
int main() {
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

    return 0;
}