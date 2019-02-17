#include<stdio.h>
int main() {
  int n, burstArr[10], waitingArr[10], arrivalArr[10], tatArr[10], avgWaitingTime=0,avgTurnAroundTime=0,i,j;

  printf("Enter total no. of processes: ");
  scanf("%d", &n);

  printf("Enter process burst time and arrival time: " );
  for (i=0; i < n; i++) {
    printf("\nP[%d] - ",i);
    scanf("%d", &burstArr[i]);
    printf("\nAT[%d] - ",i);
    scanf("%d", &arrivalArr[i]);
  }
  waitingArr[0]=0;  //waiting time for first process is 0

  // waiting time
  for(i=1; i<n; i++) {
    waitingArr[i]=0;
    for(j=0;j<i;j++) {
      waitingArr[i]+= burstArr[j];
    }

  }
  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

  // turnaround time
     for(i=0;i<n;i++)
     {
         tatArr[i] = burstArr[i] + waitingArr[i]-arrivalArr[i];
         avgWaitingTime += waitingArr[i] -arrivalArr[i];
         avgTurnAroundTime += tatArr[i] ;
         printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1, burstArr[i], waitingArr[i], tatArr[i]);
     }

     avgWaitingTime/=n;
     avgTurnAroundTime/=n;
     printf("\n\nAverage Waiting Time:%d",avgWaitingTime);
     printf("\nAverage Turnaround Time:%d",avgTurnAroundTime);

     return 0;
}
