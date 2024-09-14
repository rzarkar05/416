all: problem1_omp problem2_omp problem3_omp problem4_omp

problem1_omp: problem1.cpp
	g++ -fopenmp -o problem1_omp problem1.cpp

problem2_omp: problem2.cpp
	g++ -fopenmp -o problem2_omp problem2.cpp

problem3_omp: problem3.cpp
	g++ -fopenmp -o problem3_omp problem3.cpp

problem4_omp: problem4.cpp
	g++ -fopenmp -o problem4_omp problem4.cpp

clean:
	rm -f problem1_omp problem2_omp problem3_omp problem4_omp

