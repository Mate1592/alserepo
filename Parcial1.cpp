//Parcial 1 de ALSE Grupo 3
//Integrantes:
// David Mateo Espinel Ramos
//Kaleth Stalin Sierra Aranguen




#include <iostream>
#include <cmath>

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular magnitud asociada al vector de un punto p1
/*Como puede modificar la declaración de la función para que sea mas eficiente en el manejo de memoria?
Teniendo en cuenta que solo necesita leer los valores, pero no modificarlos*/


double calcularMagnitud(const Point& p1) //con el const &point no hace una copia innecesaria, usa mem dinamica
{
    double magnitud = std::sqrt(p1.x * p1.x + p1.y * p1.y); //se completa la fórmula de la magnitud
    return  magnitud ;
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(std::vector<Point>& puntos)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    size_t n = puntos.size();

    // Verificar si la respuesta es 's' o 'n', considerando mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S') //s o S como condicion
    {
        // Leer las coordenadas de cada punto
        for (size_t i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        
        // Asegurar que no excedamos el tamaño del arreglo
        if (n >= 1) puntos[0] = {0, 0};   // Punto 1 (0, 0)
        if (n >= 2) puntos[1] = {3, 4};   // Punto 2 (3, 4)
        if (n >= 3) puntos[2] = {6, 8};   // Punto 3 (6, 8)
        if (n >= 4) puntos[3] = {9, 12};  // Punto 4 (9, 12)
        
        // Si hay más puntos, llenar con valores adicionales
        for (size_t i = 4; i < n; i++)
        {
            puntos[i] = {static_cast<double>(i), static_cast<double>(i * 2)};
        }
    }
}

// Función para calcular la mayor magnitud
double calcularMayorMagnitud(const std::vector<Point>& puntos, int &indiceMayorMagnitud)
{

    // Funcion del parcial 1 punto 3 apoyandose de la funcion calcular magnitud
    double mayorMagnitud = calcularMagnitud(puntos[0]);
    indiceMayorMagnitud = 0;
    
    // Recorrer todos los puntos para encontrar la mayor magnitud
    for (size_t i = 1; i < puntos.size(); i++)
    {
        double magnitudActual = calcularMagnitud(puntos[i]);
        if (magnitudActual > mayorMagnitud)
        {
            mayorMagnitud = magnitudActual;
            indiceMayorMagnitud = i;
        }
    }
    
    return mayorMagnitud;
}

// Función para mostrar el punto con mayor magnitud y sus coordenadas
void mostrarResultado(const std::vector<Point>& puntos, int indiceMayorMagnitud, double magnitud)
{
    std::cout << "\nEl punto de mayor magnitud: (" << puntos[indiceMayorMagnitud].x 
              << ", " << puntos[indiceMayorMagnitud].y << ")\n";
    std::cout << "El valor de la magnitud es: " << magnitud << std::endl;
}

int main()
{
    int n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para determinar la mayor magnitud.\n";
        return 1;
    }

    std::vector<Point> puntos(n); // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos);

    // Calcular mayor magnitud
    int indiceMayorMagnitud;
    double mayorMagnitud = calcularMayorMagnitud(puntos, indiceMayorMagnitud);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMayorMagnitud, mayorMagnitud);

    return 0;
}
