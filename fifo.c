#include<stdio.h>
void main()
{
	int a[100],n,i,t,sum=0;
	float avg;

	printf("Enter the number of processes.");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(i != n-1){
			sum += t;
		}
		a[i] = t;
	}
	
	avg = sum/n;
        printf("Avg is %f",avg);
}
