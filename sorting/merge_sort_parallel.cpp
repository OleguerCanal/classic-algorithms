#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "mpi.h"
#include "utils.hpp"

void mergeSortedVectors(const std::vector<float> &in1,
                        const std::vector<float> &in2,
                        std::vector<float> *out)
{
    // Given two sorted arrays, returns sorted merge
    int n1 = in1.size();
    int n2 = in2.size();

    int it1 = 0;
    int it2 = 0;
    double val;
    for (int i = 0; i < n1 + n2; i++)
    {
        if (it1 < n1 && it2 < n2)
        {
            if (in1[it1] < in2[it2])
            {
                val = in1[it1];
                it1++;
            }
            else
            {
                val = in2[it2];
                it2++;
            }
        }
        else if (it1 < n1)
        {
            val = in1[it1];
            it1++;
        }
        else
        {
            val = in2[it2];
            it2++;
        }
        out->at(i) = val;
    }
}

void transferVector(const std::vector<float> &in,
                    std::vector<float> *out,
                    size_t start, size_t end)
{
    for (size_t i = start; i < end; i++)
        out->at(i - start) = in[i];
}

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 0;
    }

    // Start MPI
    int p, P;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    MPI_Comm_rank(MPI_COMM_WORLD, &p);
    std::cout << "Process " << p << " of " << P << " started" << std::endl;
    double start_time = MPI_Wtime();

    // Compute vector partition sizes
    bool even_process = p % 2;
    bool first_process = (p == 0);
    bool last_process = (p == P - 1);
    int N = 100; // Total number of elements
    int I = N / P;
    int I_prev = (p - 1 < N % P) ? I + 1 : I;
    int I_next = (p + 1 < N % P) ? I + 1 : I;
    I = (p < N % P) ? I + 1 : I;

    // Initialize vector partition
    std::vector<float> vect = utils::get_random_vector(I, p);
    std::vector<float> vect_prev(I_prev);
    std::vector<float> vect_next(I_next);
    std::vector<float> merged(2 * I + 2);

    // Serial sorting of current process' vector
    std::sort(vect.begin(), vect.end());

    // Parallel sorting and merge
    for (int step = 0; step <= P; step++)
    {
        bool even_step = step % 2;
        if (even_step)
        { // even step
            if (even_process && !last_process)
            {
                MPI_Send(&vect[0], I, MPI_FLOAT, p + 1, 0, MPI_COMM_WORLD);
                MPI_Recv(&vect_next[0], I_next, MPI_FLOAT, p + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                mergeSortedVectors(vect, vect_next, &merged); // Sorted Merge
                transferVector(merged, &vect, 0, I);          // Get Min
            }
            if (!even_process && !first_process)
            { // odd porcess
                MPI_Recv(&vect_prev[0], I_prev, MPI_FLOAT, p - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(&vect[0], I, MPI_FLOAT, p - 1, 0, MPI_COMM_WORLD);
                mergeSortedVectors(vect, vect_prev, &merged);      // Sorted Merge
                transferVector(merged, &vect, I_prev, I_prev + I); // Get Max
            }
        }
        else
        { // odd step
            if (even_process && !first_process)
            {
                MPI_Send(&vect[0], I, MPI_FLOAT, p - 1, 0, MPI_COMM_WORLD);
                MPI_Recv(&vect_prev[0], I_prev, MPI_FLOAT, p - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                mergeSortedVectors(vect, vect_prev, &merged);      // Sorted Merge
                transferVector(merged, &vect, I_prev, I_prev + I); // Get Max
            }
            if (!even_process && !last_process)
            { // odd porcess
                MPI_Recv(&vect_next[0], I_next, MPI_FLOAT, p + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                MPI_Send(&vect[0], I, MPI_FLOAT, p + 1, 0, MPI_COMM_WORLD);
                mergeSortedVectors(vect, vect_next, &merged); // Sorted Merge
                transferVector(merged, &vect, 0, I);          // Get Min
            }
        }
    }

    std::string print_msg = "Process " + std::to_string(p) + ": ";
    utils::print<float>(vect, print_msg);

    MPI_Barrier(MPI_COMM_WORLD);
    if (p == 0)
    {
        double exec_time = MPI_Wtime() - start_time;
        std::cout << "Execution time: " << exec_time << std::endl;
    }
    MPI_Finalize();
}