/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;


/* 함수 리스트 */
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
	printf("[----- [전준석] [2021041051] -----]\n");
	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
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
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
	
	listNode* node = (listNode*)malloc(sizeof(listNode));	// 노드 하나를 구조체 listnode 크기만큼 동적할당 해준다
	node->key=key;	// 노드의 키에 받은 키값을 받아준다

	listNode* p = h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
	listNode* prev = NULL;	// p의 이전 노드를 가르키는 포인터

    if(p==NULL){	// 빈 리스트일 경우
        node->link=p;	// 노드가 p를 가르키게 한다
        h->first=node;	// 헤드노드가 노드를 가르키게 한다
        return 0;
    }
    else{
        while(p!=NULL){	// 리스트를 끝까지 검색
            if(node->key<p->key) break;	// 입력받은 key보다 큰값이 나오는 노드 검색
            prev=p;
            p=p->link;
        }
        if(prev==NULL){	// 검색한 노드가 첫번째 노드일 경우
            node->link=p;	// 노드가 p를 가르키게 한다
            h->first=node;	// 헤드노드가 노드를 가르키게 한다
        }
        else{	// 일반적인 경우의 노드 삽입
            node->link=p;	// 노드가 p를 가르키게 한다
            prev->link=node;	// 이전 노드가 노드를 가르키게 한다
        }
    }

	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

    listNode* node=(listNode*)malloc(sizeof(listNode));	// 노드 하나를 구조체 listnode 크기만큼 동적할당 해준다
    node->key=key;	// 노드의 키에 받은 키값을 받아준다

    listNode *p=h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
    if(p==NULL){	// 빈 리스트일 경우
        node->link=p;
        h->first=node;
        return 0;
    }
    while(1){
        if(p->link==NULL){	// 리스트의 마지막 노드 검색
            node->link=p->link;	// 노드가 p를 가르키게 한다
            p->link=node;	// p가 노드를 가르키게 한다
            break;	
        }
        p=p->link;
    }

	return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
    listNode *p=h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
    listNode *prev=NULL;	// p의 이전 노드를 가르키는 포인터

    if(p==NULL){	// 빈 리스트일 경우
        printf("empty node..\n");
        return 0;	// 삭제하지 않고 종료
    }
    else{
        h->first=p->link;	// 헤드노드가 두번째 노드를 가르키게 한다
        free(p);	// 첫번째 노드 free
    }

	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
    listNode *p=h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
    listNode *prev=NULL;	// p의 이전 노드를 가르키는 포인터
    if(p==NULL){	// 빈 리스트일 경우
        printf("empty node..\n");
        return 0;	// 삭제하지 않고 종료
    }
    else{
        while(p->key!=key){	// 입력받은 key값을 가진 노드 검색
            prev=p;
            p=p->link;
			if(p==NULL){	// 입력받은 key값을 가진 노드가 없을 경우
				printf("node do not have this key..\n");
				return 0;	// 삭제하지 않고 종료
			}
        }
        if(prev==NULL){	// 검색한 노드가 첫번째 노드일 경우
            h->first=p->link;	// 헤드노드가 두번째 노드를 가르키게 한다
            free(p);	// 첫번째 노드 free
        }
        else{	// 일반적인 경우의 노드 삭제
            prev->link=p->link;	// 삭제할 노드의 이전 노드가 삭제할 다음 노드를 가르키게 한다
            free(p);	// 삭제할 노드 free
        }
    }

	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
    listNode *p=h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
    listNode *prev=NULL;	// p의 이전 노드를 가르키는 포인터

    if(p==NULL){	// 빈 리스트일 경우
        printf("empty node..\n");
        return 0;	// 삭제하지 않고 종료
    }
    else{
        if(p->link==NULL){	// 리스트에 노드가 하나일 경우
            h->first=p->link;
            free(p);	// 노드 free
        }
        else{
            while(p->link!=NULL){	// 리스트의 마지막 노드 검색
                prev=p;
                p=p->link;
            }
            prev->link=p->link;	// 마지막 노드의 이전 노드가 마지막 노드를 가르키게 한다
            free(p);	// 마지막 노드 free
        }
    }
	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치   // 이전 노드의 정보를담는 포인터가 있어야함
 */
int invertList(headNode* h) {	// 역순으로 바꾸기 위해 listnode형 포인터 3개를 사용하였다
    listNode *lead=h->first;	// 노드의 리스트에서 첫번째를 받아주는 포인터
    listNode *middle=NULL;	// lead의 이전 노드를 가르키는 포인터
    listNode *tail=NULL;	// middle의 이전 노드를 가르키는 포인터

    if(lead==NULL){	// 빈 리스트일 경우
        printf("empty node..\n");
        return 0;	// 종료
    }
    else{
        while(1){
            middle=lead;	// middle이 lead로 이동
            lead=lead->link;	// lead는 다음 노드로 이동
            middle->link=tail;	// middle이 이전노드인 t를 가르키게 한다
            tail=middle;	// tail이 middle로 이동
            if(lead==NULL){	// 리스트의 마지막에 도달했을 경우
                h->first=middle;	// 헤드노드가 마지막노드인 middle을 가르키게 하여 리스트의 시작을 바꾼다
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

