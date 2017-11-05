#! usr/bin/env python3
# -*- coding:utf-8 -*-
'''
Solve the quadratic equation x2 + 3x-5.6 = 0.
Author:'kyzhou'
'''
import math


def fun(a,b,c):
    dis=b**2-4*a*c
    if dis>0:
        x1=(-b+math.sqrt(dis))/(2.0*a)
        x2=(-b-math.sqrt(dis))/(2.0*a)
        print('x1=%.2f,x2=%.2f' % (x1,x2))
    elif dis==0:
        x=(-b+math.sqrt(dis))/(2.0*a)
        print('x=%d',x)
    else:
        print("Please enter legal parameters ")

def main():
    a=float(input('a='))
    b=float(input('b='))
    c=float(input('c='))
    fun(a,b,c)

if __name__=='__main__':
    main()