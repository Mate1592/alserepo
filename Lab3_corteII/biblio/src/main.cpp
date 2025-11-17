#include "biblioteca.h"
#include <iostream>
#include <limits>

void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mostrarMenu() {
    std::cout << "\n===== SISTEMA DE GESTION DE BIBLIOTECA (C++) =====\n";
    std::cout << "1. Agregar libro\n";
    std::cout << "2. Eliminar libro\n";
    std::cout << "3. Buscar libro por titulo o autor\n";
    std::cout << "4. Mostrar libros disponibles\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    Biblioteca miBiblioteca;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;
        limpiarBuffer();

        std::string titulo, autor, isbn, clave;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el titulo: ";
                std::getline(std::cin, titulo);
                std::cout << "Ingrese el autor: ";
                std::getline(std::cin, autor);
                std::cout << "Ingrese el ISBN: ";
                std::getline(std::cin, isbn);
                miBiblioteca.agregarLibro(titulo, autor, isbn);
                break;
            case 2:
                std::cout << "Ingrese el ISBN del libro a eliminar: ";
                std::getline(std::cin, isbn);
                miBiblioteca.eliminarLibro(isbn);
                break;
            case 3:
                std::cout << "Ingrese titulo o autor a buscar: ";
                std::getline(std::cin, clave);
                miBiblioteca.buscarLibros(clave);
                break;
            case 4:
                miBiblioteca.mostrarLibrosDisponibles();
                break;
            case 0:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
