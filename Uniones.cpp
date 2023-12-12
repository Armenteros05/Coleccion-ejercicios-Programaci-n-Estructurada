#include <iostream>
#include <string>
#include <cstring>

union MiUnion {
    int entero;
    float flotante;
    char cadena[50];  // Utilizamos un arreglo de caracteres para la cadena
};

int main() {
    MiUnion miVariable;

    // Asignar un entero
    miVariable.entero = 42;
    std::cout << "Valor entero: " << miVariable.entero << std::endl;

    // Asignar un flotante
    miVariable.flotante = 3.14f;
    std::cout << "Valor flotante: " << miVariable.flotante << std::endl;

    // Asignar una cadena de caracteres
    std::strcpy(miVariable.cadena, "Hola, mundo!");
    std::cout << "Valor cadena: " << miVariable.cadena << std::endl;

    return 0;
}
