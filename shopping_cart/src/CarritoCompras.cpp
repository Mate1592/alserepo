#include "CarritoCompras.h"
#include <iostream>
#include <algorithm> // Para std::remove_if

// Agrega un ítem al carrito.
void CarritoCompras::agregarProducto(const ItemCarrito& item) {
    if (item.getProducto()->getStock() >= item.getCantidad()) {
        items.push_back(item);
    } else {
        std::cout << "No hay stock suficiente para " << item.getProducto()->getNombre() << std::endl;
    }
}

// Elimina un producto del carrito por su nombre.
void CarritoCompras::eliminarProducto(const std::string& nombreProducto) {
    items.erase(
        std::remove_if(items.begin(), items.end(),
                       [&](const ItemCarrito& item) {
                           return item.getProducto()->getNombre() == nombreProducto;
                       }),
        items.end());
}

// Calcula el total de la compra.
double CarritoCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getSubtotal();
    }
    return total;
}

// Muestra los productos en el carrito.
void CarritoCompras::verCarrito() const {
    if (items.empty()) {
        std::cout << "El carrito de compras está vacío." << std::endl;
        return;
    }
    for (const auto& item : items) {
        std::cout << "Producto: " << item.getProducto()->getNombre()
                  << ", Cantidad: " << item.getCantidad()
                  << ", Subtotal: " << item.getSubtotal() << std::endl;
    }
}

// Obtiene los ítems del carrito.
const std::vector<ItemCarrito>& CarritoCompras::getItems() const {
    return items;
}
