#include<stdio.h>
#include<stdlib.h>

void main(){
    int **x;    // ���������� x ����
    printf("sizeof(x) = %lu\n", sizeof(x)); // ���� �������� x�� ũ��� 4����Ʈ�̴�.
    printf("sizeof(*x) = %lu\n", sizeof(*x));   // ���� ������ x�� �����ϰ� �ִ� �� �ּҴ� 4����Ʈ�̴�.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // ���� ������ x�� int�� �̰� �ι� �����ϰ� �װ��� int �� �����̹Ƿ� 4����Ʈ�̴�.
    printf("[----- [���ؼ�] [2021041051] -----]\n");
}