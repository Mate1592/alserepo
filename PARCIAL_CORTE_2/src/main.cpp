#include <fstream>
#include <iostream>
#include <vector>

#include "DispositivoInteligente.h"

// --- Función para generar el reporte de consumo ---
void generarReporte(
    const std::vector<DispositivoInteligente>& dispositivos,
    const std::vector<float>& consumos) {
    std::ofstream reporte("reporte_consumo.txt");
    if (reporte.is_open()) {
        reporte << "--- Reporte de Consumo Energético ---" << std::endl;
        for (size_t i = 0; i < dispositivos.size(); ++i) {
            reporte << "Dispositivo: " << dispositivos[i].getNombre()
                    << ", Consumo Total: " << consumos[i] << " Vatios"
                    << std::endl;
        }
        reporte.close();
        std::cout << "Reporte 'reporte_consumo.txt' generado exitosamente."
                  << std::endl;
    } else {
        std::cerr << "Error: No se pudo crear el archivo de reporte."
                  << std::endl;
    }
}

// --- Función Principal ---
int main() {
    // I. Usar contenedores de la STL para almacenar dispositivos
    std::vector<DispositivoInteligente> dispositivos;
    dispositivos.push_back(
        DispositivoInteligente("Lámpara de Escritorio", 15.5f));
    dispositivos.push_back(DispositivoInteligente("Ventilador de Torre", 45.0f));
    dispositivos.push_back(
        DispositivoInteligente("Cargador de Laptop", 65.0f));

    std::cout << "--- Simulación de Hogar Inteligente ---" << std::endl;

    // II. Simular lectura de datos y registro de consumo
    std::vector<float> consumoTotal(dispositivos.size(), 0.0f);

    // Simulación: Encender dispositivos y medir consumo por 3.5 horas
    std::cout << "\n1. Encendiendo dispositivos y usando por 3.5 horas..."
              << std::endl;
    for (size_t i = 0; i < dispositivos.size(); ++i) {
        dispositivos[i].encender();
        consumoTotal[i] += dispositivos[i].medirConsumo(3.5f);
        std::cout << "- " << dispositivos[i].getNombre()
                  << " encendido. Consumo registrado." << std::endl;
    }

    // Simulación: Apagar un dispositivo y medir consumo por 2 horas más
    std::cout << "\n2. Apagando la lámpara y usando el resto por 2 horas..."
              << std::endl;
    dispositivos[0].apagar();
    std::cout << "- " << dispositivos[0].getNombre() << " ha sido apagado."
              << std::endl;

    for (size_t i = 0; i < dispositivos.size(); ++i) {
        consumoTotal[i] += dispositivos[i].medirConsumo(2.0f);
    }

    // Simulación: Bloquear el control remoto del ventilador
    std::cout << "\n3. Bloqueando el control del ventilador..." << std::endl;
    dispositivos[1].bloquearControlRemoto();
    std::cout << "- Intentando apagar el ventilador (debería fallar)..."
              << std::endl;
    dispositivos[1].apagar();  // No debería cambiar el estado

    if (dispositivos[1].getEstado()) {
        std::cout << "- El ventilador sigue encendido (control bloqueado)."
                  << std::endl;
    }

    // Apagar todos los dispositivos al final
    std::cout << "\n--- Fin de la Simulación ---" << std::endl;
    for (auto& dispositivo : dispositivos) {
        dispositivo.desbloquearControlRemoto();  // Desbloquear por si acaso
        dispositivo.apagar();
    }

    // III. (BONO) Generar un reporte en formato .txt
    generarReporte(dispositivos, consumoTotal);

    return 0;
}