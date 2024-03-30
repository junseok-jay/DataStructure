#include<stdio.h>
#include<stdlib.h>

void main(){
    int **x;    // 더블포인터 x 선언
    printf("sizeof(x) = %lu\n", sizeof(x)); // 더블 포인터의 x의 크기는 4바이트이다.
    printf("sizeof(*x) = %lu\n", sizeof(*x));   // 더블 포인터 x가 참조하고 있는 그 주소는 4바이트이다.
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // 더블 포인터 x가 int형 이고 두번 참조하고 그곳은 int 형 공간이므로 4바이트이다.
    printf("[----- [전준석] [2021041051] -----]\n");
}