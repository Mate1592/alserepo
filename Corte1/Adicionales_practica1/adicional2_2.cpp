
//adicionales practica 2.2 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int NUM_CONDUCTORES = 10;
    float distancias[NUM_CONDUCTORES];
    float distanciaTotal = 0.0;
    float distanciaPromedio;
    float distanciaMaxima = 0.0;
    int conductorMaximo = 0;
    
    cout << "=== RASTREADOR DE DISTANCIAS - CONDUCTORES DE ENTREGAS ===" << endl << endl;
    
    // Capturar distancias de cada conductor
    cout << "Ingrese la distancia recorrida por cada conductor (en km):" << endl;
    
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        cout << "Conductor " << (i + 1) << ": ";
        cin >> distancias[i];
        
        // Acumular distancia total
        distanciaTotal += distancias[i];
        
        // Encontrar la distancia máxima y el conductor
        if (distancias[i] > distanciaMaxima) {
            distanciaMaxima = distancias[i];
            conductorMaximo = i + 1;
        }
    }
    
    // Calcular promedio
    distanciaPromedio = distanciaTotal / NUM_CONDUCTORES;
    
    // Mostrar resumen de distancias por conductor
    cout << endl << "=== DISTANCIAS REGISTRADAS ===" << endl;
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        cout << "Conductor " << (i + 1) << ": " << distancias[i] << " km" << endl;
    }
    
    
    cout << endl << " ESTADISTICAS" << endl;
    cout << "Distancia total recorrida por todos los conductores: " << distanciaTotal << " km" << endl;
    cout << "Distancia promedio por conductor: " << distanciaPromedio << " km" << endl;
    cout << "Conductor con mayor distancia: Conductor " << conductorMaximo 
         << " (" << distanciaMaxima << " km)" << endl;
    
    // Mostrar conductores por encima y debajo del promedio
    cout << endl << "RENDIMIENTO " << endl;
    cout << "Conductores por encima del promedio:" << endl;
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        if (distancias[i] > distanciaPromedio) {
            cout << "  - Conductor " << (i + 1) << ": " << distancias[i] << " km" << endl;
        }
    }
    
    cout << "Conductores por debajo del promedio:" << endl;
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        if (distancias[i] < distanciaPromedio) {
            cout << "  - Conductor " << (i + 1) << ": " << distancias[i] << " km" << endl;
        }
    }
    
    return 0;
}