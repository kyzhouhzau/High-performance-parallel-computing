#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>

int prime(int n)
{
	int i = 2;
	for (i; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main(int argc, char *argv[])
{
	FILE *fpt;
	int count = 0,sum=0,myid, numprocs, n=1000000,i,mycount,ycount;
	double startwtime = 0.0, endwtime;
	int  namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];


	MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(processor_name,&namelen);
    fprintf(stderr,"Process %d on %s\n",myid, processor_name);
 	// printf("===========================");
	// printf("\n1-100000之间的素数\n");
	// printf("===========================\nSave to file: prime_number_s.txt\n");
	fpt=fopen("prime_number_p.txt","w");
	startwtime = MPI_Wtime();
	MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD); 
	for (i=myid*2+1;i<=n;i+=numprocs*2)
	{
		
		if (prime(i))
		{
			count++;
			fprintf(fpt,"%d\t",i);	
		}
	 
	}
	mycount=count;
    MPI_Reduce(&mycount,&ycount,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);  //规约 
    if(myid==0)
    {    
    	printf("结果=%d\n",ycount);  
    	endwtime=MPI_Wtime();  
    	printf("并行时间=%f\n",endwtime-startwtime); 
    }      
 

     //串行程序  
    count=0;
    double startwtime2=MPI_Wtime();
    if(myid==0) 

    {
    	for (i = 1; i <=n; i+=2)  
    	{
		
			if (prime(i))
			{
				count++;
			// fprintf(fpt,"%d\t",i);

			}
	 
		}
		printf("结果=%d\n",count); 
	    double endwtime2=MPI_Wtime();  
	    printf("串行时间=%f\n",endwtime2-startwtime2); 
	}
 
	MPI_Finalize();
	// fclose(fpt);
	// printf("===========================");
	// printf("\n素数一共有%d个\n", count);
	// printf("\nTime-consuming for mpi codes:\n %.6lf seconds\n",endwtime-startwtime);
	return 0;
}
