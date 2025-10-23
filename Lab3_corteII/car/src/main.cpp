#include "sistema_alquiler.h"
#include <iostream>
#include <limits>

void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mostrarMenu() {
    std::cout << "\n===== SISTEMA DE ALQUILER DE VEHICULOS (C++) =====\n";
    std::cout << "1. Registrar Auto\n";
    std::cout << "2. Registrar Bicicleta\n";
    std::cout << "3. Mostrar Vehiculos Disponibles\n";
    std::cout << "4. Alquilar Vehiculo\n";
    std::cout << "5. Devolver Vehiculo\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    SistemaAlquiler sistema;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;
        limpiarBuffer();

        std::string marca, modelo, placa;

        switch (opcion) {
            case 1: {
                int capacidad;
                std::cout << "Marca del auto: "; std::getline(std::cin, marca);
                std::cout << "Modelo del auto: "; std::getline(std::cin, modelo);
                std::cout << "Placa del auto: "; std::getline(std::cin, placa);
                std::cout << "Capacidad de pasajeros: "; std::cin >> capacidad;
                limpiarBuffer();
                sistema.registrarAuto(marca, modelo, placa, capacidad);
                break;
            }
            case 2: {
                int tieneCanastaInt;
                std::cout << "Marca de la bicicleta: "; std::getline(std::cin, marca);
                std::cout << "Modelo de la bicicleta: "; std::getline(std::cin, modelo);
                std::cout << "Placa (o ID) de la bicicleta: "; std::getline(std::cin, placa);
                std::cout << "Tiene canasta? (1=Si, 0=No): "; std::cin >> tieneCanastaInt;
                limpiarBuffer();
                sistema.registrarBicicleta(marca, modelo, placa, (tieneCanastaInt == 1));
                break;
            }
            case 3:
                sistema.mostrarVehiculosDisponibles();
                break;
            case 4:
                std::cout << "Ingrese placa del vehiculo a alquilar: ";
                std::getline(std::cin, placa);
                sistema.alquilarVehiculo(placa);
                break;
            case 5:
                std::cout << "Ingrese placa del vehiculo a devolver: ";
                std::getline(std::cin, placa);
                sistema.devolverVehiculo(placa);
                break;
            case 0:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
