#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choose;
    char *Letter;
    char *num;

    Letter = (char*) malloc(sizeof(char)*80);

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
            printf("Enter a Letter : ");
            fflush(stdin);
            scanf("%s", Letter);
            printf("Enter a Constent : ");
            scanf("%lf", &num);
            printf("%s = %lf\n", Letter, num);
            
            Letter = num;                     //有問題
            
            printf("\n\n");
            break;
        case 2:                               //還沒做
        	
        	printf("\n\n");
            break;
        }
    }
}
