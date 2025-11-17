#include "libro.h"

Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(true) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getISBN() const { return isbn; }
bool Libro::isDisponible() const { return disponible; }

void Libro::mostrar() const {
    std::cout << "  - Titulo: " << titulo << "\n"
              << "    Autor: " << autor << "\n"
              << "    ISBN: " << isbn << "\n"
              << "    Disponible: " << (disponible ? "Si" : "No") << std::endl;
}
