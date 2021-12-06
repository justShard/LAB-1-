#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


int Made(int m1, int m2, int n2);
void MatrixMaxMin(int **a,int m1);
void Tp(int **b,int m2,int n2);
void sortA(int **a,int m1);
void sum(int **a,int **b,int m1,int m2,int n2);

void main(){

    int m1, m2, n2;
    printf("Input size matrix 1:\t");
    scanf("%d",&m1);
    printf("Input size matrix 2\nCols:\t");
    scanf("%d",&m2);
    printf("\nRows:\t");
    scanf("%d",&n2);
    Made(m1,m2,n2);

    getch();
}



int Made(int m1, int m2, int n2){                           //Завнення матриць та вибір дії з ними




    int var1,var2;
    int ***a;
    int **b;


    srand(time(0));                         //Випадковий seed

    a = (int***)malloc(m1 * sizeof(int **));
    for (int i = 0; i < m1; i++){
        a[i] =  malloc(m1 * sizeof(int));
    }
    a[1][1] = 7;
    b = malloc(n2 * sizeof(int *));
    for (int i = 0; i < n2; i++){
        b[i] =  malloc(m2 * sizeof(int));
    }
    printf("Auto or manual filling of the array?\n(1 - Auto  0 - Manual):\n ");
    scanf("%d",&var1);

    if(var1 == 0){                                                          //Автоматичне заповнення масиву
         for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }
    }if(var1 == 1){
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < m1; j++){
                printf("b[%d][%d] = %d\n", i, j,rand()%25);
                a[i][j] = rand()%25;
            }
        }
        for (int i = 0; i < m1 ; i++){
            for (int j = 0; j < m1; j++){
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }
    }else{printf("\nBie bie");}
    printf("\Random or manual filling of the array 2?\n(1 - Random  0 - Manual):\n ");
    scanf("%d", &var2);
    printf("\n variant  = %d \n", var2);
    if(var2 == 0){                                                          //Ручне заповнення масиву
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &b[i][j]);
            }
        }
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }
    }if(var2 == 1){
        for (int i = 0; i < n2; i++){
            for (int j = 0; j < m2; j++){
                printf("b[%d][%d] = %d\n", i, j,rand()%25);
                b[i][j] = rand()%25;
            }
        }
        for (int i = 0; i < n2 ; i++){
            for (int j = 0; j < m2; j++){
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }
    }else{printf("\nBie bie");}
    Mult(a,b,m1,m2,n2);
    printf("Chois variant:\n1 - MaxMin\n2 - Tp\n3 - Mult\n4 - Sort\n5 - Summ\n");

    int choise=0;
    scanf("%d",&choise);

    switch(choise){

    case 1:
    MatrixMaxMin(a, m1);
    break;

    case 2:
    Tp(b, m2, n2);
    break;

    case 3:
    Mult(a, b, m1, m2, n2);
    break;

    case 4:
    SortA(a, m1);
    break;

    case 5:
    Sum(a, b, m1, m2, n2);
    break;
    }

    for (int i = 0; i < m1; i++)
    free(a[i]);
    free(a);
    for (int i = 0; i < n2; i++)
    free(b[i]);
    free(b);
}
void MatrixMaxMin(int **a,int m1){                          //Максимальні та мінімальні значення матриці
    int max = 1;
    int min = 0;
    for(int i = 0; i < m1; i++ ){
        for (int j = m1 - 1; j > i;j--){
            max = (a[i][j] > max ? a[i][j] : max);
            min = (a[i][j] < min ? a[i][j] : min);
        }

    }
    printf("\nMax up:\t%d\nMin up:\t%d\n",max,min);
    min = 1;
    max = 0;
    for(int i = 0;i < m1;i++){
        for(int j = 0; j < i; j++){
            max = (a[i][j] > max ? a[i][j] : max);
            min = (a[i][j] < min ? a[i][j] : min);
        }
    }
    printf("\nMax down:\t%d\nMin down:\t%d\n",max,min);
}
void Tp(int **b,int m2,int n2){                             //Транспонування матриці
    int **temp;
     temp = malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++){
        temp[i] =  malloc(n2 * sizeof(int));
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            temp[i][j] = b[j][i];
        }
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            printf("%d\t",temp[i][j]);
        }
        printf("\n");
    }

for (int i = 0; i < n2; i++)
    free(temp[i]);
    free(temp);
}
void Mult(int **a,int **b,int m1,int m2,int n2){            //Добуток
    int **temp;
    temp = malloc(m2 * sizeof(int *));
    for (int i = 0; i < m2; i++){
        temp[i] =  malloc(n2 * sizeof(int));
    }
    if(m1 != m2 ){
        printf("Error\n");
        return;
    }
    for(int i = 0; i < m2;i++){
        for (int j = 0;j < n2;j++){
            temp[i][j] = a[i][j] * b[j][i];
        }
    }
    for(int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            printf("%d\t",temp[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n2; i++)
    free(temp[i]);
    free(temp);
}
void SortA(int **a,int m1){                                 //Сортування
    int row;
    int arr[m1];
    printf("choose a row: \t");
    scanf("%d",&row);
    row--;
    for(int i = 0 ; i < m1; i++){
       for(int j = 0 ; j < m1 -i ; j++){
           if(a[row][j] > a[row][j+1]){
                int tmp = a[row][j];
                a[row][j] = a[row][j+1];
                a[row][j+1] = tmp;
           }
        }
    }
    printf("\n");
    for (int i = 0;i < m1;i++){
        printf("%d\t",a[row][i]);
    }
}
void Sum(int **a, int **b,int m1,int m2,int n2){            //Сума
    int sum =0;
    printf("\n");
    for (int i = 0;i < m1;i++){
        for(int j = 0;j < m1;j++){
            sum+=a[i][j];
        }
        printf("%d\t",sum);
        sum = 0;
    }
    sum = 0;
    printf("\n\n");
    for (int i = 0;i < m2;i++){
        for(int j = 0;j < n2;j++){
            sum+=b[j][i];
        }
        printf("\n %d\t",sum);
        sum = 0;
    }
}
