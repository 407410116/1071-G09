#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Constent
{
    char Letter[];
    double num[];
};

Constent constent;

int check(char N, int i)
{
    for(int n=0; n<i; n++)
    {
        if(constent.Letter[n] == N)
        {
            printf("Already have this Constent\n\n");
            return 0;
        }
    }
}

int search(char N, int i)
{
    for(int n=1; n<=i; n++)
    {
        if(constent.Letter[n] == N)
            printf("---%lf\n",constent.num[n]);
        else
            printf("Can't found this Constent.\n");
    }
}


int main()
{
    int choose;
    int i=0;

    while(choose != 4)
    {
        printf("Choose the next move :\n"
               "1. Insert a Constent.\n"
               "2. Delete a Constent.\n"
               "3. Search a Constent.\n"
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
            scanf("%c", &constent.Letter[i]);
            if(check(constent.Letter[i],i) == 0)
                break;
            else
            {
                printf("Enter a Constent : ");
                scanf("%lf", &constent.num[i]);
                printf("%c = %lf\n", constent.Letter[i], constent.num[i]);

                printf("\n\n");
            }
            break;
        case 2:

            printf("\n\n");
            break;
        case 3:
        	printf("Enter a Letter : ");
        	fflush(stdin);
            scanf("%c", &constent.Letter[i]);
            search(constent.Letter[i],i);
            
            printf("\n\n");
            break;
        }
    }
}
