#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];                                    // 크기 5인 정수형 배열 선언
    int *plist[5] = {NULL,};                        // 크기 5인 정수형 포인터 배열 선언 NULL값으로 초기화
    plist[0] = (int *)malloc(sizeof(int));          // 포인터 배열 0자리에 동적할당 주소를 받음
    list[0] = 1;                                    // 배열 0자리에 값 1받음
    list[1] = 100;                                  // 배열 1자리에 값 100받음
    *plist[0] = 200;                                // 포인터 배열의 0자리가 가르키는 주소에 값 입력
    printf("list[0] = %d\n", list[0]);              // 배열의 0자리 값 출력
    printf("&list[0] = %p\n", &list[0]);            // 베열의 0자리 주소값 출력
    printf("list = %p\n", list);                    // 배열의 이름은 포인터이므로 배열의 첫자리의 주소 출력
    printf("&list = %p\n", &list);                  // 
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]);              // 배열의 1자리 값 출력
    printf("&list[1] = %p\n", &list[1]);            // 배열의 1자리 주소값으로 0자리와 주소값 차이는 4이다
    printf("*(list+1) = %d\n", *(list + 1));        // 배열의 1자리 값 출력
    printf("list+1 = %p\n", list+1);                // 배열의 1자리 주소값 출력
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]);          // 포인터 배열 0자리에 가르키는 주소에 값 출력
    printf("&plist[0] = %p\n", &plist[0]);          // 포인터 배열 0자리의 주소값 출력
    printf("&plist = %p\n", &plist);                // 포인터 배열 첫자리의 주소값 출력
    printf("plist = %p\n", plist);                  // 포인터 배열 첫자리의 주소값 출력
    printf("plist[0] = %p\n", plist[0]);            // 포인터 배열 0자리가 가르키는 주소값 출력
    printf("plist[1] = %p\n", plist[1]);            // 나머지 포인터 배열은 NULL값임
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);
    printf("[----- [전준석] [2021041051] -----]");
    free(plist[0]);                                 // 동적할당 해준것을 해제함
}