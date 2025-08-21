#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 4  // Matrix dimension (NxN), adjust as needed

void printMatrix(const std::vector<int>& mat, int rows, int cols, const std::string& name) {
    std::cout << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << mat[i * cols + j] << " ";
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (N % world_size != 0) {
        if (world_rank == 0) {
            std::cerr << "Matrix size must be divisible by number of processes.\n";
        }
        MPI_Finalize();
        return -1;
    }

    int rows_per_proc = N / world_size;

    // Allocate matrices
    std::vector<int> A, B(N * N), C;
    std::vector<int> local_A(rows_per_proc * N);
    std::vector<int> local_C(rows_per_proc * N, 0);

    if (world_rank == 0) {
        A.resize(N * N);
        C.resize(N * N);

        // Initialize matrices A and B with random values
        srand(time(nullptr));
        for (int i = 0; i < N * N; ++i) {
            A[i] = rand() % 10;
            B[i] = rand() % 10;
        }

        printMatrix(A, N, N, "Matrix A");
        printMatrix(B, N, N, "Matrix B");
    }

    // Scatter rows of A
    MPI_Scatter(A.data(), rows_per_proc * N, MPI_INT,
        local_A.data(), rows_per_proc * N, MPI_INT,
        0, MPI_COMM_WORLD);

    // Broadcast matrix B to all processes
    MPI_Bcast(B.data(), N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Local computation of matrix multiplication
    for (int i = 0; i < rows_per_proc; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                local_C[i * N + j] += local_A[i * N + k] * B[k * N + j];
            }
        }
    }

    // Gather results from all processes
    MPI_Gather(local_C.data(), rows_per_proc * N, MPI_INT,
        C.data(), rows_per_proc * N, MPI_INT,
        0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printMatrix(C, N, N, "Result Matrix C = A x B");
    }

    MPI_Finalize();
    return 0;
}
