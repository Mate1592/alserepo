#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include "vehiculo.h"
#include "auto.h"
#include "bicicleta.h"
#include <vector>
#include <string>

class SistemaAlquiler {
private:
    std::vector<Vehiculo*> inventario;

public:
    ~SistemaAlquiler();

    void registrarAuto(const std::string& marca, const std::string& modelo, const std::string& placa, int capacidad);
    void registrarBicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta);
    void mostrarVehiculosDisponibles() const;
    Vehiculo* buscarVehiculo(const std::string& placa);
    void alquilarVehiculo(const std::string& placa);
    void devolverVehiculo(const std::string& placa);
};

#endif // SISTEMA_ALQUILER_H
