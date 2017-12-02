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
	clock_t t1,t2,t3,t4,t5,t6;
	printf("===========================");
	printf("\n1-1000000之间的素数\n");
	printf("===========================\nSave to file: prime_number_s.txt\n");

	fpt=fopen("prime_number_s.txt","w");
	t1 = clock();
	for (i = 2; i < 1000000; i++) 
	{
		
		if (prime(i))
		{
			count_++;   
			fprintf(fpt,"%d\t",i);	
		}
	}
	fclose(fpt);
	t2 = clock();
	t3=t2-t1;
	printf("===========================");
	printf("\n素数一共有%d个\n", count_);
	printf("===========================");
	printf("\nTime-consuming for Serial codes:\n %.6lf secs\n",(double)(t3)/CLOCKS_PER_SEC);
	printf("\n\n\n############################################\n");
	printf("############################################\n\n\n");	
	printf("===========================");
	printf("\n1-1000000之间的素数");
	printf("\n===========================\nSave to file: prime_number_p.txt\n");

	// fpt=fopen("prime_number_p.txt","w");
	
	for(int t=1;t<9;t++)
	{ 
		int count = 0;
		printf("\n\nWhen threads was set as %d\n",t);
		t4 = clock();
		omp_set_num_threads(t);
		#pragma omp parallel for private(i) reduction(+:count)
		for (i = 2; i < 1000000; i++) 
		{
			
			if (prime(i))
			{
				count++;
				// fprintf(fpt,"%d\t",i);	
			}

		}
		t5 = clock();
		t6=t5-t4;
		// fclose(fpt);
		printf("===========================");
		printf("\n素数一共有%d个\n", count);
		printf("===========================");
		printf("\nTime-consuming for parallel codes:\n %.6lf secs\n",(double)(t6)/CLOCKS_PER_SEC );
		printf("===========================\n");
		printf("When threads is %d the speedup ratio is %.6lf\n",t,(double)(t3)/(double)(t6));
	}
	return 0;
}

