#include <stdlib.h>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iostream>
#include <omp.h> 

int edgeCount(std::vector<int> const& A, size_t N) {
    int count = 0;

    #pragma omp parallel for reduction(+:count)
    for (size_t i = 0; i < N; i += 1) {
        for (size_t j = 0; j < N; j += 1) {
            if (A[i * N + j] == 1) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char **argv) {
    int N = 128;
    int seed = 17;

    if (argc == 2) {
        N = std::stoi(argv[1]);
    }
    if (argc == 3) {
        N = std::stoi(argv[1]);
        seed = std::stoi(argv[2]);
    }

    std::vector<int> A(N * N);
    srand(seed);

    std::fill(A.begin(), A.end(), 0);
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            if (rand() % 2 == 0) {
                A[i * N + j] = 1;
            }
        }
    }

    
    double totalTime = 0.0;
    double start = omp_get_wtime();

    int count = edgeCount(A, N);

    totalTime = omp_get_wtime() - start;

    printf("Count : %d\n", count);
    /*printf("TIME %.5f seconds\n", totalTime); */
}
