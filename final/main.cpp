#include "stafx.h"
#include "user.h"


int main()
{

    int choice;
   instructions1();
    scanf("%d",&choice);

    while(choice!=4){

        switch(choice){
        case 1:
            cal();

            break;
        case 2:
            cal2();
            break;
        case 3:
            cal3();
            break;



        }
 instructions1();
    scanf("%d",&choice);



    }
printf("The calculator is shutting down.\n");

}
