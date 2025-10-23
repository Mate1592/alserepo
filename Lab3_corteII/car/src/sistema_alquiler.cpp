#include "sistema_alquiler.h"

SistemaAlquiler::~SistemaAlquiler() {
    for (Vehiculo* v : inventario) {
        delete v;
    }
    inventario.clear();
}

void SistemaAlquiler::registrarAuto(const std::string& marca, const std::string& modelo, const std::string& placa, int capacidad) {
    inventario.push_back(new Auto(marca, modelo, placa, capacidad));
    std::cout << "--> Auto registrado correctamente." << std::endl;
}

void SistemaAlquiler::registrarBicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta) {
    inventario.push_back(new Bicicleta(marca, modelo, placa, canasta));
    std::cout << "--> Bicicleta registrada correctamente." << std::endl;
}

void SistemaAlquiler::mostrarVehiculosDisponibles() const {
    std::cout << "\n--- VEHICULOS DISPONIBLES ---" << std::endl;
    bool hayDisponibles = false;
    for (const Vehiculo* v : inventario) {
        if (v->isDisponible()) {
            v->mostrarInformacion();
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles) {
        std::cout << "No hay vehículos disponibles en este momento." << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

Vehiculo* SistemaAlquiler::buscarVehiculo(const std::string& placa) {
    for (Vehiculo* v : inventario) {
        if (v->getPlaca() == placa) {
            return v;
        }
    }
    return nullptr;
}

void SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    Vehiculo* v = buscarVehiculo(placa);
    if (v != nullptr && v->isDisponible()) {
        v->alquilar();
        std::cout << "--> Vehiculo con placa " << placa << " alquilado exitosamente." << std::endl;
    } else {
        std::cout << "--> Error: Vehiculo no encontrado o no disponible." << std::endl;
    }
}

void SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    Vehiculo* v = buscarVehiculo(placa);
    if (v != nullptr && !v->isDisponible()) {
        v->devolver();
        std::cout << "--> Vehiculo con placa " << placa << " devuelto exitosamente." << std::endl;
    } else {
        std::cout << "--> Error: Vehiculo no encontrado o ya estaba disponible." << std::endl;
    }
}
