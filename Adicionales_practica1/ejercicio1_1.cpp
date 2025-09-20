
//adicionales practica 1 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int numProductos;
    double subtotal = 0.0;
    double impuesto, costoTotal;
    const double TASA_IMPUESTO = 0.08;  // 8% de impuesto
    const double TASA_DESCUENTO = 0.10; // 10% de descuento
    const double LIMITE_DESCUENTO = 100.0; // Descuento aplica si es mayor a $100
    
    cout << "CALCULADORA TIENDA DE ABASTOS " << endl << endl;
    
    // Solicitar númro de producto
    cout << "¿Cuántos productos va a comprar? ";
    cin >> numProductos;
    
    cout << endl << "Ingrese el precio y cantidad de cada producto:" << endl;
    
    // Capturar información de cada producto
    for (int i = 1; i <= numProductos; i++) {
        double precio, cantidad, totalProducto;
        
        cout << "Producto " << i << ":" << endl;
        cout << "  Precio unitario: $";
        cin >> precio;
        cout << "  Cantidad: ";
        cin >> cantidad;
        
        totalProducto = precio * cantidad;
        subtotal += totalProducto;
        
        cout << "  Total del producto: $" << fixed << setprecision(2) << totalProducto << endl << endl;
    }
    
    // Calcular impuesto
    impuesto = subtotal * TASA_IMPUESTO;
    
    // Calcular costo total antes del descuento
    costoTotal = subtotal + impuesto;
    
    // Mostrar resultados
    cout << "-RESUMEN DE LA COMPRA- " << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Impuesto (8%): $" << impuesto << endl;
    cout << "Total antes de descuento: $" << costoTotal << endl;
    
    // Aplicar descuento si corresponde
    if (costoTotal > LIMITE_DESCUENTO) {
        double descuento = costoTotal * TASA_DESCUENTO;
        costoTotal -= descuento;
        
        cout << "Descuento aplicado (10%) -$" << descuento << endl;
        cout << "COSTO TOTAL FINAL: $" << costoTotal << endl;
    } else {
        cout << "COSTO TOTAL FINAL: $" << costoTotal << endl;
        cout << "(No se aplica descuento - total menor a 100)" << endl;
    }
    
    return 0;
}