#include <iostream>
#include <cstring>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void imprimirEstudiantePorValor(Estudiante est) {
    std::cout << "a. Por valor: Nombre: " << est.nombre << ", Edad: " << est.edad << ", Promedio: " << est.promedio << std::endl;
}

void modificarEstudiantePorReferencia(Estudiante& est) {
    std::cout << "Introduce la nueva edad: ";
    std::cin >> est.edad;
}

void imprimirEstudiantePorDireccion(const Estudiante* est) {
    std::cout << "c. Por direccion: Nombre: " << est->nombre << ", Edad: " << est->edad << ", Promedio: " << est->promedio << std::endl;
}

class EstudianteOOP {
public:
    char nombre[50];
    int edad;
    float promedio;

    EstudianteOOP(const char* n, int e, float p) : edad(e), promedio(p) {
        std::strcpy(nombre, n);
    }

    void imprimirInformacion() const {
        std::cout << "d. Programacion orientada a objetos: Nombre: " << nombre << ", Edad: " << edad << ", Promedio: " << promedio << std::endl;
    }
};

int main() {
    Estudiante estudiante1;
    std::cout << "Introduce el nombre del estudiante: ";
    std::cin.ignore(); // Ignorar el salto de línea anterior
    std::cin.getline(estudiante1.nombre, 50);

    std::cout << "Introduce la edad del estudiante: ";
    std::cin >> estudiante1.edad;

    std::cout << "Introduce el promedio del estudiante: ";
    std::cin >> estudiante1.promedio;

    imprimirEstudiantePorValor(estudiante1);
    modificarEstudiantePorReferencia(estudiante1);
    imprimirEstudiantePorDireccion(&estudiante1);

    EstudianteOOP estudianteOOP("Maria", 22, 9.0);
    estudianteOOP.imprimirInformacion();

    return 0;
}
