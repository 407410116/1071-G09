#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Max 10000

int top=-1;


struct Element
{
	char stack[Max];
	float stackf[Max];
	char infix[Max];
	char postfix[Max];
	int count[Max];
};

typedef struct ListNode
{
	int order;
	Element data;
	struct ListNode *next;
}node;

typedef struct ListNode *nodePtr;


void put(nodePtr newnode, int i);
void putf(nodePtr newnode, float arithmetic);
char take(nodePtr newnode);
float takef(nodePtr newnode);
int priority(char Operator);
void infix_to_postfix(nodePtr newnode);
float value(nodePtr newnode);
void algebra(nodePtr newnode);
int isEmpty(nodePtr start);
void polynomial(nodePtr *start, int order);
void deleteValue(nodePtr *start, int order);
void printValue(nodePtr current);
void instructions(void);

