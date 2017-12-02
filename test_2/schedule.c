#include <stdio.h>
#include <omp.h>
#include <math.h>

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
	double t1,t2,time;
	int i=0;
	omp_set_num_threads(5);
	t1=omp_get_wtime();
	#pragma omp parallel private(i) default(shared)
	#pragma omp schedule(static)
	for (i=2;i<10000;i++)
	{
		if (prime(i))
		{
			i+=i;
		}
	// printf("%d",i);
	}
	t2=omp_get_wtime();
	time = (t2-t1)*1000;
	printf(" \nstatic schedule time = %10.5f milleseconds\n", time);
// ###################################################################
	t1=omp_get_wtime();
	#pragma omp parallel private(i) default(shared)
	#pragma omp schedule(dynamic)
	for (i=2;i<10000;i++)
	{
		if (prime(i))
		{
			i+=i;
		}
	// printf("%d",i);
	}
	t2=omp_get_wtime();
	time = (t2-t1)*1000;
	printf(" \ndynamic schedule time = %10.5f milleseconds\n", time);
// ##################################################################
	t1=omp_get_wtime();
	#pragma omp parallel private(i) default(shared)
	#pragma omp schedule(guide)
	for (i=2;i<10000;i++)
	{
		if (prime(i))
		{
			i+=i;
		}
	// printf("%d",i);
	}
	t2=omp_get_wtime();
	time = (t2-t1)*1000;
	printf(" \nguide schedule time = %10.5f milleseconds\n", time);
// ##################################################################
	t1=omp_get_wtime();
	#pragma omp parallel private(i) default(shared)
	#pragma omp schedule(runtime)
	for (i=2;i<10000;i++)
	{
		if (prime(i))
		{
			i+=i;
		}
	// printf("%d",i);
	}
	t2=omp_get_wtime();
	time = (t2-t1)*1000;
	printf(" \nruntime schedule time = %10.5f milleseconds\n", time);










}