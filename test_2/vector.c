#include <stdio.h>
#include <omp.h>

int main()
{
	int i,n;
	double a[1000],b[1000],result;//define double vectors
	n=1000;
	result = 0.0;
	for (i = 0;i<n;i++)//assign for vectors
	{
		a[i] = i*2.0;
		b[i] = i*3.0;

	}
	double start = omp_get_wtime();
	#pragma omp parallel for private(i) reduction(+:result)
	for (i = 0;i<n;i++)
	{
		result = result + (a[i]*b[i]);

	}
	double end = omp_get_wtime();
	double wtick = omp_get_wtick();
	//printf("串行程序运行时间\n");
	printf("并行程序运行时间\n");
	printf("a*b=%.5lf \n",result);
	printf("start = %.16g\n end = %.16g\n diff = %.16g\n",start,end,end-start);
	//printf("wtick = %.16g\n 1/wtick = %.16g\n",wtick,1.0/wtick);
}

