#include <iostream>
#include <cstring>

// Estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// a. Pasar una estructura por valor como argumento
void imprimirEstudiantePorValor(Estudiante est) {
    std::cout << "a. Por valor: Nombre: " << est.nombre << ", Edad: " << est.edad << ", Promedio: " << est.promedio << std::endl;
}

// b. Pasar una estructura por referencia como argumento
void modificarEstudiantePorReferencia(Estudiante& est) {
    est.edad = 30;
}

// c. Pasar una estructura por dirección como argumento
void imprimirEstudiantePorDireccion(const Estudiante* est) {
    std::cout << "c. Por dirección: Nombre: " << est->nombre << ", Edad: " << est->edad << ", Promedio: " << est->promedio << std::endl;
}

// d. Programación orientada a objetos
class EstudianteOOP {
public:
    char nombre[50];
    int edad;
    float promedio;

    // Constructor
    EstudianteOOP(const char* n, int e, float p) : edad(e), promedio(p) {
        std::strcpy(nombre, n);
    }

    // Método para imprimir información del estudiante
    void imprimirInformacion() const {
        std::cout << "d. Programación orientada a objetos: Nombre: " << nombre << ", Edad: " << edad << ", Promedio: " << promedio << std::endl;
    }
};

int main() {
    // Crear una instancia de la estructura Estudiante
    Estudiante estudiante1;
    std::strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 25;
    estudiante1.promedio = 8.5;

    // a. Pasar una estructura por valor como argumento
    imprimirEstudiantePorValor(estudiante1);

    // b. Pasar una estructura por referencia como argumento
    modificarEstudiantePorReferencia(estudiante1);
    std::cout << "b. Por referencia: Edad después de modificar: " << estudiante1.edad << std::endl;

    // c. Pasar una estructura por dirección como argumento
    imprimirEstudiantePorDireccion(&estudiante1);

    // d. Programación orientada a objetos
    EstudianteOOP estudianteOOP("Maria", 22, 9.0);
    estudianteOOP.imprimirInformacion();

    return 0;
}
