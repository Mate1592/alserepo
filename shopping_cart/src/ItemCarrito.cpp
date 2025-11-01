#include "ItemCarrito.h"

// Constructor que inicializa un ítem del carrito con un producto y una cantidad.
ItemCarrito::ItemCarrito(Producto* producto, int cantidad)
    : producto(producto), cantidad(cantidad) {}

// Obtiene el producto del ítem.
Producto* ItemCarrito::getProducto() const {
    return producto;
}

// Obtiene la cantidad del producto en el ítem.
int ItemCarrito::getCantidad() const {
    return cantidad;
}

// Calcula el subtotal del ítem.
double ItemCarrito::getSubtotal() const {
    return producto->getPrecio() * cantidad;
}
