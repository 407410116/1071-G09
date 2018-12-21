#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Constant
{
    char Letter[];
    double num[];
};

Constant constant;

int check(char N, int i)
{
    for(int n=0; n<i; n++)
    {
        if(constant.Letter[n] == N)
        {
            printf("Already have this Constant\n\n");
            return 0;
        }
    }
}

int search(char N, int i)           //有問題
{
    for(int n=0; n<i; n++)
    {
        if(constant.Letter[n] == N)
            printf("---%lf\n",constant.num[n]);
        else
            printf("Can't found this Constant.\n");
    }
}

int main()
{
    int choose;
    int i=0;

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
        case 1:
            i++;
            printf("Enter a Letter : ");
            fflush(stdin);
            scanf("%c", &constant.Letter[i]);
            if(check(constant.Letter[i],i) == 0)
                break;
            else
            {
                printf("Enter a Constant : ");
                scanf("%lf", &constant.num[i]);
                printf("%c = %lf\n", constant.Letter[i], constant.num[i]);

                printf("\n\n");
            }
            break;
        case 2:                  //還沒做

            printf("\n\n");
            break;
        case 3:
        	printf("Enter a Letter : ");
        	fflush(stdin);
            scanf("%c", &constant.Letter[i]);
            search(constant.Letter[i],i);
            
            printf("\n\n");
            break;
        }
    }
}
