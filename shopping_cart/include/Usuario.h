#ifndef USUARIO_H
#define USUARIO_H

#include "CarritoCompras.h"
#include <string>
#include <vector>

class Usuario {
public:
    // Constructor para inicializar un usuario con su nombre.
    Usuario(const std::string& nombre);

    // Agrega un carrito de compras al historial del usuario.
    void agregarCompra(const CarritoCompras& carrito);

    // Muestra el historial de compras del usuario.
    void verHistorialDeCompras() const;

private:
    std::string nombre;
    std::vector<CarritoCompras> historialDeCompras;
};

#endif // USUARIO_H
