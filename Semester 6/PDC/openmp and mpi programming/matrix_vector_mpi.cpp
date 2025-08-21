#include <iostream>
#include <mpi.h>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows = 1000, cols = 1000;
    vector<double> matrix, vec(cols), local_result;

    if (rank == 0) {
        matrix.resize(rows * cols, 1.0); // Example: matrix of ones
        for (int i = 0; i < cols; ++i) vec[i] = i + 1;
    }

    MPI_Bcast(vec.data(), cols, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    int local_rows = rows / size;
    vector<double> local_matrix(local_rows * cols);

    MPI_Scatter(matrix.data(), local_rows * cols, MPI_DOUBLE,
                local_matrix.data(), local_rows * cols, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    local_result.resize(local_rows);
    for (int i = 0; i < local_rows; ++i) {
        local_result[i] = 0.0;
        for (int j = 0; j < cols; ++j) {
            local_result[i] += local_matrix[i * cols + j] * vec[j];
        }
    }

    vector<double> result;
    if (rank == 0) result.resize(rows);
    
    MPI_Gather(local_result.data(), local_rows, MPI_DOUBLE,
               result.data(), local_rows, MPI_DOUBLE,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Result[0]: " << result[0] << endl;
    }

    MPI_Finalize();
    return 0;
}