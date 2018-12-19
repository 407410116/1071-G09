#include "stafx.h"
/*計算*/

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

            ch=getche();
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


/*void instructions(void)
{
    printf("Menu:\n"
           "  1. Fundamental arithmetic.\n"
           "  2. Store a polynomial.  (There are six variable you can use: a, b, c, x, y, z.)\n"
           "  3. Store a algebra.\n"
           "  4. Call a stored function and calculate it.\n"
           "  5. Turn off the calculator.\n\n"
           "Enter your choice: ");
}*/
