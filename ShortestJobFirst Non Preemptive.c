#include<stdio.h>

int main() {
    int burstArr[20],p[20],waitingArr[20],tatArr[20],i,j,n,total=0,pos,temp;
    float avgWaitingTime = 0.0,avgTurnAroundTime = 0.0;
    printf("Enter number of processes:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++) {
        printf("p[%d]:",i+1);
        scanf("%d", &burstArr[i]);
        p[i]=i+1;
    }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++) {
        pos=i;
        for(j=i+1;j<n;j++) {
            if(burstArr[j]<burstArr[pos])
                pos=j;
        }

        temp=burstArr[i];
        burstArr[i]=burstArr[pos];
        burstArr[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    waitingArr[0] = 0;  //waiting time for first process is zero

    // waiting time
    for(i=1;i<n;i++) {
        waitingArr[i]=0;
        for(j=0;j<i;j++) {
          waitingArr[i]+=burstArr[j];
        }
        total+=waitingArr[i];
    }

    avgWaitingTime=total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    // turnaround time
    for(i=0;i<n;i++) {
        tatArr[i] = burstArr[i] + waitingArr[i];
        total += tatArr[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", p[i], burstArr[i], waitingArr[i], tatArr[i]);
    }

    avgTurnAroundTime=total/n;
    printf("\n\nAverage Waiting Time=%f", avgWaitingTime);
    printf("\nAverage Turnaround Time=%f\n", avgTurnAroundTime);

    return 0;
}
