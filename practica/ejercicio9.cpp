//Ejercicio 9 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen
//Máximo Común Divisor (MCD)

#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el MCD 
int calcularMCD(int a, int b) {
    // Convertir a y b a valores absolutos
    a = abs(a);
    b = abs(b);
    
    // Algoritmo con variable auxiliar
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int main() {
    int numero1, numero2, mcd;
    
    cout << "CALCULADORA DEL MAXIMO COMUN DIVISOR " << endl << endl;
    
    // Solicitar los dos números
    cout << "Ingrese el primer número: ";
    cin >> numero1;
    
    cout << "Ingrese el segundo número: ";
    cin >> numero2;
  
    mcd = calcularMCD(numero1, numero2);
    
    // Mostrar resultados
    cout << endl << "RESULTADOS " << endl;
    cout << "Número 1: " << numero1 a<< endl;
    cout << "Número 2: " << numero2 << endl;
    cout << "El MCD de " << numero1 << " y " << numero2 << " es: " << mcd << endl;
    return 0;
}
 