#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Constant
{
    char Letter[MAX];
    double num[MAX];
};

Constant constant;

int check_1(char N, int i)
{
    for(int n=1; n<i; n++)
    {
        if(constant.Letter[n] == N)
            return 0;
    }
}

int check_2(char N, int i)
{
    for(int n=1; n<=i; n++)
    {
        if(constant.Letter[n] == N)
            return 0;
    }
}

int search(char N, int i)
{
    for(int n=1; n<=i; n++)
    {
        if(constant.Letter[n] == N)
            return n;
    }
}

int del(char N, int i)
{
    for(int n=1; n<=i; n++)
    {
        if(constant.Letter[n] == N)
            return n;
    }
}
int main()
{
    int choose;
    int i=0;
    int n;
    char A,B;

    while(choose != 4)
    {
        printf("Choose the next move :\n"
               "1. Insert a Constant.\n"
               "2. Delete a Constant.\n"
               "3. Serch a Constant.\n"
               "4. Back.\n"
               "-->");
        scanf("%d", &choose);
        printf("\n");

        switch(choose)
        {
        case 1://加入常數
            i++;
            printf("Enter a Letter : ");
            fflush(stdin);
            scanf("%c", &constant.Letter[i]);
            if(check_1(constant.Letter[i],i) == 0)
            {
                printf("Already have this Constant");
                i = i-1;
            }
            else
            {
                printf("Enter a Constant : ");
                scanf("%lf", &constant.num[i]);
                printf("%c = %lf\n", constant.Letter[i], constant.num[i]);
            }
            printf("\n\n");
            break;
        case 2://刪除
            printf("Enter a Letter to be deleted : ");
            fflush(stdin);
            scanf("%c", &B);

            if(check_2(B,i) == 0)
            {
                constant.Letter[del(B,i)] = '\0';
                del(B,i);
                printf("%c has been deleted.\n", B);
                printf("%d\n", del(B,i));
                printf("%c\n", constant.Letter[del(B,i)]);
            }
            else
            {
                printf("Can't found this Constant.\n");
            }

            printf("\n\n");
            break;
        case 3://搜尋
            printf("Enter a Letter to be search : ");
            fflush(stdin);
            scanf("%c", &A);

            if(search(A,i) <= i)
                printf("---%lf\n",constant.num[search(A,i)]);
            else
                printf("Can't found this Constant.\n");
            printf("\n\n");
            break;
        case 4:
            break;
        default:
            printf( "Invalid choice.\n\n" );
            break;
        }
    }
}
