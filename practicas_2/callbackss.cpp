#include <iostream>
#include <cstring>
using namespace std;

// Callback functions for different operations
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

// Function that performs an operation using a callback
void performOperation(int (*callback)(int, int), int x, int y)
{
    cout << "The result of the operation is: " << callback(x, y) << endl;
}

int main(int argc, char* argv[])
{
    // Verificar que se pasaron los argumentos correctos
    if (argc != 4)
    {
        cout << "Uso: " << argv[0] << " <operacion> <numero1> <numero2>" << endl;
        cout << "Operaciones disponibles: add, multiply, subtract" << endl;
        return 1;
    }

    // Leer los argumentos
    char* operation = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    // Seleccionar la operación según el argumento
    int (*selectedOperation)(int, int) = nullptr;

    if (strcmp(operation, "add") == 0)
    {
        selectedOperation = add;
        cout << "Addition: ";
    }
    else if (strcmp(operation, "multiply") == 0)
    {
        selectedOperation = multiply;
        cout << "Multiplication: ";
    }
    else if (strcmp(operation, "subtract") == 0)
    {
        selectedOperation = subtract;
        cout << "Subtraction: ";
    }
    else
    {
        cout << "Operacion no valida. Use: add, multiply, o subtract" << endl;
        return 1;
    }

    // Ejecutar la operación seleccionada
    performOperation(selectedOperation, num1, num2);

    return 0;
}