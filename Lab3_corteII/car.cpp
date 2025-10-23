#include <iostream>
#include <vector>
#include <string>
#include <limits> // Necesario para std::numeric_limits


class Vehiculo {
protected: // protected para que las clases derivadas puedan acceder
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    // Constructor
    Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa)
        : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

    // Destructor virtual: crucial para la correcta liberación de memoria en polimorfismo
    virtual ~Vehiculo() {}

    // --- Métodos de acceso ---
    std::string getPlaca() const {
        return placa;
    }

    bool isDisponible() const {
        return disponible;
    }
    
    // --- Métodos de estado ---
    void alquilar() {
        if (disponible) {
            disponible = false;
        }
    }

    void devolver() {
        if (!disponible) {
            disponible = true;
        }
    }

    // --- MÉTODO VIRTUAL ---
    // Permite que las clases derivadas lo personalicen (polimorfismo)
    virtual void mostrarInformacion() const {
        std::cout << "  Marca: " << marca << " | Modelo: " << modelo << " | Placa: " << placa
                  << " | Estado: " << (disponible ? "Disponible" : "Alquilado");
    }
};



// Clase Auto hereda de Vehiculo
class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    // El constructor de Auto llama al constructor de Vehiculo
    Auto(const std::string& marca, const std::string& modelo, const std::string& placa, int capacidad)
        : Vehiculo(marca, modelo, placa), capacidadPasajeros(capacidad) {}

    // Personalización del método (override)
    void mostrarInformacion() const override {
        std::cout << "[AUTO] ";
        Vehiculo::mostrarInformacion(); // Llama al método de la clase base
        std::cout << " | Pasajeros: " << capacidadPasajeros << std::endl;
    }
};

// Clase Bicicleta hereda de Vehiculo
class Bicicleta : public Vehiculo {
private:
    bool tieneCanasta;

public:
    Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta)
        : Vehiculo(marca, modelo, placa), tieneCanasta(canasta) {}

    // Personalización del método (override)
    void mostrarInformacion() const override {
        std::cout << "[BICI] ";
        Vehiculo::mostrarInformacion(); // Llama al método de la clase base
        std::cout << " | Canasta: " << (tieneCanasta ? "Sí" : "No") << std::endl;
    }
};



//SISTEMA DE ALQUILER

class SistemaAlquiler {
private:
    // Un único vector que guarda punteros a Vehiculo.
    // Esto permite almacenar objetos de cualquier clase derivada (Autos, Bicicletas, etc.)
    std::vector<Vehiculo*> inventario;

public:
    // El destructor se encarga de liberar la memoria de todos los vehículos creados
    ~SistemaAlquiler() {
        for (Vehiculo* v : inventario) {
            delete v; // Libera la memoria de cada objeto
        }
        inventario.clear();
    }
    
    // --- Métodos de gestión ---
    void registrarAuto(const std::string& marca, const std::string& modelo, const std::string& placa, int capacidad) {
        inventario.push_back(new Auto(marca, modelo, placa, capacidad));
        std::cout << "--> Auto registrado correctamente." << std::endl;
    }

    void registrarBicicleta(const std::string& marca, const std::string& modelo, const std::string& placa, bool canasta) {
        inventario.push_back(new Bicicleta(marca, modelo, placa, canasta));
        std::cout << "--> Bicicleta registrada correctamente." << std::endl;
    }

    void mostrarVehiculosDisponibles() const {
        std::cout << "\n--- VEHICULOS DISPONIBLES ---" << std::endl;
        bool hayDisponibles = false;
        for (const Vehiculo* v : inventario) {
            if (v->isDisponible()) {
                v->mostrarInformacion(); // Polimorfismo en acción
                hayDisponibles = true;
            }
        }
        if (!hayDisponibles) {
            std::cout << "No hay vehículos disponibles en este momento." << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    
    Vehiculo* buscarVehiculo(const std::string& placa) {
        for (Vehiculo* v : inventario) {
            if (v->getPlaca() == placa) {
                return v;
            }
        }
        return nullptr; // nullptr si no se encuentra
    }

    void alquilarVehiculo(const std::string& placa) {
        Vehiculo* v = buscarVehiculo(placa);
        if (v != nullptr && v->isDisponible()) {
            v->alquilar();
            std::cout << "--> Vehiculo con placa " << placa << " alquilado exitosamente." << std::endl;
        } else {
            std::cout << "--> Error: Vehiculo no encontrado o no disponible." << std::endl;
        }
    }

    void devolverVehiculo(const std::string& placa) {
        Vehiculo* v = buscarVehiculo(placa);
        if (v != nullptr && !v->isDisponible()) {
            v->devolver();
            std::cout << "--> Vehiculo con placa " << placa << " devuelto exitosamente." << std::endl;
        } else {
            std::cout << "--> Error: Vehiculo no encontrado o ya estaba disponible." << std::endl;
        }
    }
};


// FUNCIÓN PRINCIPAL 

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
        limpiarBuffer(); // Importante para limpiar el buffer después de leer un número

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