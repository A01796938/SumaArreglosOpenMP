# Suma de arreglos en paralelo con OpenMP (C++)

Este proyecto suma dos arreglos A y B para generar un arreglo C, utilizando paralelismo con OpenMP.

## Requisitos
- Visual Studio (C++ Desktop Development)
- OpenMP habilitado en: Project Properties → C/C++ → Language → OpenMP Support = Yes (/openmp)

## Ejecución
1. Abrir el archivo `.sln` en Visual Studio
2. Compilar: Build → Build Solution
3. Ejecutar: Ctrl + F5

## Descripción
- Se crean tres arreglos: A, B y C (tamaño N).
- A y B se llenan con valores pseudoaleatorios.
- Se suma en paralelo con `#pragma omp parallel for`.
- Se imprimen los primeros `mostrar` elementos para comprobar resultados.
