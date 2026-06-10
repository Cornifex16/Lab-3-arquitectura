#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
    const size_t N = 100000000;
    std::vector<double> vec(N, 1.0);
    
    // --- Mejora 1: Reducción de OpenMP ---
    double sum_reduction = 0.0;
    double start_red = omp_get_wtime();
    
    #pragma omp parallel for reduction(+:sum_reduction)
    for (size_t i = 0; i < N; ++i) {
        sum_reduction += vec[i];
    }
    double end_red = omp_get_wtime();
    std::cout << "Suma (Reduction) = " << sum_reduction << " en " << (end_red - start_red) << "s\n";
    
    return 0;
}