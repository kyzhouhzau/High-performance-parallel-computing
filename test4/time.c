#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main (int argc, char **argv)
{
	int myid, numprocs;
	int namelen;
	double startwtime = 0.0, endwtime;
	char processor_name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init (&argc, &argv);
	MPI_Comm_rank (MPI_COMM_WORLD, &myid);
	MPI_Comm_size (MPI_COMM_WORLD, &numprocs);
	MPI_Get_processor_name (processor_name, &namelen);
	startwtime = MPI_Wtime();
	fprintf (stderr, "Hello World! Process %d of %d on %s\n", myid, numprocs, processor_name);        
    endwtime=MPI_Wtime();
    if(myid==0)
	{      
	printf("Time=%f\n",endwtime-startwtime); 
	}      

    MPI_Finalize();

    return 0;

}