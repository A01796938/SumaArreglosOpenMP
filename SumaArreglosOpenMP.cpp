#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando arreglos en paralelo con OpenMP\n\n";

    float a[N], b[N], c[N];
    int i;

    std::srand((unsigned)std::time(nullptr));

    // Llenar arreglos A y B
    for (i = 0; i < N; i++)
    {
        a[i] = (std::rand() % 1000) / 10.0f;
        b[i] = (std::rand() % 1000) / 10.0f;
    }

    // Suma paralela
#pragma omp parallel for shared(a, b, c) private(i) schedule(static, chunk)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    std::cout << "Arreglo A:\n";
    imprimeArreglo(a);

    std::cout << "Arreglo B:\n";
    imprimeArreglo(b);

    std::cout << "Arreglo C = A + B:\n";
    imprimeArreglo(c);

    std::cout << "Presiona ENTER para salir...";
    std::cin.get();

    return 0;
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << std::fixed << std::setprecision(1) << d[x] << "  ";
    }
    std::cout << "\n\n";
}
