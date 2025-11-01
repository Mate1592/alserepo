#include <iostream>
#include "include/Producto.h"
#include "include/ItemCarrito.h"
#include "include/CarritoCompras.h"
#include "include/Usuario.h"

int main() {
    // Creación de productos
    Producto laptop("Laptop", 1200.00, 10);
    Producto telefono("Teléfono", 800.00, 20);
    Producto audifonos("Audífonos", 150.00, 30);

    // Creación de un usuario
    Usuario usuario("JuanPerez");

    // El usuario realiza una compra
    CarritoCompras carrito1;
    carrito1.agregarProducto(ItemCarrito(&laptop, 1));
    carrito1.agregarProducto(ItemCarrito(&audifonos, 2));

    std::cout << "--- Carrito de Compras 1 ---" << std::endl;
    carrito1.verCarrito();
    std::cout << "Total de la compra: " << carrito1.calcularTotal() << std::endl;

    usuario.agregarCompra(carrito1);

    // El usuario realiza otra compra
    CarritoCompras carrito2;
    carrito2.agregarProducto(ItemCarrito(&telefono, 1));

    std::cout << "\n--- Carrito de Compras 2 ---" << std::endl;
    carrito2.verCarrito();
    std::cout << "Total de la compra: " << carrito2.calcularTotal() << std::endl;

    usuario.agregarCompra(carrito2);

    // Ver el historial de compras del usuario
    std::cout << "\n--- Historial de Compras ---" << std::endl;
    usuario.verHistorialDeCompras();

    // Verificar el stock de los productos
    std::cout << "\n--- Stock de Productos ---" << std::endl;
    std::cout << "Stock de Laptop: " << laptop.getStock() << std::endl;
    std::cout << "Stock de Teléfono: " << telefono.getStock() << std::endl;
    std::cout << "Stock de Audífonos: " << audifonos.getStock() << std::endl;

    return 0;
}
