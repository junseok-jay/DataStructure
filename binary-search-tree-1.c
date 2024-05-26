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
	printf("[----- [���ؼ�] [2021041051] -----]\n");
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



void inorderTraversal(Node* ptr)	// 	����Լ��� �̿��� ������ȸ
{
	if(ptr!=NULL){
		inorderTraversal(ptr->left);	// ���� �ڽ� ����� �θ� ����� ������ �ڽ� ����ϴ� ����
		printf(" [%d] ",ptr->key);	
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)	//	����Լ��� �̿��� ������ȸ
{
	if(ptr!=NULL){
		printf(" [%d] ",ptr->key);	// �θ� ����� ���� �ڽ� ����� ������ �ڽ� ����ϴ� ����
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)	//	����Լ��� �̿��� ������ȸ
{
	if(ptr!=NULL){
		postorderTraversal(ptr->left); // ���� �ڽ� ����� ������ �ڽ� ����� �θ� ����ϴ� ����
		postorderTraversal(ptr->right);
		printf(" [%d] ",ptr->key);
	}
}


int insert(Node* head, int key)	
{
	Node* ptr=(Node*)malloc(sizeof(Node));	// �� ��� �����Ҵ�
	ptr->key=key;	// �� ���key�� �Է¹��� key�� ����
    ptr->left=NULL;	// ��� �ʱ�ȭ
    ptr->right=NULL;

	if(head->left==NULL){	// ��Ʈ��尡 ������
		head->left=ptr;
		return 0;
	}

	head=head->left;	// ��Ʈ��尡 ������
	// ���� ������ head�� ���������� �̵��ϱ� ���� �����ͷ� ���
	
	while(1){	// Ű���� ���Ͽ� ũ�� ������ �ڽ� ������ ���� �ڽ����� �̵�
		if(key>head->key){	//	Ű���� �� ũ�� ������ �ڽ����� �̵�
			if(head->right==NULL){	// ���������� ���������� �� ��带 ����
				head->right=ptr;
				break;
			}
			head=head->right;
		}
		else{	// Ű���� �� ������ ���� �ڽ����� �̵�
			if(head->left==NULL){	// ���������� ���������� �� ��带 ����
				head->left=ptr;
				break;
			}
			head=head->left;
		}
	}
	return 0;
}

int deleteLeafNode(Node* head, int key)	// Ű ���� ���� ������带 ����
{
    Node* p=head->left;	// ��Ʈ�� ����Ű�� ������
    Node* parent=head;	// �θ� ����Ű�� ������

    while(p!=NULL && p->key!=key){	// Ű���� ���� ��带 ã�ų� ������� ���� �����Ҷ� ���� �ݺ�
        parent=p;
        if(key>p->key) p=p->right;
        else p=p->left;
    }

	if(p==NULL){	// Ű���� ���� ��尡 ������
		printf("tree do not have this key\n");
		return 0;
	}
    if(p->left==NULL && p->right==NULL){	// ��������϶�
        if(parent->left==p) {	// �����ؾ��ϴ� ��尡 �θ��� ���� �ڽ��϶�
            free(p);
            parent->left=NULL;
        }
        else {	// �����ؾ��ϴ� ��尡 �θ��� ������ �ڽ��϶�
            free(p);
            parent->right=NULL;
        }
    }
    else{	// ������尡 �ƴҶ�
        printf("Node [%d] is not a leaf node\n",key);
        return 0;
    }
    return 0;
}

Node* searchRecursive(Node* ptr, int key)	// ����Լ��� �̿��� Ž��
{
    if(ptr==NULL) return NULL;	// Ű���� ���� ��尡 ������ NULL ��ȯ
    if(ptr->key==key) return ptr;	// Ű���� ���� ��带 ã������ �ش� ��� ��ȯ
    if(key<ptr->key) return searchRecursive(ptr->left,key);
    else return searchRecursive(ptr->right,key);
}

Node* searchIterative(Node* head, int key)	// ����Լ��� �̿����� �ʰ� �ݺ����� Ž��
{
    Node*p=head->left;
    while(p!=NULL){	// Ű���� ���� ��带 ã�ų� ������� ���� �����Ҷ� ���� �ݺ�
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


int freeBST(Node* head)	// �����Ҵ�� ������ ����
{
	if(head != NULL){
		freeBST(head->left);
		if(head->right!=head) freeBST(head->right);
		// ����带 ���� ������ �ʰ� ��带 ��Ȱ���Ͽ� ������ ��Ʈ��带 ����Ű�� �������� �ڽ��� ����Ű�� �Ͽ� ���ʸ� ����ϰ� ����
		// ���� ��Ʈ����� ��� �������� �������� �ʵ��� ���ǹ��� �߰���
		free(head);
	}
	return 0;
}