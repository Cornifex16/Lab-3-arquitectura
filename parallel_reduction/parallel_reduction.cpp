#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

int main() {
    const size_t N = 100000000;
    std::vector<double> vec(N, 1.0);
    double sum = 0.0;
    
    double start = omp_get_wtime();
    
    #pragma omp parallel for
    for (size_t i = 0; i < N; ++i) {
        #pragma omp atomic
        sum += vec[i];
    }
    
    double end = omp_get_wtime();
    
    std::cout << "Suma (Atomic) = " << sum << " en " << (end - start) << "s" << std::endl;
    
    return 0;
}