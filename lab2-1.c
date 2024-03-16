#include <stdio.h>

int main()
{
    char charType;      // ������ ���� ����
    int integerType;    // ������ ���� ����
    float floatType;    // �Ǽ��� ���� ����
    double doubleType;  // ������ ���� ����

    printf("Size of char: %ld byte\n", sizeof(charType));       // ������ ������ ũ�⸦ ���
    printf("Size of int: %ld bytes\n", sizeof(integerType));
    printf("Size of float: %ld bytes\n", sizeof(floatType));
    printf("Size of double: %ld bytes\n", sizeof(doubleType));
    printf("-----------------------------------------\n");
    printf("Size of char: %ld byte\n", sizeof(char));           // ����,����,�Ǽ�,�������� ũ�� ���
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));
    printf("-----------------------------------------\n");
    printf("Size of char*: %ld byte\n", sizeof(char *));        // ����,����,�Ǽ�,�������� ������ ũ�⸦ ���
    printf("Size of int*: %ld bytes\n", sizeof(int *));         // �����ʹ� �ּҸ� ��� ������ �������� ũ��� ���� �����ϴ�
    printf("Size of float*: %ld bytes\n", sizeof(float *));     
    printf("Size of double*: %ld bytes\n", sizeof(double *));   
    printf("[----- [���ؼ�] [2021041051] -----]");
    return 0;
}