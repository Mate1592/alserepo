#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Modela un dispositivo inteligente básico del hogar.
 *
 * Esta clase gestiona el estado (encendido/apagado), el consumo
 * energético y el bloqueo del control remoto de un dispositivo.
 */
class DispositivoInteligente {
    //  Atributos Privados 
   private:
    std::string nombre_;
    bool estado_;  // true = encendido, false = apagado
    float consumoEnergia_;
    bool controlRemotoBloqueado_;  // true = bloqueado

    //  Métodos Públicos 
   public:
    /**
     * @brief Constructor de la clase DispositivoInteligente.
     * @param nombre El nombre del dispositivo (ej. "Luz Sala").
     * @param consumoEnergia El consumo en Vatios/hora.
     */
    DispositivoInteligente(std::string nombre, float consumoEnergia);

    // Métodos de control de estad

    /** @brief Enciende el dispositivo. */
    void encender();

    /** @brief Apaga el dispositivo. */
    void apagar();

    /** @brief Bloquea el control remoto del dispositivo. */
    void bloquearControlRemoto();

    /** @brief Desbloquea el control remoto del dispositivo. */
    void desbloquearControlRemoto();  // Método auxiliar útil

    // Métodos de consulta 

    /**
     * @brief Calcula y devuelve el consumo total en un período.
     * @param horas El número de horas que el dispositivo estuvo encendido.
     * @return El consumo total en Vatios (Consumo * horas).
     */
    float medirConsumo(
        float horas) const;  // 'const' indica que no modifica el objeto

    /** @brief Devuelve el nombre del dispositivo. */
    std::string getNombre() const;

    /** @brief Devuelve el estado actual (true=encendido). */
    bool getEstado() const;

    /** @brief Devuelve si el control remoto está bloqueado. */
    bool estaBloqueado() const;

    /** @brief Devuelve el consumo base de energía del dispositivo. */
    float getConsumoEnergia() const;
};