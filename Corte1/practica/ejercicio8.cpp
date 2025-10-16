//Ejercicio 8 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen
//Cálculo de Interés compuesto

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double P, r, A;
    int n, t;
    
    cout << "CALCULADORA DE INTERES COMPUESTO" << endl << endl;
    
    // Solicitar datos 
    cout << "Ingrese cantidad inicial invertida: ";
    cin >> P;
    
    cout << "Ingrese la tasa de interes anual en decimal: ";
    cin >> r;
    
    cout << "Ingrese el numero de veces que se aplica el interes al año: ";
    cin >> n;
    
    cout << "Ingrese el numero de años: ";
    cin >> t;
    
    // Calcular el monto final usando la fórmula: A = P(1 + r/n)^(nt)
    A = P * pow((1 + r/n), n * t);
    
    // Mostrar resultados con formato
    cout << fixed << setprecision(2);
    cout << endl << "RESULTADO" << endl;
    cout << "inicial: $" << P << endl;
    cout << "Tasa de interes anual: " << (r * 100) << "%" << endl;
    cout << "Periodo de inversion: " << t << " años" << endl;
    cout << "Monto final: $" << A << endl;
    cout << "Interes ganado: $" << (A - P) << endl;
    
    return 0;
}
