#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <random>

// Función que suma elementos según umbral, generando una rama condicional
long long sum_if(const std::vector<int>& data, int threshold) {
    long long sum = 0;
    for (int val : data) {
        if (val > threshold) {
            sum += val;
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    const size_t N = 100000000; // 100 millones de elementos
    std::vector<int> data(N);

    // Inicialización con patrón predecible: valores ordenados
    std::iota(data.begin(), data.end(), 0);
    int threshold = N / 2;

    // Mezclar datos aleatoriamente (patrón impredecible)
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(data.begin(), data.end(), g);
    
    std::cout << "Ejecutando con datos aleatorios (impredecible)..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    long long result2 = sum_if(data, threshold);
    auto end = std::chrono::high_resolution_clock::now();
    double time_rand = std::chrono::duration<double>(end - start).count();
    std::cout << "Resultado: " << result2 << " Tiempo: " << time_rand << "s\n" << std::endl;

    return 0;
}