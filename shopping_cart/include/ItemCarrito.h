#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"

class ItemCarrito {
public:
    // Constructor para inicializar un ítem del carrito con un producto y una cantidad.
    ItemCarrito(Producto* producto, int cantidad);

    // Métodos para obtener los atributos del ítem.
    Producto* getProducto() const;
    int getCantidad() const;
    double getSubtotal() const;

private:
    Producto* producto;
    int cantidad;
};

#endif // ITEMCARRITO_H
