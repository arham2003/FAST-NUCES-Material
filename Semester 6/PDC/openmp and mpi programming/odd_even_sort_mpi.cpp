#include <iostream>
#include <mpi.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int n = 100;
    int local_n = n / size;
    vector<int> local_arr(local_n);

    for (int i = 0; i < local_n; ++i) {
        local_arr[i] = n - (rank * local_n + i);
    }

    bool global_sorted = false;
    do {
        bool local_sorted = true;
        for (int phase = 0; phase < 2; ++phase) {
            int partner = (phase == 0) ? 
                (rank % 2 == 0 ? rank + 1 : rank - 1) :
                (rank % 2 == 1 ? rank + 1 : rank - 1);

            if (partner < 0 || partner >= size) continue;

            vector<int> partner_arr(local_n);
            MPI_Sendrecv(local_arr.data(), local_n, MPI_INT, partner, 0,
                         partner_arr.data(), local_n, MPI_INT, partner, 0,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            vector<int> merged(2 * local_n);
            merge(local_arr.begin(), local_arr.end(),
                       partner_arr.begin(), partner_arr.end(),
                       merged.begin());

            vector<int> new_local(local_n);
            if ((rank < partner && phase == 0) || (rank > partner && phase == 1)) {
                copy(merged.begin(), merged.begin() + local_n, new_local.begin());
            } else {
                copy(merged.begin() + local_n, merged.end(), new_local.begin());
            }

            if (new_local != local_arr) {
                local_arr.swap(new_local);
                local_sorted = false;
            }
        }

        int local_flag = local_sorted ? 1 : 0;
        int global_flag;
        MPI_Allreduce(&local_flag, &global_flag, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
        global_sorted = (global_flag == 1);
    } while (!global_sorted);

    vector<int> sorted_arr;
    if (rank == 0) sorted_arr.resize(n);
    
    MPI_Gather(local_arr.data(), local_n, MPI_INT,
               sorted_arr.data(), local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        cout << "Sorted array: ";
        for (int num : sorted_arr) cout << num << " ";
        cout << endl;
    }

    MPI_Finalize();
    return 0;
}