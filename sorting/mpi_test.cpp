#include <iostream>
#include <stdlib.h>

#include "mpi.h"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }

    // Start MPI
    int p, P;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    MPI_Comm_rank(MPI_COMM_WORLD, &p);

    double start_time = MPI_Wtime();

    std::cout << p << ", " << P << std::endl;

    MPI_Barrier(MPI_COMM_WORLD);
    if (p == 0)
    {
        double exec_time = MPI_Wtime() - start_time;
        std::cout << "Execution time: " << exec_time << std::endl;
    }
    MPI_Finalize();
}