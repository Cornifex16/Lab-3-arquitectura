#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <random>

// Función optimizada sin ramas (Branchless)
long long sum_if_branchless(const std::vector<int>& data, int threshold) {
    long long sum = 0;
    for (int val : data) {
        // Multiplicación condicional para evitar el 'if'
        sum += val * (val > threshold);
    }
    return sum;
}

int main(int argc, char* argv[]) {
    const size_t N = 100000000; 
    std::vector<int> data(N);
    
    std::iota(data.begin(), data.end(), 0);
    int threshold = N / 2;

    std::cout << "Ejecutando con datos predecibles (ordenados)..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    long long result1 = sum_if_branchless(data, threshold);
    auto end = std::chrono::high_resolution_clock::now();
    double time_pred = std::chrono::duration<double>(end - start).count();
    std::cout << "Resultado: " << result1 << " Tiempo: " << time_pred << "s\n" << std::endl;

    return 0;
}