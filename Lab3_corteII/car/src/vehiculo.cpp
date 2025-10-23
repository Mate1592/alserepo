#include "vehiculo.h"

Vehiculo::Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa)
    : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

Vehiculo::~Vehiculo() {}

std::string Vehiculo::getPlaca() const {
    return placa;
}

bool Vehiculo::isDisponible() const {
    return disponible;
}

void Vehiculo::alquilar() {
    if (disponible) {
        disponible = false;
    }
}

void Vehiculo::devolver() {
    if (!disponible) {
        disponible = true;
    }
}

void Vehiculo::mostrarInformacion() const {
    std::cout << "  Marca: " << marca << " | Modelo: " << modelo << " | Placa: " << placa
              << " | Estado: " << (disponible ? "Disponible" : "Alquilado");
}
