/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
	printf("[----- [전준석] [2021041051] -----]\n");
	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)	// 	재귀함수를 이용한 중위순회
{
	if(ptr!=NULL){
		inorderTraversal(ptr->left);	// 왼쪽 자식 출력후 부모 출력후 오른쪽 자식 출력하는 구조
		printf(" [%d] ",ptr->key);	
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)	//	재귀함수를 이용한 전위순회
{
	if(ptr!=NULL){
		printf(" [%d] ",ptr->key);	// 부모 출력후 왼쪽 자식 출력후 오른쪽 자식 출력하는 구조
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)	//	재귀함수를 이용한 후위순회
{
	if(ptr!=NULL){
		postorderTraversal(ptr->left); // 왼쪽 자식 출력후 오른쪽 자식 출력후 부모 출력하는 구조
		postorderTraversal(ptr->right);
		printf(" [%d] ",ptr->key);
	}
}


int insert(Node* head, int key)	
{
	Node* ptr=(Node*)malloc(sizeof(Node));	// 새 노드 동적할당
	ptr->key=key;	// 새 노드key를 입력받은 key로 설정
    ptr->left=NULL;	// 노드 초기화
    ptr->right=NULL;

	if(head->left==NULL){	// 루트노드가 없을때
		head->left=ptr;
		return 0;
	}

	head=head->left;	// 루트노드가 있을때
	// 받은 포인터 head를 리프노드까지 이동하기 위한 포인터로 사용
	
	while(1){	// 키값을 비교하여 크면 오른쪽 자식 작으면 왼쪽 자식으로 이동
		if(key>head->key){	//	키값이 더 크면 오른쪽 자식으로 이동
			if(head->right==NULL){	// 리프노드까지 도달했을떄 새 노드를 연결
				head->right=ptr;
				break;
			}
			head=head->right;
		}
		else{	// 키값이 더 작으면 왼쪽 자식으로 이동
			if(head->left==NULL){	// 리프노드까지 도달했을떄 새 노드를 연결
				head->left=ptr;
				break;
			}
			head=head->left;
		}
	}
	return 0;
}

int deleteLeafNode(Node* head, int key)	// 키 값이 같은 리프노드를 삭제
{
    Node* p=head->left;	// 루트를 가리키는 포인터
    Node* parent=head;	// 부모를 가리키는 포인터

    while(p!=NULL && p->key!=key){	// 키값이 같은 노드를 찾거나 리프노드 까지 도달할때 까지 반복
        parent=p;
        if(key>p->key) p=p->right;
        else p=p->left;
    }

	if(p==NULL){	// 키값이 같은 노드가 없을때
		printf("tree do not have this key\n");
		return 0;
	}
    if(p->left==NULL && p->right==NULL){	// 리프노드일때
        if(parent->left==p) {	// 삭제해야하는 노드가 부모의 왼쪽 자식일때
            free(p);
            parent->left=NULL;
        }
        else {	// 삭제해야하는 노드가 부모의 오른쪽 자식일때
            free(p);
            parent->right=NULL;
        }
    }
    else{	// 리프노드가 아닐때
        printf("Node [%d] is not a leaf node\n",key);
        return 0;
    }
    return 0;
}

Node* searchRecursive(Node* ptr, int key)	// 재귀함수를 이용한 탐색
{
    if(ptr==NULL) return NULL;	// 키값이 같은 노드가 없을때 NULL 반환
    if(ptr->key==key) return ptr;	// 키값이 같은 노드를 찾았을때 해당 노드 반환
    if(key<ptr->key) return searchRecursive(ptr->left,key);
    else return searchRecursive(ptr->right,key);
}

Node* searchIterative(Node* head, int key)	// 재귀함수를 이용하지 않고 반복적인 탐색
{
    Node*p=head->left;
    while(p!=NULL){	// 키값이 같은 노드를 찾거나 리프노드 까지 도달할때 까지 반복
        if(key==p->key){
            return p;
        }
        else if(key>p->key){
            p=p->right;
        }
        else{
            p=p->left;
        }
    }
    return p;
}


int freeBST(Node* head)	// 동적할당된 노드들을 해제
{
	if(head != NULL){
		freeBST(head->left);
		if(head->right!=head) freeBST(head->right);
		// 헤드노드를 따로 만들지 않고 노드를 재활용하여 왼쪽을 루트노드를 가르키고 오른쪽을 자신을 가르키게 하여 왼쪽만 사용하게 만듬
		// 따라서 루트노드의 경우 오른쪽을 해제하지 않도록 조건문을 추가함
		free(head);
	}
	return 0;
}