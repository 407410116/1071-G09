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
	int order=1;
	Element data;
	//float value[Max];
	struct ListNode *next;
}node;

typedef struct ListNode *nodePtr;

void put(nodePtr newnode, int i)
{
	if(top >= Max-1)
		printf("The stack is full.\n");
	else
		newnode->data.stack[++top]=newnode->data.infix[i];
}

void putf(nodePtr newnode, float arithmetic)
{
	if(top >= Max-1)
		printf("The stack is full.\n");
	else
		newnode->data.stackf[++top]=arithmetic;
}

char take(nodePtr newnode)
{
	if(top==-1)
		printf("The stack is empty or your form is wrong.\n");
	else
		return newnode->data.stack[top--];
}

float takef(nodePtr newnode)
{
	if(top==-1)
		printf("The stack is empty or your form is wrong.\n");
	else
		return newnode->data.stackf[top--];
}

int priority(char Operator)
{
	if(Operator=='^')
		return 4;
	if(Operator=='!' || Operator=='c' || Operator=='p')
		return 3;
	if(Operator=='*' || Operator=='/')
		return 2;
	if(Operator=='+' || Operator=='-')
		return 1;
	if(Operator=='(')
		return 0;
}

void infix_to_postfix(nodePtr newnode)
{
	int i=0, j=0;
	while(newnode->data.infix[i]!='\0')
	{
		switch(newnode->data.infix[i])
		{
			case '(':
				put(newnode, i);
				break;
			case ')':
				while(newnode->data.stack[top]!='(')
					newnode->data.postfix[j++]=take(newnode);
				take(newnode);
				break;
			case '-':
	        case '+':
	        case '%':
	        case '/':
	        case '*':
	        case '^':
	        case '!':
	        case 'c':
	        case 'p':
	        	while(top!=-1 && (priority(newnode->data.stack[top]) >= priority(newnode->data.infix[i])))
	        		newnode->data.postfix[j++]=take(newnode);
	        	put(newnode, i);
	        	break;
	        default :
	        	newnode->data.postfix[j++]=newnode->data.infix[i];
		}
		i++;
	}
	while(top!=-1){
		newnode->data.postfix[j++]=take(newnode);
	}
}

float value(nodePtr newnode)
{
	float a, b, combination, permutation;
	for(unsigned int i=0; i<strlen(newnode->data.postfix); i++)
	{
		float x=1, y=1;
		if(newnode->data.postfix[i]=='+')
			putf(newnode, takef(newnode)+takef(newnode));
		if(newnode->data.postfix[i]=='*')
			putf(newnode, takef(newnode)*takef(newnode));
		if(newnode->data.postfix[i]=='-')
		{
			a=takef(newnode);
			b=takef(newnode);
			putf(newnode, b-a);
		}
		if(newnode->data.postfix[i]=='/')
		{
			a=takef(newnode);
			b=takef(newnode);
			putf(newnode, b/a);
		}
		if(newnode->data.postfix[i]=='%')
		{
			a=takef(newnode);
			b=takef(newnode);
			putf(newnode, (int)b%(int)a);
		}
		if(newnode->data.postfix[i]=='^')
		{
			a=takef(newnode);
			b=takef(newnode);
			putf(newnode, pow(b, a));
		}
		if(newnode->data.postfix[i]=='!')
		{
			a=takef(newnode);
			b=takef(newnode);
			for(float j=a; j<=b; j++)
				x=x*j;
			putf(newnode, x);
		}
		if(newnode->data.postfix[i]=='c')
		{
			a=takef(newnode);
			b=takef(newnode);
			for(float j=a+1; j<=b; j++)
				x=x*j;
			for(float j=b-a; j>0; j--)
				y=y*j;
			combination=x/y;
			putf(newnode, combination);
		}
		if(newnode->data.postfix[i]=='p')
		{
			a=takef(newnode);
			b=takef(newnode);
			for(float j=1; j<=b; j++)
				x=x*j;
			for(float j=b-a; j>0; j--)
				y=y*j;
			permutation=x/y;
			putf(newnode, permutation);
		}
		if(newnode->data.postfix[i]>=48 && newnode->data.postfix[i]<=57)
		{
			int temp=0, put_number=0;
			char token;
			token=newnode->data.postfix[i];
			for(int j=newnode->data.count[temp]-1; j>=0; j--)
			{
				token=newnode->data.postfix[i++];
				put_number=put_number+(token-48)*pow(10,j);
			}
			putf(newnode, put_number);
			i--;
			temp++;
		}
	}
	/*node item;
	int i=0
	item.value[i]=takef(newnode);
	i++;*/
	printf("-------------------------------------------------\n");
	printf("%s = %f\n", newnode->data.infix, takef(newnode));
	printf("-------------------------------------------------\n");
	return takef(newnode);
}

