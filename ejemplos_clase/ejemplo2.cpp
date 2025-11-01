#include <iostream>

/**
 * @struct Point
 * @brief Representa un punto en el espacio 2D.
 *
 * Esta estructura contiene las coordenadas x e y de un punto.
 */
struct Point
{
    /** @brief La coordenada x del punto. */
    int x;
    /** @brief La coordenada y del punto. */
    int y;
};

/**
 * @brief La función principal del programa.
 * @return 0 si la ejecución es exitosa.
 *
 * Esta función solicita al usuario que ingrese las coordenadas de un punto,
 * lee la entrada y luego muestra las coordenadas del punto creado.
 */
int main()
{
    // Crea un objeto Point
    Point userPoint;

    // Solicita al usuario que ingrese la coordenada x
    std::cout << "Ingrese la coordenada x: ";
    std::cin >> userPoint.x;

    // Solicita al usuario que ingrese la coordenada y
    std::cout << "Ingrese la coordenada y: ";
    std::cin >> userPoint.y;

    // Muestra las coordenadas del punto
    std::cout << "Las coordenadas del punto son: (" << userPoint.x << ", " << userPoint.y << ")" << std::endl;

    return 0;
}
