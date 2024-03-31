#include <stdio.h>

struct student1 {   // student1 ����ü ����
    char lastName;
    int studentId;
    char grade;
};

typedef struct {    // student2 typedef ����ü ����
    char lastName;
    int studentId;
    char grade;
} student2;

int main() {
    struct student1 st1 = {'A', 100, 'A'};  // student1 ���� ����ü st1 ����
    printf("st1.lastName = %c\n", st1.lastName);    // ����ü st1�� lastName�� �����Ѵ�
    printf("st1.studentId = %d\n", st1.studentId);  // ����ü st1�� studentId�� �����Ѵ�
    printf("st1.grade = %c\n", st1.grade);  // ����ü st1�� grade�� �����Ѵ�
    student2 st2 = {'B', 200, 'B'}; // typedef �� ���ǵ� ����ü �̹Ƿ� struct�� �����Ҽ� ����
    printf("\nst2.lastName = %c\n", st2.lastName);  // ����ü st2�� lastName�� �����Ѵ�
    printf("st2.studentId = %d\n", st2.studentId);  // ����ü st2�� studentId�� �����Ѵ�
    printf("st2.grade = %c\n", st2.grade);  // ����ü st2�� grade�� �����Ѵ�
    student2 st3;   // student2 ���� ����ü st3 ����

    st3 = st2;  // ���� ���� ����ü�̹Ƿ� st2�� st3���� �����Ҽ� �ִ�

    printf("\nst3.lastName = %c\n", st3.lastName);  // ����ü st3�� lastName�� �����Ѵ�
    printf("st3.studentId = %d\n", st3.studentId);  // ����ü st3�� studentId�� �����Ѵ�
    printf("st3.grade = %c\n", st3.grade);  // ����ü st3�� grade�� �����Ѵ�
    /* equality test */
    if(st3.lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade) /* not working */
    // ����ü�� �پ��� ���Ҹ� ������ �ֱ� ������ ����ü�� �̸�������� �� �Ҽ�����
    // ���� ����ü ���� ���ҳ��� ���� ���ؼ� �ΰ��� ����ü�� ������ �����ش�
    printf("equal\n");
    else
    printf("not equal\n");
    printf("[----- [���ؼ�] [2021041051] -----]\n");
    return 0;
}