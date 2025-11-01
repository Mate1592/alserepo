#include <iostream>
#include <vector>
#include <limits>
#include "include/Producto.h"
#include "include/ItemCarrito.h"
#include "include/CarritoCompras.h"
#include "include/Usuario.h"

// Función para mostrar los productos disponibles
void mostrarProductos(const std::vector<Producto>& productos) {
    std::cout << "\n--- Productos Disponibles ---" << std::endl;
    for (size_t i = 0; i < productos.size(); ++i) {
        std::cout << i + 1 << ". " << productos[i].getNombre()
                  << " - Precio: " << productos[i].getPrecio()
                  << " (Stock: " << productos[i].getStock() << ")" << std::endl;
    }
}

int main() {
    // Creación de una lista de productos disponibles en la tienda
    std::vector<Producto> productosDisponibles;
    productosDisponibles.push_back(Producto("Laptop", 1200.00, 10));
    productosDisponibles.push_back(Producto("Telefono", 800.00, 20));
    productosDisponibles.push_back(Producto("Audifonos", 150.00, 30));

    // Creación de un usuario
    Usuario usuario("JuanPerez");
    CarritoCompras carritoActual;

    int opcion = 0;
    while (opcion != 5) {
        std::cout << "\n--- Menu de la Tienda ---" << std::endl;
        std::cout << "1. Ver productos" << std::endl;
        std::cout << "2. Agregar producto al carrito" << std::endl;
        std::cout << "3. Ver carrito" << std::endl;
        std::cout << "4. Finalizar compra" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;

        // Limpiar el buffer de entrada en caso de que el usuario ingrese algo que no sea un número
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida. Por favor, ingrese un numero." << std::endl;
            continue;
        }

        switch (opcion) {
            case 1:
                mostrarProductos(productosDisponibles);
                break;
            case 2: {
                mostrarProductos(productosDisponibles);
                int eleccionProducto = 0;
                std::cout << "Seleccione el producto que desea agregar: ";
                std::cin >> eleccionProducto;

                if (std::cin.fail() || eleccionProducto < 1 || eleccionProducto > productosDisponibles.size()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Seleccion invalida." << std::endl;
                    break;
                }

                int cantidad = 0;
                std::cout << "Ingrese la cantidad: ";
                std::cin >> cantidad;

                if (std::cin.fail() || cantidad <= 0) {
                     std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Cantidad invalida." << std::endl;
                    break;
                }

                // El producto se pasa por puntero para que el stock se pueda modificar
                carritoActual.agregarProducto(ItemCarrito(&productosDisponibles[eleccionProducto - 1], cantidad));
                break;
            }
            case 3:
                std::cout << "\n--- Contenido del Carrito ---" << std::endl;
                carritoActual.verCarrito();
                std::cout << "Total actual: " << carritoActual.calcularTotal() << std::endl;
                break;
            case 4:
                if (carritoActual.getItems().empty()) {
                    std::cout << "El carrito esta vacio. No se puede finalizar la compra." << std::endl;
                } else {
                    usuario.agregarCompra(carritoActual);
                    std::cout << "Compra finalizada con exito. Su carrito ha sido guardado en su historial." << std::endl;
                    // Se crea un nuevo carrito para la siguiente compra
                    carritoActual = CarritoCompras();
                }
                break;
            case 5:
                std::cout << "Gracias por su visita." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    }

    // Al final, se puede mostrar el historial de compras del usuario
    std::cout << "\n--- Resumen Final ---" << std::endl;
    usuario.verHistorialDeCompras();

    std::cout << "\n--- Stock Final de Productos ---" << std::endl;
    mostrarProductos(productosDisponibles);

    return 0;
}
