/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;


/* �Լ� ����Ʈ */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
	printf("[----- [���ؼ�] [2021041051] -----]\n");
	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(h != NULL)
		freeList(h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode));	// ��� �ϳ��� ����ü listnode ũ�⸸ŭ �����Ҵ� ���ش�
	node->key=key;	// ����� Ű�� ���� Ű���� �޾��ش�

	listNode* p = h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
	listNode* prev = NULL;	// p�� ���� ��带 ����Ű�� ������

    if(p==NULL){	// �� ����Ʈ�� ���
        node->link=p;	// ��尡 p�� ����Ű�� �Ѵ�
        h->first=node;	// ����尡 ��带 ����Ű�� �Ѵ�
        return 0;
    }
    else{
        while(p!=NULL){	// ����Ʈ�� ������ �˻�
            if(node->key<p->key) break;	// �Է¹��� key���� ū���� ������ ��� �˻�
            prev=p;
            p=p->link;
        }
        if(prev==NULL){	// �˻��� ��尡 ù��° ����� ���
            node->link=p;	// ��尡 p�� ����Ű�� �Ѵ�
            h->first=node;	// ����尡 ��带 ����Ű�� �Ѵ�
        }
        else{	// �Ϲ����� ����� ��� ����
            node->link=p;	// ��尡 p�� ����Ű�� �Ѵ�
            prev->link=node;	// ���� ��尡 ��带 ����Ű�� �Ѵ�
        }
    }

	return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {

    listNode* node=(listNode*)malloc(sizeof(listNode));	// ��� �ϳ��� ����ü listnode ũ�⸸ŭ �����Ҵ� ���ش�
    node->key=key;	// ����� Ű�� ���� Ű���� �޾��ش�

    listNode *p=h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
    if(p==NULL){	// �� ����Ʈ�� ���
        node->link=p;
        h->first=node;
        return 0;
    }
    while(1){
        if(p->link==NULL){	// ����Ʈ�� ������ ��� �˻�
            node->link=p->link;	// ��尡 p�� ����Ű�� �Ѵ�
            p->link=node;	// p�� ��带 ����Ű�� �Ѵ�
            break;	
        }
        p=p->link;
    }

	return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
    listNode *p=h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
    listNode *prev=NULL;	// p�� ���� ��带 ����Ű�� ������

    if(p==NULL){	// �� ����Ʈ�� ���
        printf("empty node..\n");
        return 0;	// �������� �ʰ� ����
    }
    else{
        h->first=p->link;	// ����尡 �ι�° ��带 ����Ű�� �Ѵ�
        free(p);	// ù��° ��� free
    }

	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
    listNode *p=h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
    listNode *prev=NULL;	// p�� ���� ��带 ����Ű�� ������
    if(p==NULL){	// �� ����Ʈ�� ���
        printf("empty node..\n");
        return 0;	// �������� �ʰ� ����
    }
    else{
        while(p->key!=key){	// �Է¹��� key���� ���� ��� �˻�
            prev=p;
            p=p->link;
			if(p==NULL){	// �Է¹��� key���� ���� ��尡 ���� ���
				printf("node do not have this key..\n");
				return 0;	// �������� �ʰ� ����
			}
        }
        if(prev==NULL){	// �˻��� ��尡 ù��° ����� ���
            h->first=p->link;	// ����尡 �ι�° ��带 ����Ű�� �Ѵ�
            free(p);	// ù��° ��� free
        }
        else{	// �Ϲ����� ����� ��� ����
            prev->link=p->link;	// ������ ����� ���� ��尡 ������ ���� ��带 ����Ű�� �Ѵ�
            free(p);	// ������ ��� free
        }
    }

	return 0;

}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
    listNode *p=h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
    listNode *prev=NULL;	// p�� ���� ��带 ����Ű�� ������

    if(p==NULL){	// �� ����Ʈ�� ���
        printf("empty node..\n");
        return 0;	// �������� �ʰ� ����
    }
    else{
        if(p->link==NULL){	// ����Ʈ�� ��尡 �ϳ��� ���
            h->first=p->link;
            free(p);	// ��� free
        }
        else{
            while(p->link!=NULL){	// ����Ʈ�� ������ ��� �˻�
                prev=p;
                p=p->link;
            }
            prev->link=p->link;	// ������ ����� ���� ��尡 ������ ��带 ����Ű�� �Ѵ�
            free(p);	// ������ ��� free
        }
    }
	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ   // ���� ����� ��������� �����Ͱ� �־����
 */
int invertList(headNode* h) {	// �������� �ٲٱ� ���� listnode�� ������ 3���� ����Ͽ���
    listNode *lead=h->first;	// ����� ����Ʈ���� ù��°�� �޾��ִ� ������
    listNode *middle=NULL;	// lead�� ���� ��带 ����Ű�� ������
    listNode *tail=NULL;	// middle�� ���� ��带 ����Ű�� ������

    if(lead==NULL){	// �� ����Ʈ�� ���
        printf("empty node..\n");
        return 0;	// ����
    }
    else{
        while(1){
            middle=lead;	// middle�� lead�� �̵�
            lead=lead->link;	// lead�� ���� ���� �̵�
            middle->link=tail;	// middle�� ��������� t�� ����Ű�� �Ѵ�
            tail=middle;	// tail�� middle�� �̵�
            if(lead==NULL){	// ����Ʈ�� �������� �������� ���
                h->first=middle;	// ����尡 ����������� middle�� ����Ű�� �Ͽ� ����Ʈ�� ������ �ٲ۴�
                break;
            }
        }
    }
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

