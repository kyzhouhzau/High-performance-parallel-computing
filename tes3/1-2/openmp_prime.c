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
int main()
{
	FILE *fpt;
	time_t t_start, t_end;
	int nthreads,tid,i = 0;
	int count_ = 0;
	printf("===========================");
	printf("\n1-100000之间的素数\n");
	printf("===========================\nSave to file: prime_number_s.txt\n");
	fpt=fopen("prime_number_p.txt","w");
	
	int count = 0;
	printf("\n\nWhen threads was set as %d\n",4);
	double start = omp_get_wtime( ); 
	omp_set_num_threads(4);
	#pragma omp parallel for private(i) reduction(+:count)
	for (i = 2; i < 100000; i++) 
	{
		
		if (prime(i))
		{
			count++;
			fprintf(fpt,"%d\t",i);	
		}
	 
	}
	double end = omp_get_wtime();
	// fclose(fpt);
	printf("===========================");
	printf("\n素数一共有%d个\n", count);
	printf("===========================");
	printf("\nTime-consuming for parallel codes:\n %.6lf seconds\n",end-start);
	return 0;
}