#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"mech.c"

int main(){
    int ch=0;
    int m,n;
    int *seq_queue;
    float *jobs = NULL;
    do{
        system("cls");
        printf(" #############################\n ");
        printf("\n Job seqencing: ----title here ");
        printf("\n 1. 2 Machines - N jobs");
        printf("\n 2. 3 Machines - N jobs");
        printf("\n 3. M Machines - N jobs");
        printf("\n 4. Exit");
        printf("\n select a type: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t TWO MACHINES - N Jobs");
                printf("\n Enter number of jobs - ");
                scanf("%d",&n);
                m=2;
                jobs = input(m,n);
                seq_queue = sequencing(jobs,n);
                calculation(jobs, seq_queue,m,n);
                getch();
            break;
            case 2: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t THREE MACHINES - N Jobs");
                printf("\n Enter number of jobs - ");
                scanf("%d",&n);
                m=3;
                jobs = input(m,n);
                jobs = reduce(jobs,m,n);
                seq_queue = sequencing(jobs,n);
                calculation(jobs, seq_queue,m=2,n);
                printf("\n--------------\n");
                getch();
            break;
            case 3: system("cls");
                printf("\n\n--------------------\n\n");
                printf("\n\t M MACHINES - N Jobs");
                printf("\n Enter number of Machines - ");
                scanf("%d",&m);
                printf("\n Enter number of jobs - ");
                scanf("%d",&n);
                jobs = input(m,n);
                jobs = reduce(jobs,m,n);
                seq_queue = sequencing(jobs,n);
                calculation(jobs, seq_queue,m=2,n);
                printf("\n--------------\n");
                getch();
            break;
            case 4:  exit(0);
            default: system("cls");
            printf("\n Invalid input please enter a valid input: ");
            printf("\n press enter to continue...");
            getch();
        }
    }while(ch!=4);
    return 0;
}