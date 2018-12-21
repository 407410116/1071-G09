#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Constent
    {
    char *Letter[];
    double num[];
    };

int check(char *N, int i)
    {
    for(int n=0;n<i;n++)
        {
        if(strcamp(constent.Letter[n],N) == 0)
            {
            printf("Already have this Constent");
            break;
            }
        }
    }

int main()
{
    int choose;
    int i=0;
    Constent constent;

    Letter[] = (char*) malloc(sizeof(char)*20);

    while(choose != 3)
    {
        printf("Choose the next move :\n"
               "1. Insert a Constent.\n"
               "2. Delete a Constent.\n"
               "3. Back.\n"
               "-->");
        scanf("%d", &choose);
        printf("\n");

        switch(choose)
        {
        case 1:
                i++;
            printf("Enter a Letter : ");
            fflush(stdin);
            scanf("%s", &constent.Letter[i]);
                check(constent.Letter[i],i);
            printf("Enter a Constent : ");
            scanf("%lf", &constent.num[i]);
            printf("%s = %lf\n", constent.Letter[i], constent.num[i]);
            
            printf("\n\n");
            break;
        case 2:                               //還沒做
        	
        	printf("\n\n");
            break;
        }
    }
}
