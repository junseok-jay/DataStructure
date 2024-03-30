#include <stdio.h>

struct student1 {   // student1 구조체 정의
    char lastName;
    int studentId;
    char grade;
};

typedef struct {    // student2 typedef 구조체 정의
    char lastName;
    int studentId;
    char grade;
} student2;

int main() {
    struct student1 st1 = {'A', 100, 'A'};  // student1 형의 구조체 st1 선언
    printf("st1.lastName = %c\n", st1.lastName);    // 구조체 st1의 lastName에 접근한다
    printf("st1.studentId = %d\n", st1.studentId);  // 구조체 st1의 studentId에 접근한다
    printf("st1.grade = %c\n", st1.grade);  // 구조체 st1의 grade에 접근한다
    student2 st2 = {'B', 200, 'B'}; // typedef 로 정의된 구조체 이므로 struct로 선언할수 없다
    printf("\nst2.lastName = %c\n", st2.lastName);  // 구조체 st2의 lastName에 접근한다
    printf("st2.studentId = %d\n", st2.studentId);  // 구조체 st2의 studentId에 접근한다
    printf("st2.grade = %c\n", st2.grade);  // 구조체 st2의 grade에 접근한다
    student2 st3;   // student2 형의 구조체 st3 선언

    st3 = st2;  // 같은 형의 구조체이므로 st2을 st3으로 복사할수 있다

    printf("\nst3.lastName = %c\n", st3.lastName);  // 구조체 st3의 lastName에 접근한다
    printf("st3.studentId = %d\n", st3.studentId);  // 구조체 st3의 studentId에 접근한다
    printf("st3.grade = %c\n", st3.grade);  // 구조체 st3의 grade에 접근한다
    /* equality test */
    if(st3.lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade) /* not working */
    // 구조체는 다양한 원소를 가지고 있기 때문에 구조체의 이름가지고는 비교 할수없다
    // 따라서 구조체 안의 원소끼리 서로 비교해서 두개의 구조체가 같은지 비교해준다
    printf("equal\n");
    else
    printf("not equal\n");
    printf("[----- [전준석] [2021041051] -----]\n");
    return 0;
}