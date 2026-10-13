cmake_minimum_required(VERSION 3.10)
project(MiProyecto)

# Busca automáticamente todos los archivos .cpp en la carpeta actual y sus subcarpetas
file(GLOB_RECURSE SOURCES "*.cpp")

# Crea el ejecutable con todos los archivos encontrados
add_executable(programa ${SOURCES})
