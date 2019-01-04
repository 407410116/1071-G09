#include "calculator.h"

int main(void)
{
    int order=1;
    int choice;
    nodePtr start=NULL;
    instructions();
    scanf("%d", &choice);
    fflush(stdin);
    while(choice!=4)
    {
        switch(choice)
        {
            case 1:
                printf("Start arithmetic:\n");
                polynomial(&start, order);
                order++;
                break;
            case 2:
                printValue(start);
                break;
            case 3:
                printf("Enter the order of value to delete: ");
                scanf("%d", &order);
                deleteValue(&start, order);
                printValue(start);

                break;
        }
        printf("Next instruction: \n"
               "--> ");
        scanf("%d", &choice);
        fflush(stdin);
        if(choice==7)
            break;
    }
    printf("The calculator is shutting down.\n");
}
