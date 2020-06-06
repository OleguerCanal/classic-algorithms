#  mpic++ is a wrapper around gcc which links mpi libraries
 mpic++ -I include $1 -o out;
 mpirun -n $2 out