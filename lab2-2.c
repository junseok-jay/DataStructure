#include <stdio.h>
int main()
{
    int i;      // 정수형 변수 선언 
    int *ptr;   // 정수형 포인터 선언
    int **dptr; // 정수형 이중 포인터 선언
    i = 1234;
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i);            // i의 값 출력
    printf("address of i == %p\n", &i);         // i의 주소 출력
    printf("value of ptr == %p\n", ptr);        // 포인터 변수의 값 출력
    printf("address of ptr == %p\n", &ptr);     // 포인터 변수의 주소 출력
    ptr = &i; /* ptr is now holding the address of i */
    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);        // 포인터가 i를 가르키고 있어서 i의 주소 출력
    printf("address of ptr == %p\n", &ptr);     // 포인터 변수의 주소 출력
    printf("value of *ptr == %d\n", *ptr);      // 포인터가 가르키고 있는 주소 안에 값인 i의 값을 출력한다
    dptr = &ptr; /* dptr is now holding the address of ptr */
    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of dptr == %p\n", dptr);      // 이중 포인터가 포인터 ptr를 가르키고 있으므로 ptr의 주소 출력
    printf("address of dptr == %p\n", &dptr);   // 이중 포인터 dptr의 주소 출력 
    printf("value of *dptr == %p\n", *dptr);    // 이중 포인터가 가르키는 ptr의 값을 출력
    printf("value of **dptr == %d\n", **dptr);  // 이중 포인터 ptr을 가르키고 ptr은 i을 가르키므로 i의 값을 출력한다
    *ptr = 7777; /* changing the value of *ptr */
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i);            // ptr이 가르키는 주소안의 값즉, i을 7777로 바꾸었다
    printf("value of *ptr == %d\n", *ptr);      // *ptr와 **dptr은 동일한 i을 가르키기 때문에 i의 값 출력
    printf("value of **dptr == %d\n", **dptr);
    **dptr = 8888; /* changing the value of **dptr */
    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i);            // **dptr 로 i를 가르키며 i의 값을 8888로 바꾸었다.
    printf("value of *ptr == %d\n", *ptr);      // i값과 *ptr은 i을 가르키고 i의 값을 출력
    printf("value of **dptr == %d\n", **dptr);
    printf("[----- [전준석] [2021041051] -----]");
    return 0;
}