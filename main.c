#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <Windows.h>

int checkLenght(float a) {
  int n = 0;
  int temp;
  if (a < 0)
    n++;
  for (;;) {
    temp = a;
    if (temp == 0)
      return n;
    a /= 10;
    n++;
  }
}

double foo(float x) {
  return sin(x) * cos(x);
}

void paintTable(float x1, float x2, float delta, unsigned int n ) {
  int iLenght, XLenght, fooLenght;
  int i = 1;
  float X = x1;
  for (; i < n; i++) {
    iLenght = checkLenght(i);
    XLenght = checkLenght(X);
    fooLenght = checkLenght(foo(X));
    printf("+---------+---------+---------+\n");
    printf("|");
    for (int j = 0;j< 9-iLenght;j++) {
      printf(" ");
    }
    printf("%d|", i);

    for (int j = 0; j < 6 - XLenght; j++) {
      printf(" ");
    }
    printf("%.2f|", X);
    for (int j = 0; j < 4 - fooLenght; j++) {
      printf(" ");
    }
    printf("%.3f|", foo(X));
    printf("\n");
    X += delta;
  }
  printf("+---------+---------+---------+\n");
}

void Menu() {
  printf("*******************************\n");
  printf("*     N   *    X    *   F(X)  *\n");
  printf("*******************************\n");
}


int main() {
  unsigned int choice = 1;
  unsigned int n;

  float x1, x2, delta,temp;

  printf("Enter varint 1 or 2\n");
  scanf_s("%d", &choice);
  system("cls");

  switch (choice) {
  case 1:
    printf("Enter initial and final value of arguments number of table points\n");
    scanf_s("%f", &x1);
    scanf_s("%f", &x2);
    scanf_s("%d", &n);

    delta = (x2 * x1) / (n - 1);

    printf("x1=%.3f  x2=%.3f number points=%d\n", x1, x2, n);
    n++;

    break;

  case 2:
    printf("Enter the initial and final value of the arguments step of changing the argument\n");
    scanf_s("%f", &x1);
    scanf_s("%f", &x2);
    scanf_s("%f", &delta);
    n = 2;
    temp = x1;
    for (;;) {
      temp += delta;
      if (temp >= x2)
        break;
      n++;

    }
    printf("x1=%.3f  x2=%.3f delta=%.3f\n", x1, x2, delta);

    break;
  }
  Menu();
  paintTable(x1, x2, delta, n);

  system("pause");
  return 0;
}
