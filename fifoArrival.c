#include<stdio.h>
void main()
{
	int a[100][2],n,i,t,e,sum=0,sum01=0,turnAroundTime=0;
	float avg,turnAroundTimeAvg;

	printf("Enter the number of processes.");
	scanf("%d",&n);
	printf("Enter the Arrival Time and Burst Time for the processes.");	
	
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[i][0] = t;
		scanf("%d",&e);
		a[i][1] = e;
		sum += sum01 - t ;
		printf("%d\n",sum);
		sum01 = sum01 + e;
		turnAroundTime += sum01 - t; 
	}
	
	avg = sum/n;
	turnAroundTimeAvg = turnAroundTime/n;
        printf("Avg is %f",avg);
	printf("Avg is %f",turnAroundTimeAvg);
}
