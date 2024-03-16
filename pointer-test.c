#include <stdio.h>

int main(){
    int i, *p;  // 정수형 변수와 포인터 변수 선언

    i = 10;     // i에 10 저장

    printf("value of i = %d\n", i);     // 10이 저장된 i의 값 출력
    printf("address of i = %p\n", &i);  // & 을 사용함으로서 i의 주소값을 출력
    printf("value of p = %p\n", p);     // 포인터 변수p의 값을 출력
    printf("address of p = %p\n", &p);  // 포인터 변수p의 주소을 출력

    p = &i; // 포인터 변수 p에 i의 주소값을 저장

    printf("\n\n----- after p = &i ------------\n\n");
    printf("value of p = %p\n", p);     // 포인터 변수 p에 저장된 i의 주소을 출력
    printf("address of p = %p\n", &p);  // 포인터 변수 p의 주소를 출력
    printf("dereferencing *p = %d\n", *p);  // 포인터 변수 p가 가르키고 있는 i의 값을 출력

    return 0;
}