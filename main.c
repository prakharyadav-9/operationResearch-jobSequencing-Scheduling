#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"mech.c"  // including the file containing all the explicit definition of functions used

int main(){
    int ch=0;
    int m,n;
    int *seq_queue;
    float *jobs = NULL;
    float *jred =NULL;
    do{
        system("cls");
        printf(" #############################\n ");     // showing a menu driven
        printf("\n Job seqencing: ----title here ");     // for avalilable options
        printf("\n 1. 2 Machines - N jobs");
        printf("\n 2. 3 Machines - N jobs");
        printf("\n 3. M Machines - N jobs");
        printf("\n 4. Exit");
        printf("\n 0. Test");
        printf("\n select a type: ");
        scanf("%d",&ch);                                 //  taking the choice of user
        switch(ch){
            case 0: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t M MACHINES - N Jobs");
                printf("\n Enter number of Machines - ");
                scanf("%d",&m);                                 //  this case 0 is totally for experiment cases
                printf("\n Enter number of jobs - ");           //  rest all other cases work fine you may comment this 
                scanf("%d",&n);                                 //  case if you wants
                jobs = input(m,n);
                printinp(jobs,m,n);


            printf("\n--------------\n");
            printf("Press enter to continue...");
            getch();
            break;
            case 1: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t TWO Process - N Food Items");
                printf("\n Enter number of Food Items - ");
                scanf("%d",&n);
                m=2;
                jobs = input(m,n);                      // input() function takes the input as choosen by user
                seq_queue = sequencing(jobs,n);         // sequencing() perfoms operationResearch Sequencing
                calculation(jobs, seq_queue,m,n);       // calculaion() perfomed over the sequence generated
                printf("\n--------------\n");
                printf("Press enter to continue...");
                getch();
            break;
            case 2: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t THREE Process - N Food Items");
                printf("\n Enter number of Food Items - ");
                scanf("%d",&n);
                m=3;
                jobs = input(m,n);
                jred = reduce(jobs,m,n);                // reduces the M machines to G and H
                seq_queue = sequencing(jred,n);
                calculation(jobs, seq_queue,m,n);
                printf("\n--------------\n");
                printf("Press enter to continue...");
                getch();
            break;
            case 3: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t M Process - N Food Items");
                printf("\n Enter number of Process - ");
                scanf("%d",&m);
                printf("\n Enter number of Food Items - ");
                scanf("%d",&n);
                jobs = input(m,n);
                //jred = reduce(jobs,m,n);
                seq_queue = sequencing(jobs,n);
                calculation(jobs, seq_queue,m,n);
                printf("\n--------------\n");
                printf("Press enter to continue...");
                getch();
            break;
            case 4:  exit(0);                       // safely exit on choosing this option
            default: system("cls");                 
            printf("\n Invalid input please enter a valid input: ");
            printf("\n press enter to continue...");    // handling default case
            getch();
        }
    }while(ch!=4);                                  // looping untill not exit specified
    return 0;
}
