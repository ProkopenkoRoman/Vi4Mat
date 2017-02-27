#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);
double proizvodnaya(double x);

double func(double x){
//	return pow(x,3)+2*pow(x,2)+3*x+5; //значение функции в точке x
	return x*x*x*x + 9*x*x*x - 15*x*x +21*x -9;
}

double proizvodnaya(double x){
//	return 3*pow(x,2)+4*x+3; //значение производной функции в точке x
	return 4*x*x*x + 27*x*x - 30*x +21;
}

void main(){
	double x = 0, x0;
	int iter = 1;
	double e = 0.000001;
	do{
		x0 = x;
		x = x0 - func(x) / proizvodnaya(x);
		printf("%d iteration: x = %.6f\n", iter, x);
		iter++;
	}
	while (fabs(x0 - x) > e);
	printf("x = %.6f", x);
}
