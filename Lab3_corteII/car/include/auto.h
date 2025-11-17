#ifndef AUTO_H
#define AUTO_H

#include "vehiculo.h"

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(const std::string& marca, const std::string& modelo, const std::string& placa, int capacidad);

    void mostrarInformacion() const override;
};

#endif // AUTO_H
