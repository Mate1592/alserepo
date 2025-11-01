#include "Producto.h"

// Constructor que inicializa un producto con su nombre, precio y stock.
Producto::Producto(const std::string& nombre, double precio, int stock)
    : nombre(nombre), precio(precio), stock(stock) {}

// Obtiene el nombre del producto.
std::string Producto::getNombre() const {
    return nombre;
}

// Obtiene el precio del producto.
double Producto::getPrecio() const {
    return precio;
}

// Obtiene el stock disponible del producto.
int Producto::getStock() const {
    return stock;
}

// Establece el stock del producto.
void Producto::setStock(int nuevoStock) {
    stock = nuevoStock;
}
