#include "bicicleta.h"

Bicicleta::Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta)
    : Vehiculo(marca, modelo, placa), tieneCanasta(canasta) {}

void Bicicleta::mostrarInformacion() const {
    std::cout << "[BICI] ";
    Vehiculo::mostrarInformacion();
    std::cout << " | Canasta: " << (tieneCanasta ? "Sí" : "No") << std::endl;
}
