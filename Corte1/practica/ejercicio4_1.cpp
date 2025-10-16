//Ejercicio 4.1 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen
//Sumar los elementos de un arreglo

#include <iostream>
using namespace std;

// Versión con función separada para la suma
int calcular_suma(int arr[], int n) {
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}



int main() {
  int arreglo[5];
    const int tamaño = 5;
    
  cout << " Entrada del usuario " << endl;
  cout << "Ingrese 5 números enteros:" << endl;
    
    // Leer elementos del usuario
    for(int i = 0; i < tamaño; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
    
    // Calcular suma
    int suma = calcular_suma(arreglo, tamaño);
    
    cout << "\nElementos ingresados: ";
    for(int i = 0; i < tamaño; i++) {
        cout << arreglo[i] << " ";
    }
    
    cout << "\nLa suma total es: " << suma << endl;
    return 0;
}
