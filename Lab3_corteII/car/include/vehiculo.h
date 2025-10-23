#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa);
    virtual ~Vehiculo();

    std::string getPlaca() const;
    bool isDisponible() const;

    void alquilar();
    void devolver();

    virtual void mostrarInformacion() const;
};

#endif // VEHICULO_H
