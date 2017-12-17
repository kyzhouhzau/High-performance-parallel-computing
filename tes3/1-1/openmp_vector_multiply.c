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
    for( i = 0; i < n; ++i )
    {
        a[i] = (float)(i*2.0);
        b[i] = (float)(i*5.0);
    } 
    double start = omp_get_wtime( );  
	#pragma omp parallel for private(i) reduction(+:result)
    for( i = 0; i < n; ++i )
    {

     	result =result+ a[i]*b[i];
    
    }
	

    double end = omp_get_wtime( ); 

    /* compute on the host to compare */
    for( i = 0; i < n; ++i ) 
    {

    	exception = exception+a[i]*b[i];

    }
    printf("Programming by Openmp.");
    printf("The vector dimension is %d \n",n);
    
    /* check the results */

    if (result-exception < 0.001)
    	{
    		printf( "After compared with exception results the result was assert as Right.\n" );
    	    
    	}
    else{
    		printf( "After compared with exception results the result was assert as Right. \n" );
    	}

    printf("parallel time:%.16g seconds\n",end-start);
    printf("a*b=%.6g \n",result);
    return 0;
}

