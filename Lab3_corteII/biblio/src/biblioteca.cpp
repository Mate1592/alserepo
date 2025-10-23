#include "biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const std::string& titulo, const std::string& autor, const std::string& isbn) {
    auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& libro) {
        return libro.getISBN() == isbn;
    });

    if (it != libros.end()) {
        std::cout << "--> Error: Ya existe un libro con el ISBN " << isbn << "." << std::endl;
    } else {
        libros.emplace_back(titulo, autor, isbn);
        std::cout << "--> Libro agregado exitosamente." << std::endl;
    }
}

void Biblioteca::eliminarLibro(const std::string& isbn) {
    auto it = std::find_if(libros.begin(), libros.end(), [&](const Libro& libro) {
        return libro.getISBN() == isbn;
    });

    if (it != libros.end()) {
        libros.erase(it);
        std::cout << "--> Libro con ISBN " << isbn << " eliminado correctamente." << std::endl;
    } else {
        std::cout << "--> Error: No se encontro ningun libro con ese ISBN." << std::endl;
    }
}

void Biblioteca::buscarLibros(const std::string& clave) const {
    std::cout << "\n--- Resultados de la busqueda para \"" << clave << "\" ---" << std::endl;
    int encontrados = 0;
    for (const auto& libro : libros) {
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

void Biblioteca::mostrarLibrosDisponibles() const {
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
