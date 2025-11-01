#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include "ItemCarrito.h"
#include <vector>

class CarritoCompras {
public:
    // Agrega un ítem al carrito.
    void agregarProducto(const ItemCarrito& item);

    // Elimina un producto del carrito por su nombre.
    void eliminarProducto(const std::string& nombreProducto);

    // Calcula el total de la compra.
    double calcularTotal() const;

    // Muestra los productos en el carrito.
    void verCarrito() const;

    // Obtiene los ítems del carrito.
    const std::vector<ItemCarrito>& getItems() const;

private:
    std::vector<ItemCarrito> items;
};

#endif // CARRITOCOMPRAS_H
