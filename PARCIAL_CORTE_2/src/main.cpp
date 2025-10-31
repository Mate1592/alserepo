#include <fstream>
#include <iomanip>  // Para std::setw y std::left
#include <iostream>
#include <vector>

#include "DispositivoInteligente.h"

// --- Función para generar el reporte de consumo (BONO) ---
void generarReporte(
    const std::vector<DispositivoInteligente>& dispositivos,
    const std::vector<float>& consumos) {
    std::ofstream reporte("reporte_consumo.txt");
    if (reporte.is_open()) {
        reporte << "--- Reporte Final de Consumo Energético Diario ---"
                << std::endl;
        reporte << "----------------------------------------------------"
                << std::endl;
        for (size_t i = 0; i < dispositivos.size(); ++i) {
            reporte << std::left << std::setw(30)
                    << "Dispositivo (ID): " + dispositivos[i].getNombre()
                    << "Consumo Total: " << std::fixed << std::setprecision(2)
                    << consumos[i] << " Vatios-hora" << std::endl;
        }
        reporte << "----------------------------------------------------"
                << std::endl;
        reporte.close();
        std::cout << "\n[INFO] Reporte 'reporte_consumo.txt' generado "
                     "exitosamente en la carpeta 'build'."
                  << std::endl;
    } else {
        std::cerr << "[ERROR] No se pudo crear el archivo de reporte."
                  << std::endl;
    }
}

// --- Función Principal ---
int main() {
    // I. Usar contenedores de la STL para almacenar dispositivos
    std::cout << "--- Configurando el Hogar Inteligente ---" << std::endl;
    std::vector<DispositivoInteligente> dispositivos;

<<<<<<< HEAD
    // Lista de dispositivos a crear
    std::vector<std::pair<std::string, float>> dispositivosACrear = {
        {"Asistente de Voz", 3.0f},
        {"Cafetera Expreso", 1200.0f},
        {"Lámpara Dormitorio", 10.0f},
        {"TV 65 pulgadas", 150.0f},
        {"Consola de Videojuegos", 200.0f},
        {"Cargador de Laptop", 65.0f}
    };
=======
    std::cout << " Simulación de Hogar Inteligente " << std::endl;
>>>>>>> 1dc127f (correccion con los dispositivos simulados)

    std::cout << "Registrando dispositivos..." << std::endl;
    for (const auto& d : dispositivosACrear) {
        dispositivos.push_back(DispositivoInteligente(d.first, d.second));
        std::cout << "- " << d.first << " (Consumo base: " << d.second
                  << " Vatios/hora)" << std::endl;
    }

    // II. Simular lectura de datos y registro de consumo a lo largo de un día
    std::cout << "\n--- Iniciando Simulación de un Día Completo ---"
              << std::endl;
    std::vector<float> consumoTotal(dispositivos.size(), 0.0f);

    // El asistente de voz siempre está en modo de bajo consumo (24 horas)
    dispositivos[0].encender();
    consumoTotal[0] += dispositivos[0].medirConsumo(24.0f);

    // --- Rutina de la Mañana (2 horas de actividad) ---
    std::cout << "\n[MAÑANA - 7:00 AM a 9:00 AM]" << std::endl;
    // La cafetera se usa por 15 minutos (0.25 horas)
    dispositivos[1].encender();
    consumoTotal[1] += dispositivos[1].medirConsumo(0.25f);
    dispositivos[1].apagar();
    std::cout << "- Cafetera utilizada para el desayuno." << std::endl;

    // La lámpara del dormitorio se enciende 1 hora
    dispositivos[2].encender();
    consumoTotal[2] += dispositivos[2].medirConsumo(1.0f);
    dispositivos[2].apagar();
    std::cout << "- Lámpara del dormitorio encendida mientras se prepara para el día." << std::endl;

    // --- Rutina de la Tarde (4 horas de trabajo) ---
    std::cout << "\n[TARDE - 1:00 PM a 5:00 PM]" << std::endl;
    // El cargador de la laptop se usa durante la jornada de trabajo
    dispositivos[5].encender();
    consumoTotal[5] += dispositivos[5].medirConsumo(4.0f);
    dispositivos[5].apagar();
    std::cout << "- Laptop cargando durante las horas de trabajo." << std::endl;

    // --- Rutina de la Noche (4 horas de ocio) ---
    std::cout << "\n[NOCHE - 7:00 PM a 11:00 PM]" << std::endl;
    // La TV se enciende por 3 horas
    dispositivos[3].encender();
    consumoTotal[3] += dispositivos[3].medirConsumo(3.0f);
    std::cout << "- TV encendida para ver series." << std::endl;

    // La consola se enciende por 2 horas junto a la TV
    dispositivos[4].encender();
    consumoTotal[4] += dispositivos[4].medirConsumo(2.0f);
    std::cout << "- Noche de videojuegos en la consola." << std::endl;

    // Al final de la noche, se apagan todos los dispositivos de ocio
    dispositivos[3].apagar();
    dispositivos[4].apagar();
    std::cout << "- TV y consola apagadas al final del día." << std::endl;


    // Demostración de bloqueo de control remoto
    std::cout << "\n[DEMO] Bloqueando la lámpara para evitar que se encienda..." << std::endl;
    dispositivos[2].bloquearControlRemoto();
    dispositivos[2].encender(); // Intento fallido
    if (!dispositivos[2].getEstado()) {
        std::cout << "- La lámpara no se pudo encender (control bloqueado)." << std::endl;
    }
    dispositivos[2].desbloquearControlRemoto(); // Se desbloquea

<<<<<<< HEAD
    // --- Fin de la Simulación ---
    std::cout << "\n--- Fin de la Simulación ---" << std::endl;
=======
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
    std::cout << " Intentando apagar el ventilador (debería fallar)"
              << std::endl;
    dispositivos[1].apagar();  // No debería cambiar el estado

    if (dispositivos[1].getEstado()) {
        std::cout << "El ventilador sigue encendido (control bloqueado)."
                  << std::endl;
    }

    // Apagar todos los dispositivos al final
    std::cout << "\n Fin de la Simulación " << std::endl;
    for (auto& dispositivo : dispositivos) {
        dispositivo.desbloquearControlRemoto();  // Desbloquear por si acaso
        dispositivo.apagar();
    }
>>>>>>> 1dc127f (correccion con los dispositivos simulados)

    // III.reporte en formato .txt
    generarReporte(dispositivos, consumoTotal);

    return 0;
}