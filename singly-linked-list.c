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
	
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key=key;

	listNode* p = h->first;
	listNode* prev = NULL;

    if(p==NULL){
        node->link=p;
        h->first=node;
        return 0;
    }
    else{
        while(p!=NULL){
            if(node->key<p->key) break;
            prev=p;
            p=p->link;
        }
        if(prev==NULL){
            node->link=p;
            h->first=node;
        }
        else{
            node->link=p;
            prev->link=node;
        }
    }

	return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {

    listNode* node=(listNode*)malloc(sizeof(listNode));
    node->key=key;

    listNode *p=h->first;
    if(p==NULL){
        node->link=p;
        h->first=node;
        return 0;
    }
    while(1){
        if(p->link==NULL){
            node->link=p->link;
            p->link=node;
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
    listNode *p=h->first;
    listNode *prev=NULL;

    if(p==NULL){
        printf("empty node..\n");
        return 0;
    }
    else{
        h->first=p->link;
        free(p);
    }

	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
    listNode *p=h->first;
    listNode *prev=NULL;
    if(p==NULL){
        printf("empty node..\n");
        return 0;
    }
    else{
        while(p->key!=key){
            prev=p;
            p=p->link;
			if(p==NULL){
				printf("node do not have this key..\n");
				return 0;
			}
        }
        if(prev==NULL){
            h->first=p->link;
            free(p);
        }
        else{
            prev->link=p->link;
            free(p);
        }
    }

	return 0;

}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
    listNode *p=h->first;
    listNode *prev=NULL;

    if(p==NULL){
        printf("empty node..\n");
        return 0;
    }
    else{
        if(p->link==NULL){
            h->first=p->link;
            free(p);
        }
        else{
            while(p->link!=NULL){
                prev=p;
                p=p->link;
            }
            prev->link=p->link;
            free(p);
        }
    }
	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ   // ���� ����� ��������� �����Ͱ� �־����
 */
int invertList(headNode* h) {
    listNode *lead=h->first;
    listNode *middle=NULL;
    listNode *trail=NULL;

    if(lead==NULL){
        printf("empty node..\n");
        return 0;
    }
    else{
        while(1){
            middle=lead;
            lead=lead->link;
            middle->link=trail;
            trail=middle;
            if(lead==NULL){
                h->first=middle;
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

