# Gestor de Inventario

## Requisitos
- CMake >= 3.16
- Qt6 (o Qt5) con módulos Widgets y Sql
- Compilador C++17

## Compilar (Linux / Terminal)
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```
Ejecutable: `./gestor`

## Testing (Headless / Codespaces)
Si no tienes acceso a un entorno gráfico (como en CI/CD o SSH), puedes probar la funcionalidad principal (base de datos, CSV) ejecutando:
```bash
./test_headless
```
Esto verificará:
- Creación de base de datos y esquema.
- Inserción de componentes.
- Listado de componentes.
- Exportación a CSV.

## Configuración Local en Windows (Qt Creator)

### 1. Requisitos Previos
- **Qt Creator + Qt Libraries**: Asegúrate de haber instalado Qt (versión 6 o 5) usando el "Qt Online Installer". Al instalar, selecciona "Qt 6.x.x" y marca "MinGW" o "MSVC" (el compilador).
- **CMake**: Si no lo tienes, descárgalo e instálalo desde [cmake.org/download](https://cmake.org/download/). Durante la instalación, marca la opción "Add CMake to system PATH".

### 2. Abrir el Proyecto
1. Abre Qt Creator.
2. Ve a **File > Open File or Project**.
3. Busca la carpeta del proyecto y selecciona el archivo `CMakeLists.txt`.
4. Qt Creator te pedirá configurar el proyecto ("Configure Project").
   - Selecciona un "Kit" compatible (ej. `Desktop Qt 6.x.x MinGW 64-bit`).
   - Haz clic en **Configure**.

### 3. Ejecutar
1. Haz clic en el botón **Run** (triángulo verde) abajo a la izquierda (o presiona `Ctrl+R`).
2. La aplicación debería abrirse.

## Notas
- El archivo de BD `inventory.db` se creará en la carpeta de compilación (build).
- Para reducir tamaño del ejecutable: compila en Release.
