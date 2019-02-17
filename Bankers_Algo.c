#include<stdio.h>
#define true 1
#define false 0
int m,n,i,j,count=0,process;
int max[10][10],alloc[10][10],need[10][10],c[10],avail[10],finish[10];
int seq[5], x = 0;

void readtable(int t[10][10]) {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&t[i][j]);
}

void printtable(int t[10][10]) {
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("\t%d",t[i][j]);
        printf("\n");
    }
}

void readvector(int v[10]) {
    for(j=0;j<n;j++)
        scanf("%d",&v[j]);
}

void printvector(int v[10]) {
    for(j=0;j<n;j++)
        printf("\t%d",v[j]);
}

void init() {
    printf("enter the number of process\n");
    scanf("%d",&m);
    printf("enter the number of resources\n");
    scanf("%d",&n);
    printf("enter the max table\n");
    readtable(max);
    printf("enter the allocation table\n");
    readtable(alloc);
    printf("enter the max units of each resource\n");
    readvector(c);
    for(i=0;i<n;i++)
        finish[i]=false;
}

void findavail() {
    int sum;
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<m;i++)
        {
            sum=sum+alloc[i][j];
        }
        avail[j]=c[j]-sum;
    }
}

void findneed() {
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }

    }
}

void selectprocess()
{
    int flag;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(need[i][j]<=avail[j])
                flag=1;
            else
            {
                flag=0;
                break;
            }
        }
        if((flag==1)&&(finish[i]==false))
        {
            process=i;
            count++;
            break;
        }
    }
    printf("current status is\n");
    printtable(alloc);
    if(flag==0)
    {
        printf("system is in unsafe state\n");
        exit(1);
    }
    printf("system is in safe state\n");
}
void executeprocess(int p)
{
    printf("\nexecuting process is %d\n",p);
    seq[x] = p;
    x++;
    printtable(alloc);
}
void releaseresource()
{
    for(j=0;j<n;j++)
        avail[j]=avail[j]+alloc[process][j];
    for(j=0;j<n;j++)
    {
        alloc[process][j]=0;
        need[process][j]=0;
    }
}

main()
{
    init();
    findavail();
    findneed();
    do
    {
        selectprocess();
        finish[process]=true;
        executeprocess(process);
        releaseresource();
    }while(count<m);
    printf("\nall processes executed correctly\n");
    printf("the safe sequence is:\n");
    for (int i = 0; i < 4; i++) {
      printf("%d\t", seq[i]);
    }

}
