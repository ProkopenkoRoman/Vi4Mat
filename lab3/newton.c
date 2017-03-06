#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double proizvodnaya(double x);
void newton(double a, double e);

double f(double x){
	return x*x*(x-1);
	//return x*(x-1)*(x-2)*(x-3) ;
}

double proizvodnaya(double x){
	return 3*x*x-2*x;
	//return 4*x*x*x - 18*x*x + 22*x - 6;
}

void main(){
	double x = 0, x0, a, b;
	int iter = 1;
	double e = 0.001;
	
	printf("Input 1 point\n");
    scanf("%lf", &a);
    printf("\nInput 2 point\n");
    scanf("%lf", &b);
    printf("\n");
    
	int i, n;
    n = (fabs(a)+fabs(b))/0.1;
    for(i = 0; i < n; i++){
    //   a = a + 0.1;  

        if (f(a) < 0 && f(a - 0.1) > 0){
          newton(a, e);
            
          printf("--------------------------------\n");
             
       }
      
       
        if (f(a) > 0 && f(a - 0.1) < 0){
          newton(a, e);
          printf("******************************\n");
        }
        
        if ((f(a) > -0.0001) && (f(a) < 0.0001)){
         // newton(a, e);
          printf("x = %lf\n", f(a));
        }
    a = a + 0.1;  

     // printf("f1 = %lf f2 = %lf\n", f(a), f(a - 0.1));
    }
    
	system ("pause");
}

void newton(double a, double e){
     double x0, x;
     x = a;
     do{
		x0 = x; // x0 - точка близкая к точному решению
		x = x0 - f(x) / proizvodnaya(x);
	}
	while (fabs(x0 - x) > e);
	printf("x = %.6f\n", x);
}
