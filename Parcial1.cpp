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
double calcularMagnitud(Point p1)
{
    // Completar: Usar la fórmula de distancia euclidiana
    // sugerencia: puede hacer uso de funcionines como sqrt y pow
    return;
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    // Leer la respuesta del usuario

    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == <valor a comparar><Operador logico> respuesta == <valor a comparar>)
    {
        // Completar: Leer las coordenadas de cada punto
        for ()
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[].>> puntos;
        }
    }
    else
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};  // Punto 1 (0, 0)
        puntos[1] = {3, 4};  // Punto 2 (3, 4)
        puntos[2] = {6, 8};  // Punto 3 (6, 8)
        puntos[3] = {9, 12}; // Punto 4 (9, 12)
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularMayorMagnitud(Point puntos[], int n, int &indiceMayorMagnitud)
{

    return mayorMagnitud;
}

// Función para mostrar el punto con mayor magnitud y sus coordenadas
void mostrarResultado(Point puntos[], int indiceMayorMagnitud, double magnitud)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMayorMagnitud].x << ", " << puntos[indiceMayorMagnitud].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    <tipo> n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    std::<funcion> >> n;

    if ()
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(<completar argumentos>);

    // Calcular mayor magnitud
    <type> indiceMayorMagnitud;
    // llamar funcion
    //  Mostrar el resultado
    mostrarResultado(puntos, <variable>, distancia);

    return 0;
}
