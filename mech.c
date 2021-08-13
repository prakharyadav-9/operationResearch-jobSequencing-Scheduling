#include"mech.h"
#define NA 9999
float *input(int m, int n){   
    float *jobs = (float *) calloc(m*n,sizeof(float));          // using dynamic memory allocation for better space utilization
    if(!jobs)
        return NULL;                                            // handling error case
    for(int i=0;i<m ; i++){
        printf("\n Enter P%d values: ",i+1);
        for(int j=0;j<n;j++)
            scanf("%f",&(*(jobs + n*i +j)));                    // taking values as input
    }
    return jobs;
}  // end of input function

float *reduce(float *jobs, int m , int n){
    float *temp = (float *) calloc(2*n, sizeof(float));      // getting space for 2xN reduced machine
    float sum=0;
    for(int k = 0;k<2;k++){
        for(int j=0; j<n;j++){
            sum = 0;
            for(int i=0+k;i<m + k -1;i++){
                sum += *(jobs + j + i*n);                   // summing elements to reducing technique
            }
            *(temp + k*n + j) = sum;
        }
    }    
    free(jobs);                                             // freeing previoius heap area
    return temp;                                            //  returning new matrix
}

void printinp( float * values, int r,int c){            
    printf("\n");                                     // private function to see the 
    for(int i= 0 ; i<r; i++){                         // current matrix passed on it
        for(int j=0;j<c;j++)
            printf(" %f ",*(values + i*c + j));
        printf("\n");
    }
}

int *sequencing(float *jobs, int n){
    int min_pos=NA;
    int min_val=NA;
    float temp[2][n];
    int *seq_queue = (int *)calloc(n, sizeof(int));     // double sided queue for sequencing purpose
    int front = 0, rear=n-1;
    int flag=0;
    //take a copy
    for(int i=0;i<2;i++)    
        for(int j=0;j<n;j++)
            temp[i][j] = *(jobs + i*n +j);

    for(int k=0; k<n;k++){
        min_pos = NA;
        min_val = NA;
        flag = 0;
        for(int i=0;i<n;i++){
            if(min_val>temp[0][i]){                          // taking out minimum in 1st row
                min_pos = i;
                min_val = temp[0][i];
            }
        }
        for(int i=0;i<n;i++){
            if(min_val>temp[1][i]){                         // taking out minimum in 2nd row
                min_pos = i;
                min_val = temp[1][i];
                flag = 1;                                   // flag to rear side input 
            }
        }
        // now inserting into queue
        if(flag){
            seq_queue[rear--]=min_pos+1;                   // rear input in special case of 2nd row value being minimum
        }
        else{
            seq_queue[front++]=min_pos+1;                  // usual scenario for front input
        }
        temp[0][min_pos]=NA;                            
        temp[1][min_pos]=NA;                                // eliminating that column when done
    }
    // show final sequence
    printf("\n choosen index sequence:\n");
    for(int i=0; i<n;i++)
        printf("%d \t",*(seq_queue+i));

    return seq_queue;                                       // returning sequence queue as pointer
}

void calculation(float *jobs,int * seq_queue, int m, int n){
    float temp[m][n];
    int t1out=0,t2in=0,t2out=0;
    int m2_idel=0;
    //take a copy & work upon
    for(int i=0;i<m;i++)    
        for(int j=0;j<n;j++)
            temp[i][j] = *(jobs + i* n + j);    

    for(int j=0;j<n;j++){
        t1out += temp[0][seq_queue[j]-1];
        t2in = t1out>t2out?t1out:t2out;
        m2_idel +=(t2in - t2out);
        t2out = t2in + temp[1][seq_queue[j]-1];
    }

    printf("\n ----------------- \n");
    printf(" value of p1_ideal = %d \n", t2out-t1out);
    printf(" value of p2_idel = %d \n", m2_idel);
    printf(" total running time = %d", t2out);
    printf("\n");
    // printinp(jobs,m,n);
    // printinp(temp,m,n);
}
