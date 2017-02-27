#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bisec(double a, double b, double c, double eps);

double f(double x){
    return x*x*x*x + 9*x*x*x - 15*x*x +21*x -9;
//return pow(x, 2) - 4;
}
int main(){
    double a, b, c, eps = 0.001;
    printf("Input 1 point\n");
    scanf("%lf", &a);
    printf("\nInput 2 point\n");
    scanf("%lf", &b);
    printf("\n");
    if (a > b){ // неверный интервал
    	printf("ERROR: Invalid interval!\n");
    	getch();
    	exit(1);
    }
    ///это проверка на смену знака
    int flag1 = 0, flag2 = 1, i, n;
    n = (fabs(a)+fabs(b))/0.1;
    for(i = 0; i < n; i++){
       a = a + 0.1;  
       
       if (f(a) > 0)
          flag1 = 1;
       else{
          if (f(a) < 0 && flag1 == 1 && flag2 == 1){
                    //вызываем метод бисекций
             bisec(a - 0.1, a, c, eps);
             flag1 = 0; 
             }
       }
       
       if (f(a) < 0)
          flag2 = 0;
       else{
          if (f(a) > 0 && flag2 == 0 && flag1 == 1){
                    //вызываем метод бисекций
             bisec(a - 0.1, a, c, eps);
             flag2 = 1;
             }
       }
    }
      system("pause");
return 0;
}
void bisec(double a, double b, double c, double eps){
     while( (b-a)>2*eps ){
        c = (a+b)/2;
        if (f(c)==0)
            break;
        if (f(a)*f(c)<0)
            b = c;
        else
            a = c;
    }
    printf("x = %.3f\n", c);
}
