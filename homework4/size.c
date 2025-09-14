#include<stdio.h>
#include<stdlib.h>

void main(){
    int **x;    // 더블포인터 x 선언
    printf("sizeof(x) = %lu\n", sizeof(x)); // x의 크기는 포인터의 크기로 8이지만 32비트 컴파일러에서는 4바이트
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // *x의 크기는 참조된 주소값을 담은 포인터의 크기로 4바이트
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // **x는 두번 참조되어 최종적인 값이 담긴 공간이고 그 공간은 int형 공간이므로 4바이트
}