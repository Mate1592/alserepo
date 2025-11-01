#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
public:
    // Constructor para inicializar un producto.
    Producto(const std::string& nombre, double precio, int stock);

    // Métodos para obtener los atributos del producto.
    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    // Método para actualizar el stock.
    void setStock(int stock);

private:
    std::string nombre;
    double precio;
    int stock;
};

#endif // PRODUCTO_H
