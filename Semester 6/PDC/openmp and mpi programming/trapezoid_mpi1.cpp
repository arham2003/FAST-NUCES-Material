#include <iostream>
#include <mpi.h>
using namespace std;

double f(double x) {
    return x * x;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a = 0.0, b = 1.0;
    int n = 1000000;
    double h = (b - a) / n;

    int m = n - 1; // Number of internal points
    int start = 1 + (rank * m) / size;
    int end = 1 + ((rank + 1) * m) / size;

    double local_integral = 0.0;
    for (int i = start; i < end; ++i) {
        local_integral += f(a + i * h);
    }

    double total_sum;
    MPI_Reduce(&local_integral, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double integral = (total_sum + (f(a) + f(b)) / 2.0) * h;
        cout << "Integral result: " << integral << endl;
    }

    MPI_Finalize();
    return 0;
}