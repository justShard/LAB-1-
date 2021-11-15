#include "Lib2.h"
double Func_Integral(double x){                           //Методи та інтегральна функція
    return pow(x,2)*sqrt(1+pow(x,3));
}
double left_triangle(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n - 1;++i){
        s += h * Func_Integral(a + i * h);
    }
    Draw(s);
    return s;
}
double right_triangle(double a, double b, int n){
    double h = (b - a) / n;
    double s = 0;
    for(int i = 0; i <= n;i++){
        s += h * Func_Integral(a + i * h);
    }
    Draw(s);
    return s;
}
double trapeze(double a, double b, int n){
    double h = (b - a) / n;
    double s = Func_Integral(a) + Func_Integral(b);
    for(int i = 0;i <= n - 1;i++){
        s += 2 * Func_Integral(a+ i * h);
    }
    s *= h / 2;
    Draw(s);
    return s;
}
double Homer(double a, double b, int n){
    double h = (b - a) / n;
    double s = Func_Integral(a) + Func_Integral(b);
    int k = 0;
    for(int i = 0;i <= n - 1;i++){
        k = 2 + 2 * (i % 2);
        s += k * Func_Integral(a + i * h);
    }
    s *= h / 3;
    Draw(s);
    return s;
}
void Draw(double s){                                       //Побудва таблиці
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
        puts("\xBA        F(x)      \xBA          S        \xBA");
        puts("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA");
        printf("\xBA x^2*sqrt(1+x^3)  \xBA%12.3f       \xBA\n",s);

}
int err(){
    printf("Wrong Choice. Choice again.\n");
    choice();
}

double choice(){
    int choice,n;
    double a,b;
    printf("1) Left triangle\n2) Right triangle\n3) Trapeze\n4) Simpson\n5) All");
    printf("\nChoice you variant:\t");
	scanf("%i", &choice);
	printf("Input variables\na:\t");
	scanf("%lf", &a);
	printf("\nb:\t");
	scanf("%lf", &b);
	printf("\nn:\t");
	scanf("%i", &n);                                        //Тернарний оператор
	double Method = choice == 1 ? left_triangle(a,b,n) : choice == 2 ? right_triangle(a,b,n) : choice == 3 ? trapeze(a,b,n) : choice == 4 ? Homer(a,b,n) : choice == 5 ? left_triangle(a,b,n),right_triangle(a,b,n),trapeze(a,b,n),Homer(a,b,n) : err();
    return Method;
}
