#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

public:
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn);

    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool isDisponible() const;

    void mostrar() const;
};

#endif // LIBRO_H
