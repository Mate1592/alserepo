#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "libro.h"
#include <vector>
#include <string>

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const std::string& titulo, const std::string& autor, const std::string& isbn);
    void eliminarLibro(const std::string& isbn);
    void buscarLibros(const std::string& clave) const;
    void mostrarLibrosDisponibles() const;
};

#endif // BIBLIOTECA_H
