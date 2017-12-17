#include <stdio.h>
#include <omp.h>
#include <math.h>
//gcc -fopenmp 1-1.c
//pgcc vector_multiply.c -acc -Minfo -ta=multicore

int main()
{
    int n=100000;     /* size of the vector */
    double a[n],b[n],result=0.0,exception=0.0;/*definr vector*/
    int i, errs=0;
    struct timeval start, end;
    for( i = 0; i < n; ++i )
    {
        a[i] = (float)(i*2.0);
        b[i] = (float)(i*5.0);
    } 
    gettimeofday( &start, NULL );
	#pragma acc parallel loop
    for( i = 0; i < n; ++i )
    {

     	result =result+ a[i]*b[i];
    
    }
	

    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    /* compute on the host to compare */
    for( i = 0; i < n; ++i ) 
    {

    	exception = exception+a[i]*b[i];

    }
    printf("Programming by OpenACC.");
    printf("The vector dimension is %d \n",n);
    
    /* check the results */

    if (abs(result-exception) < 0.001)
    	{
    		printf( "After compared with exception results the result was assert as Right.\n" );
    	    
    	}
    else{
    		printf( "After compared with exception results the result was assert as wrong. \n" );
    	}

    printf("parallel time:%d microseconds\n ",timeuse);
    printf("a*b=%.6g \n",result);
    return 0;
}
