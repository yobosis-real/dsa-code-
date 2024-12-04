#include <stdio.h>
#include <stdlib.h>

//struct to represent a job
typedef struct Job 
{
    int id;//job id 
    int deadline;//job deadline
    int profit;//job profit
}Job;

//function to find the max deadline 
int findmaxdeadline(Job jobs[],int n)
{
        int maxdeadline=0;
        for(int i=0;i<n;i++)
        {
            if(jobs[i].deadline>maxdeadline)
                maxdeadline=jobs[i].deadline;
        }
    return maxdeadline;
}

void sortjobs(Job jobs[],int n)
{
    int i,j,t1,t2,t3;
    for(i=1;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(jobs[j].profit>jobs[j-1].profit)
            {
                t3=jobs[j].id;
                t1=jobs[j].profit;
                t2=jobs[j].deadline;
                jobs[j].deadline=jobs[j-1].deadline;
                jobs[j].profit=jobs[j-1].profit;
                jobs[j].id=jobs[j-1].id;
                jobs[j-1].profit=t1;
                jobs[j-1].deadline=t2;
                jobs[j-1].id=t2;
            }
        }
    }
}

void jobscheduling(Job jobs[],int n)
{
    sortjobs(jobs,n);//sorts the jobs in descending order 
    int maxdeadline=findmaxdeadline(jobs,n);
    int schedule[maxdeadline];
    int slotused[maxdeadline];
    for(int i=0;i<maxdeadline;i++)
    {
        slotused[i]=0;
        schedule[i]=-1;
    }
    int totalprofit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline-1;j>=0;j--)
        {
            if(slotused[j]==0)
            {
                    schedule[j]=jobs[i].id;
                    slotused[j]=1;
                    totalprofit+=jobs[i].profit;
                    break;
            }
        }
    }
    printf("\nScheduled jobs : ");

    for(int i=0;i<maxdeadline;i++)
    {
        if(schedule[i]!=-1)
        {
            printf("%d\t",schedule[i]);
        }
    }
    printf("\nTotal profit : %d\n",totalprofit);
}

void printj(Job jobs[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n%d",jobs[i].profit);

    }
}   

void main()
{
    int n=0,n1;
    printf("Enter the number of jobs : ");
    scanf("%d",&n1);
    n+=n1;
    Job jobs[n];
    for(int i=0;i<n;i++)
    {
        printf("-------------------------");
        printf("\nJob id : ");
        scanf("%d",&jobs[i].id);
        printf("\nJob deadline : ");
        scanf("%d",&jobs[i].deadline);
        printf("\nJob profit : ");
        scanf("%d",&jobs[i].profit);
    }  
    printf("-------------------------");
    jobscheduling(jobs,n);
}