void separate(nodePtr newnode)
{
	int amount=0, x=0;
	for(unsigned int i=0; i<=strlen(newnode->data.infix); i++)
	{
		if(newnode->data.infix[i]>=48 && newnode->data.infix[i]<=57)
			x++;
		else
		{
			if(x>0)
				newnode->data.count[amount++]=x;
			x=0;
		}
	}
	amount--;
}

void algebra(nodePtr newnode)
{
	char algebra[6]={'a', 'b', 'c', 'x', 'y', 'z'};
	char variable[6];
	int count=0;
	for(unsigned int i=0; i<strlen(newnode->data.infix); i++)
	{
		for(int j=0; j<6; j++)
		{
			if(newnode->data.infix[i]==algebra[j])
			{
				printf("%c = ",newnode->data.infix[i]);
				scanf("%c", &variable[count]);
				newnode->data.infix[i]=variable[count];
				count++;
			}
		}
	}
}

void polynomial(nodePtr *start, node item)
{
	nodePtr newnode;
	nodePtr previous;
	nodePtr current;

	newnode = (node *)malloc(sizeof(node));

	newnode->order = item.order;
    
	gets(newnode->data.infix);
	algebra(newnode);
	separate(newnode);
	infix_to_postfix(newnode);
	value(newnode);

	newnode->next=NULL;

	if(start == NULL)
	{
		*start = newnode;
	}
	else
	{
		current = *start;
		previous = NULL;

		while(current != NULL)
		{
			if(newnode->order <= current->order)
				break;
			else
			{
				previous = current;
				current = current->next;
			}
		}
		if(previous == NULL && current != NULL)
		{
			newnode->next = current;
			*start = newnode;
		}
		else if(previous != NULL && current != NULL)
		{
            previous->next = newnode;
			newnode->next = current;
		}
		else
		{
			previous->next = newnode;
		}
	}

}
/*
int deleteValue(nodePtr *start, node item)
{
    nodePtr previous;
    nodePtr current;
    nodePtr temp;

    if(item.order == (*start)->order)
    {
        temp = current;
        *start = (*start)->next;
        free(temp);
        return item.order;
    }
    else
    {
        previous = *start;
        current = (*start)->next;

        while(current != NULL  &&  current->order != item.order)
        {
            previous = current;
            current = current->next;
        }

        if(current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return item.order;
        }
    }
    return 0;
}*/

void printValue(nodePtr current)
{
	int i=1;
    if(current == NULL)
        printf( "There is no value.\n" );
    else
    {
        printf( "All value:\n" );
        while(current != NULL)
        {
           printf("%d. %lf ", current->order, value(current));
           current = current->next;
           i++;
        }
        printf( "......\n" );
    }
}

int detEmpty(nodePtr start)
{
    return start == NULL;
}

void instructions(void)
{
	printf("Enter instruction:\n"
		   "  1. Simple arithmetic. (Only + - * /)\n"
		   "  2. Calculate polynomial and store its value.\n"
		   "  3. Delete a value.\n"
		   "  4. Show all value.\n"
		   "  5. Store a algebra.\n"
		   "  6. Delete a algebra.\n"
		   "  7. Turn off calculator.\n"
		   "--> ");
}

int main(void)
{
	nodePtr start=NULL;
	node item;
	int choice;

	instructions();
	scanf("%d", &choice);
	fflush(stdin);
	while(choice!=7)
	{
		switch(choice)
		{
			case 1:
				break;
			case 2:
				printf("Start arithmetic:\n");
				polynomial(&start, item);
				//item.order++;
				break;/*
			case 3:
				if(!detEmpty(start))
                {
                    printf("Enter order to be deleted: ");
                    scanf("%d", &item.order);

                    if(deleteValue(&start, item))
                    {
                        printf("Value NO.%d was deleted.\n", item.order);
                        printValue(start);
                    }
                    else
                        printf("Value NO.%d not found.\n\n", item.order);
                }
                else
                    printf("There is no value.\n\n");
				break;*/
			case 4:
			    printValue(start);
				break;
			case 5:
				break;
			case 6:
				break;
		}
		printf("Next instruction: \n"
			   "--> ");
		scanf("%d", &choice);
		fflush(stdin);
		if(choice==7)
			break;
	}
	printf("The calculator is shutting down.");
	return 0;
}
