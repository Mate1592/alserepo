# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(HogarInteligente)

# Establecer el estándar de C++ a C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir el directorio 'include' a las rutas de búsqueda de encabezados
include_directories(include)

# Añadir el ejecutable y especificar sus archivos fuente
add_executable(simulador_hogar
    src/main.cpp
    src/DispositivoInteligente.cpp
)

# Mensaje para el usuario
message(STATUS "Proyecto configurado. Usa 'make' para compilar.")