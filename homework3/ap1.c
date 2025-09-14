#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];                                    // ũ�� 5�� ������ �迭 ����
    int *plist[5] = {NULL,};                        // ũ�� 5�� ������ ������ �迭 ���� NULL������ �ʱ�ȭ
    plist[0] = (int *)malloc(sizeof(int));          // ������ �迭 0�ڸ��� �����Ҵ� �ּҸ� ����
    list[0] = 1;                                    // �迭 0�ڸ��� �� 1����
    list[1] = 100;                                  // �迭 1�ڸ��� �� 100����
    *plist[0] = 200;                                // ������ �迭�� 0�ڸ��� ����Ű�� �ּҿ� �� �Է�
    printf("list[0] = %d\n", list[0]);              // �迭�� 0�ڸ� �� ���
    printf("&list[0] = %p\n", &list[0]);            // ������ 0�ڸ� �ּҰ� ���
    printf("list = %p\n", list);                    // �迭�� �̸��� �������̹Ƿ� �迭�� ù�ڸ��� �ּ� ���
    printf("&list = %p\n", &list);                  // 
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]);              // �迭�� 1�ڸ� �� ���
    printf("&list[1] = %p\n", &list[1]);            // �迭�� 1�ڸ� �ּҰ����� 0�ڸ��� �ּҰ� ���̴� 4�̴�
    printf("*(list+1) = %d\n", *(list + 1));        // �迭�� 1�ڸ� �� ���
    printf("list+1 = %p\n", list+1);                // �迭�� 1�ڸ� �ּҰ� ���
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]);          // ������ �迭 0�ڸ��� ����Ű�� �ּҿ� �� ���
    printf("&plist[0] = %p\n", &plist[0]);          // ������ �迭 0�ڸ��� �ּҰ� ���
    printf("&plist = %p\n", &plist);                // ������ �迭 ù�ڸ��� �ּҰ� ���
    printf("plist = %p\n", plist);                  // ������ �迭 ù�ڸ��� �ּҰ� ���
    printf("plist[0] = %p\n", plist[0]);            // ������ �迭 0�ڸ��� ����Ű�� �ּҰ� ���
    printf("plist[1] = %p\n", plist[1]);            // ������ ������ �迭�� NULL����
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);
    printf("[----- [���ؼ�] [2021041051] -----]");
    free(plist[0]);                                 // �����Ҵ� ���ذ��� ������
}