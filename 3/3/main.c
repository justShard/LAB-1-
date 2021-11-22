#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#define SP printf("\n");        //������ ��� �������� ����� SP



float func(float x){
    return pow(x,2)-sqrt(1-pow(x,3));       //������ �������
}



void MethodHalfDivision(float a, float b, float e, unsigned int iter){       //���������� �������(����� ����������� ������)
    float c;
    unsigned int q, n=iter, i=0;
    do{
        if(i==iter){
            printf("\nChoose an action?\n1)exit and display result\n2)plus iteration\n3)just find root\n ");
            SP
            scanf("%u",&q);
            SP
            printf("\n");
            if(q==1){
                break;
            } else if(q==2){
                iter+=n;
            } else if(q==3){
                iter=INFINITY;
            }
        }

        c=(a+b)/2;                   // Xi
        if ((func(a)*func(c))>0)
            a = c;
        else
            b = c;
        i++;

            printf("x = %f, f(x) = %f, iteration = %u\n", c,func(c), i);
            getch();
    }
    while ((b-a)/2>=e);
    SP
    printf("x = %.2f, f(x) = %.2f, iteration = %u\n", c,func(c), i);
}



void MethodChord(float a, float b, float e, float iter){        //���������� �������(����� ����)
    float c;
    unsigned int q, n=iter, i=0;

    do{
         if(i==iter){
            printf("\nChoose an action?\n1)exit and display result\n2)plus iteration\n3)just find root\n");
            sp
            scanf("%u",&q);
            sp
            if(q==1){
                break;
            } else if(q==2){
                iter+=n;
            } else if(q==3){
                iter=INFINITY;
            }
        }
                                                                //Xi
        c=(func(b)*a-func(a)*b)/(func(b)-func(a));
        i++;

            printf("x = %f, f(x) = %f, iteration = %u\n", b,func(b), i);
            getch();
    }
    while(fabs(func(b)) > e);
    SP
printf("x = %.2f, f(x) = %.2f, iteration = %u\n", b,func(b), i);
}

void main()      //������� ��������
{
    float a, b, e, tStop,tStart;
    unsigned int method, q, n, iter, i=0, c;

    printf("Chose method?\n1)Half division\n2)Chord\n ");       //���� ������ �� �������� �����
    SP
    scanf("%u", &method);
    SP
    do{
    printf("Enter lower limit(x1): ");
    scanf("%f", &a);
    printf("Enter higher limit(x2): ");
    scanf("%f", &b);
    }while(func(a)*func(b)>0);      //��������
    printf("Enter allowable error: ");
    scanf("%f", &e);
    printf("\rEnter maximum number of iterations: ");
    scanf("%u", &iter);
    SP
    printf("\rEnter mode:\n0)Find root\n1)Display intermediate results\n");
    scanf("%f", &q);
    SP

    tStart = clock(); //˳�������


    switch(method){     // ���� ������ ����������
    case 1:
    MethodHalfDivision(a, b, e, iter);
    break;
    case 2:
    MethodChord(a, b, e, iter);
    break;
    }

      tStop=clock();
    float time=(tStop-tStart)/CLOCKS_PER_SEC;

    printf("\nTime costs = %f second",time);

    return 0;
}
