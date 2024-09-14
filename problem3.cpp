#include <stdlib.h>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <omp.h>

double productWithInverses(std::vector<double> const& x) {
    double result = 1.0;

    #pragma omp parallel for reduction(*:result)
    for (int i = 0; i < x.size(); i++) {
        if (i % 2 == 1) {
            result *= 1 / x[i];
        } else {
            result *= x[i];
        }
    }

    return result;
}

int main(int argc, char **argv) {
    int N = 1024;
    int seed = 273;

    if (argc == 2) {
        N = std::stoi(argv[1]);
    }
    if (argc == 3) {
        N = std::stoi(argv[1]);
        seed = std::stoi(argv[2]);
    }

    std::vector<double> x(N);
    srand(seed);

    for (int i = 0; i < N; i += 1) {
        x[i] = (rand() / (double) RAND_MAX) * N;
    }

    double totalTime = 0.0;
    double start = omp_get_wtime();

    double val = productWithInverses(x);

    totalTime = omp_get_wtime() - start;

    printf("Product: %.5f\n", val);
    /*printf("TIME %.5f seconds\n", totalTime); */ 
}
