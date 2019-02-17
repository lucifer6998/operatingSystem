#include "stdio.h"

int main()
{
    int burstArr[20],p[20],waitingArr[20],tatArr[20],priority[20],i,j,n,total=0,pos,temp;
    float avgWaitingTime = 0.0, avgTurnAroundTime = 0.0;
    printf("Enter number of processes:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&burstArr[i]);
        printf("Priority:");
        scanf("%d",&priority[i]);
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=burstArr[i];
        burstArr[i]=burstArr[pos];
        burstArr[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    waitingArr[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waitingArr[i]=0;
        for(j=0;j<i;j++)
            waitingArr[i]+=burstArr[j];

        total+=waitingArr[i];
    }

    avgWaitingTime = total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tatArr[i]=burstArr[i]+waitingArr[i];     //calculate turnaround time
        total+=tatArr[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],burstArr[i],waitingArr[i],tatArr[i]);
    }

    avgTurnAroundTime=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avgWaitingTime);
    printf("\nAverage Turnaround Time=%d\n",avgTurnAroundTime);

    return 0;
}
