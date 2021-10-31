#include <stdio.h>
#include <math.h>

double foo(float x) {
  return sin(x) * cos(x);
}

void paintTable(float x1, float x2, float delta, unsigned int n) {
  for (int i = 1; i <= n; i++, x1 += delta) {
    printf("+---------+---------+---------+\n");
    printf("|");
    printf("%9d|", i);
    printf("%9.2f|", x1);
    printf("%9.3f|", foo(x1));
    printf("\n");
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

    delta = (x2 - x1) / (n - 1);
    printf("x1=%.3f  x2=%.3f number points=%d\n", x1, x2, n);

    break;

  case 2:
    printf("Enter the initial and final value of the arguments step of changing the argument\n");
    scanf_s("%f", &x1);
    scanf_s("%f", &x2);
    scanf_s("%f", &delta);
    n = ceil((x2-x1) / delta);
    printf("x1=%.3f  x2=%.3f delta=%.3f\n", x1, x2, delta);

    break;
  }

  Menu();
  paintTable(x1, x2, delta, n);

  system("pause");
  return 0;
}
