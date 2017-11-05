#include <stdio.h>
#include <math.h>
void fun(float a,float b,float c)
{	
	float dis,x1,x2,x;
	dis=b*b-4*a*c;
	if (dis>0)
{
		x1=(-b+sqrt(dis))/(2.0*a);
        	x2=(-b-sqrt(dis))/(2.0*a);
        	printf("%.2f %.2f",x1,x2);
}

	else if (dis=0)
{
    		x=(-b+sqrt(dis))/(2.0*a);
        	printf("%.2f",x);
}

	else
{
    		printf("Please enter legal parameters ");
}
}
void main()
{
	float a,b,c;
	fun(1,3,-5.6);
}
