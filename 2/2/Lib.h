#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Func_Integral(double x);                           //Оголошення функцій
double left_triangle(double a, double b, int n);
double right_triangle(double a, double b, int n);
double trapeze(double a, double b, int n);
double Homer(double a, double b, int n);
int V3();
double choice();
void Draw(double s);


#endif // LIB_H_INCLUDED
