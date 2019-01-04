#include "stafx.h"
/*­pºâ*/

void cal()
{

    int a,b,c;
    char ch;


    scanf("%d",&a);
    while(1)
    {
        if(scanf("%d",&b)==EOF)
        {
            break;
        }
        else
        {

            printf("Choice (+ - * /):");
            scanf("%c",&ch);

            ch=getchar();
            if(ch=='+')
            {
                printf("\n");
                c=a+b;
                printf("%d\n",c);
            }
            else if(ch=='-')
            {
                printf("\n");
                c=a-b;
                printf("%d\n",c);
            }
            else if(ch=='*')
            {
                printf("\n");
                c=a*b;
                printf("%d\n",c);
            }
            else if(ch=='/')
            {
                printf("\n");
                c=a/b;
                printf("%d\n",c);
            }
            a=c;
        }

    }
}
