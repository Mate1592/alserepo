# Gestor de Inventario

## Requisitos
- CMake >= 3.16
- Qt6 (o Qt5) con módulos Widgets y Sql
- Compilador C++17

## Compilar
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```
Ejecutable: `./gestor`

## Testing (Headless)
Si no tienes acceso a un entorno gráfico (como en CI/CD o SSH), puedes probar la funcionalidad principal (base de datos, CSV) ejecutando:
```bash
./test_headless
```
Esto verificará:
- Creación de base de datos y esquema.
- Inserción de componentes.
- Listado de componentes.
- Exportación a CSV.

## Notas
- El archivo de BD `inventory.db` se creará en la carpeta donde ejecutes el binario.
- Para reducir tamaño del ejecutable: compila en Release y usa strip en Linux.

## Consideraciones de diseño
- Sin warnings: usar `-Wall -Wextra`.
- Memoria: RAII (Qt objects con parents).
- Documentación: Doxygen.
- Estructura: `src/` para código fuente.
