#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
    const size_t N = 100000000;
    std::vector<double> vec(N, 1.0);
    
    // --- Mejora 2: Privatización manual ---
    double sum_manual = 0.0;
    int num_threads = omp_get_max_threads();
    std::vector<double> local_sums(num_threads, 0.0);
    
    double start_man = omp_get_wtime();
    
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        #pragma omp for
        for (size_t i = 0; i < N; ++i) {
            local_sums[tid] += vec[i];
        }
    }
    
    // Suma de los arreglos locales al final
    for (double s : local_sums) {
        sum_manual += s;
    }
    double end_man = omp_get_wtime();
    std::cout << "Suma (Privatizacion) = " << sum_manual << " en " << (end_man - start_man) << "s\n";
    
    return 0;
}