#include "DispositivoInteligente.h"

#include <iostream>

/**
 * @brief Constructor: inicializa los atributos del dispositivo.
 * Por defecto, el dispositivo se crea apagado y con el control remoto
 * desbloqueado.
 */
DispositivoInteligente::DispositivoInteligente(std::string nombre,
                                               float consumoEnergia)
    : nombre_(nombre),
      consumoEnergia_(consumoEnergia),
      estado_(false),
      controlRemotoBloqueado_(false) {}

/**
 * @brief Enciende el dispositivo.
 * Cambia el estado a 'true' (encendido).
 */
void DispositivoInteligente::encender() {
    if (!controlRemotoBloqueado_) {
        estado_ = true;
    }
}

/**
 * @brief Apaga el dispositivo.
 * Cambia el estado a 'false' (apagado).
 */
void DispositivoInteligente::apagar() {
    if (!controlRemotoBloqueado_) {
        estado_ = false;
    }
}

/**
 * @brief Bloquea el control remoto.
 * Evita que el dispositivo se encienda o apague.
 */
void DispositivoInteligente::bloquearControlRemoto() {
    controlRemotoBloqueado_ = true;
}

/**
 * @brief Desbloquea el control remoto.
 * Permite que el dispositivo vuelva a ser controlado.
 */
void DispositivoInteligente::desbloquearControlRemoto() {
    controlRemotoBloqueado_ = false;
}

/**
 * @brief Calcula el consumo de energía en un período determinado.
 * @param horas Número de horas de funcionamiento.
 * @return Consumo total en vatios. Si el dispositivo está apagado, retorna 0.
 */
float DispositivoInteligente::medirConsumo(float horas) const {
    if (getEstado()) {
        return consumoEnergia_ * horas;
    }
    return 0.0f;
}

/**
 * @brief Obtiene el nombre del dispositivo.
 * @return El nombre asignado al dispositivo.
 */
std::string DispositivoInteligente::getNombre() const { return nombre_; }

/**
 * @brief Verifica el estado del dispositivo.
 * @return true si está encendido, false si está apagado.
 */
bool DispositivoInteligente::getEstado() const { return estado_; }

/**
 * @brief Verifica si el control remoto está bloqueado.
 * @return true si está bloqueado, false en caso contrario.
 */
bool DispositivoInteligente::estaBloqueado() const {
    return controlRemotoBloqueado_;
}