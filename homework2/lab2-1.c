#include <stdio.h>

int main()
{
    char charType;      // 문자형 변수 선언
    int integerType;    // 정수형 변수 선언
    float floatType;    // 실수형 변수 선언
    double doubleType;  // 더블형 변수 선언

    printf("Size of char: %ld byte\n", sizeof(charType));       // 각각의 변수의 크기를 출력
    printf("Size of int: %ld bytes\n", sizeof(integerType));
    printf("Size of float: %ld bytes\n", sizeof(floatType));
    printf("Size of double: %ld bytes\n", sizeof(doubleType));
    printf("-----------------------------------------\n");
    printf("Size of char: %ld byte\n", sizeof(char));           // 문자,정수,실수,더블형의 크기 출력
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));
    printf("-----------------------------------------\n");
    printf("Size of char*: %ld byte\n", sizeof(char *));        // 문자,정수,실수,더블형의 포인터 크기를 출력
    printf("Size of int*: %ld bytes\n", sizeof(int *));         // 포인터는 주소를 담기 때문에 포인터의 크기는 전부 동일하다
    printf("Size of float*: %ld bytes\n", sizeof(float *));     
    printf("Size of double*: %ld bytes\n", sizeof(double *));   
    printf("[----- [전준석] [2021041051] -----]");
    return 0;
}