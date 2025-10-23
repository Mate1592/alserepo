#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm> // Necesario para std::find_if


class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

public:
    // Constructor para inicializar un libro
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
        : titulo(titulo), autor(autor), isbn(isbn), disponible(true) {}

    // Métodos de acceso (getters) para leer los datos privados
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    std::string getISBN() const { return isbn; }
    bool isDisponible() const { return disponible; }

    // Método para mostrar la información del libro
    void mostrar() const {
        std::cout << "  - Titulo: " << titulo << "\n"
                  << "    Autor: " << autor << "\n"
                  << "    ISBN: " << isbn << "\n"
                  << "    Disponible: " << (disponible ? "Si" : "No") << std::endl;
    }
};


class Biblioteca {
private:
    // Usamos std::vector en lugar de un arreglo C. Es más seguro y flexible.
    std::vector<Libro> libros;

public:
    void agregarLibro(const std::string& titulo, const std::string& autor, const std::string& isbn) {
        // Buscamos si ya existe un libro con el mismo ISBN
        auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& libro) {
            return libro.getISBN() == isbn;
        });

        if (it != libros.end()) {
            std::cout << "--> Error: Ya existe un libro con el ISBN " << isbn << "." << std::endl;
        } else {
            libros.emplace_back(titulo, autor, isbn); // Más eficiente que push_back
            std::cout << "--> Libro agregado exitosamente." << std::endl;
        }
    }

    void eliminarLibro(const std::string& isbn) {
        // posición del libro a eliminar
        auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& libro) {
            return libro.getISBN() == isbn;
        });

        if (it != libros.end()) {
            libros.erase(it); // Eliminamos el libro del vector
            std::cout << "--> Libro con ISBN " << isbn << " eliminado correctamente." << std::endl;
        } else {
            std::cout << "--> Error: No se encontro ningun libro con ese ISBN." << std::endl;
        }
    }

    void buscarLibros(const std::string& clave) const {
        std::cout << "\n--- Resultados de la busqueda para \"" << clave << "\" ---" << std::endl;
        int encontrados = 0;
        for (const auto& libro : libros) {
            // str.find() busca si una subcadena existe. std::string::npos es el valor si no se encuentra.
            if (libro.getTitulo().find(clave) != std::string::npos || libro.getAutor().find(clave) != std::string::npos) {
                libro.mostrar();
                encontrados++;
            }
        }
        if (encontrados == 0) {
            std::cout << "No se encontraron libros con esa informacion." << std::endl;
        }
        std::cout << "---------------------------------------------" << std::endl;
    }

    void mostrarLibrosDisponibles() const {
        std::cout << "\n--- Libros Disponibles en la Biblioteca ---" << std::endl;
        int disponibles = 0;
        for (const auto& libro : libros) {
            if (libro.isDisponible()) {
                libro.mostrar();
                disponibles++;
            }
        }
        if (disponibles == 0) {
            std::cout << "Actualmente no hay libros disponibles." << std::endl;
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};


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
        limpiarBuffer(); // Muy importante para que getline funcione bien después de cin

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