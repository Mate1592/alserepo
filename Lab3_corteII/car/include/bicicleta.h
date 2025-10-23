#ifndef BICICLETA_H
#define BICICLETA_H

#include "vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    bool tieneCanasta;

public:
    Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta);

    void mostrarInformacion() const override;
};

#endif // BICICLETA_H
