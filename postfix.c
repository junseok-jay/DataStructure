/** 
 * postfix.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

// stack ������ �켱����, lparen = 0 ���� ���� */
typedef enum{
	lparen = 0,  // ( ���� ��ȣ */
	rparen = 9,  // ) ������ ��ȣ*/
	times = 7,   // * ���� */
	divide = 6,  // / ������ */
	plus = 5,    // + ���� */
	minus = 4,   // - ���� */
	operand = 1 // �ǿ����� */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	// infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE];	// postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	// postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		// ����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  // postfixStack�� top */
int evalStackTop = -1;	   // evalStack�� top */

int evalResult = 0;	   // ��� ����� ���� */

void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;

	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');
    printf("[----- [���ؼ�] [2021041051] -----]\n");
	return 1;
}

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return '\0';
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}

/**
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * �����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.
 */
void toPostfix()
{
	// infixExp�� ���� �ϳ����� �б����� ������ 
	char *exp = infixExp;
	char x; // �����ϳ��� �ӽ÷� �����ϱ� ���� ���� 
    
    while (*exp != '\0')    // exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� 
        {
            // ���� ���ڰ� �ǿ������� ���
            if (getToken(*exp) == operand)
            {
                charCat(exp); // �ǿ����ڸ� postfixExp�� �߰�
            }
            else if (getToken(*exp) == lparen)  // ���� ���ڰ� '('�� ���
            {
                postfixPush(*exp); // '('�� postfix ���ÿ� push
            }
            else if (getToken(*exp) == rparen)  // ���� ���ڰ� ')'�� ���
            {
                while (getToken(postfixStack[postfixStackTop]) != lparen)
                {   // '('�� ���� ������ postfix ���ÿ��� pop�ϰ� postfixExp�� �߰�
                    charCat(&postfixStack[postfixStackTop]);
                    postfixPop();
                }
                postfixPop(); // '('�� ���ÿ��� ����
            }
            else    
            {
                while (getPriority(postfixStack[postfixStackTop]) >= getPriority(*exp))
                {   // ������ top�� �ִ� �������� �켱������ ���ų� ������ pop�ϰ� postfixExp�� �߰�
                    charCat(&postfixStack[postfixStackTop]);
                    postfixPop();
                }
                postfixPush(*exp); // ���� �����ڸ� postfix ���ÿ� push
            }
            exp++; // ���� ���ڷ� �̵�
        }
    while (postfixStackTop != -1)   // ���ÿ� �����ִ� �����ڵ��� ��� pop�Ͽ� postfixExp�� �߰�
    {
        charCat(&postfixStack[postfixStackTop]);
        postfixPop();
    }

}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
    char *exp = postfixExp; // postfixExp�� �б����� ������

    while(*exp != '\0'){
        if(getToken(*exp) == operand){  // �ǿ������� ��� �ٷ� push
            evalPush(*exp - '0');
        }
        else{   // �������� ��� pop�Ͽ� ���� �� �ٽ� push
            int op1=evalPop();
            int op2=evalPop();
            switch(getToken(*exp)){
                case plus:
                    evalPush(op1+op2);
                    break;
                case minus:
                    evalPush(op1-op2);
                    break;
                case times:
                    evalPush(op1*op2);
                    break;
                case divide:
                    evalPush(op1/op2);
                    break;
            }
        }
        exp++;  // ���� ���ڷ� �̵�
    }
    evalResult=evalPop();   //  ���������� ���� ���� ��� ���
}