#include "stafx.h"
#include "user.h"

int main()
{

    int choice;
    printf("1.Simple calculation:\n");
    printf("2.Custom formula:\n");
    printf("3.Custom parameters:\n");
    printf("4.Exit\n");
    printf("=> ");
    scanf("%d",&choice);

    while(choice!=4){

        switch(choice){
        case 1:
            cal();

            break;
        case 2:
            break;
        case 3:
            break;



        }
    printf("1.Simple calculation:\n");
    printf("2.Custom formula:\n");
    printf("3.Custom parameters:\n");
    printf("4.Exit\n");
    printf("=> ");
    scanf("%d",&choice);



    }


}

/*int main(void)
{
    node item;
    int choice;

    item.inputfunc = (char *)malloc(sizeof(char)*50);

    nodePtr startPtr = NULL;

    instructions();

    while(1)
    {
        printf("->");
        scanf("%d", &choice);
        if(choice==5)
            break;
        switch(choice)
        {
            case 1:
                printf("Start your arithmetic:\n");
                //funAri();
                break;
            case 2:
                printf("Enter a function:\n");
                gets(item.inputfunc);
                stoFun(&startPtr, item);
                break;
            case 3:
                break;
            case 4:
                break;
        }
        printf("\n");
    }
    printf("The calculator is shutting down.");

    return 0;
}
*/
