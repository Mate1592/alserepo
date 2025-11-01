#include "Usuario.h"
#include <iostream>

// Constructor que inicializa un usuario con su nombre.
Usuario::Usuario(const std::string& nombre) : nombre(nombre) {}

// Agrega un carrito de compras al historial del usuario.
void Usuario::agregarCompra(const CarritoCompras& carrito) {
    historialDeCompras.push_back(carrito);
    for (const auto& item : carrito.getItems()) {
        item.getProducto()->setStock(item.getProducto()->getStock() - item.getCantidad());
    }
}

// Muestra el historial de compras del usuario.
void Usuario::verHistorialDeCompras() const {
    std::cout << "Historial de compras de " << nombre << ":" << std::endl;
    if (historialDeCompras.empty()) {
        std::cout << "No hay compras en el historial." << std::endl;
        return;
    }
    int i = 1;
    for (const auto& carrito : historialDeCompras) {
        std::cout << "--- Compra " << i++ << " ---" << std::endl;
        carrito.verCarrito();
        std::cout << "Total: " << carrito.calcularTotal() << std::endl;
    }
}
