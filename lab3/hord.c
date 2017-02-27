#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x){
  return x*x*x*x + 9*x*x*x - 15*x*x + 21*x - 9;
  //return x*x - 4;
}

void find(double a, double b, double eps){
//	int iter = 1;
    while (fabs(b - a) > eps){
        a = b - (b - a) * func(b) / (func(b) - func(a));
        b = a - (a - b) * func(a) / (func(a) - func(b));
       // printf("%d iteration: x = %.3lf\n", iter, b);
     //   iter++;
    }
    printf("x = %.3lf\n", b);
}

int main(){
    double a, b, eps;
    
    printf("Input started point:\n");
    scanf("%lf", &a);
    printf("Input ended point:\n");
    scanf("%lf", &b);
    if (a > b){ // неверный интервал
    	printf("ERROR: Invalid interval!\n");
    	getch();
    	exit(1);
    }
    printf("Input precision(eps):\n");
    scanf("%lf", &eps);
    if (eps > 0.1){ //неверная точность
    	printf("ERROR: Invalid precision(eps)!\n");
    	getch();
    	exit(1);
    }
    
    ///это проверка на смену знака
    int flag1 = 0, flag2 = 1, i, n;
    n = (fabs(a)+fabs(b))/0.1;
    for(i = 0; i < n; i++){
       a = a + 0.1;  // исследуем интервал [a, b] с шагом 0.1
       
       //1-й корень
       	if (func(a) > 0)
          	flag1 = 1;
       	else{
          	if (func(a) < 0 && flag1 == 1 && flag2 == 1){
                //вызываем метод хорд
             	find(a - 0.1, a, eps);
             	flag1 = 0; 
            }
       	}
       
       //2-й корень
       	if (func(a) < 0)
          	flag2 = 0;
       	else{
          	if (func(a) > 0 && flag2 == 0 && flag1 == 1){
                //вызываем метод хорд
             	find(a - 0.1, a, eps);
             	flag2 = 1;
        	}
       	}
    }
    
    return 0;
}
