#include<stdio.h> 
 
int main() 
{ 
 
  int cnt,j,n,time,remain,flag=0,timeQuantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter the no.of Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(cnt=0;cnt<n;cnt++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",cnt+1); 
    scanf("%d",&at[cnt]); 
    scanf("%d",&bt[cnt]); 
    rt[cnt]=bt[cnt]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&timeQuantum); 
  printf("\n\nProcess	-	Turnaround Time	-	Waiting Time\n\n"); 
  for(time=0,cnt=0;remain!=0;) 
  { 
    if(rt[cnt]<=timeQuantum && rt[cnt]>0) 
    { 
      time+=rt[cnt]; 
      rt[cnt]=0; 
      flag=1; 
    } 
    else if(rt[cnt]>0) 
    { 
      rt[cnt]-=timeQuantum; 
      time+=timeQuantum; 
    } 
    if(rt[cnt]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]	-		%d 	-		%d\n",cnt+1,time-at[cnt],time-at[cnt]-bt[cnt]); 
      wait_time+=time-at[cnt]-bt[cnt]; 
      turnaround_time+=time-at[cnt]; 
      flag=0; 
    } 
    if(cnt==n-1) 
      cnt=0; 
    else if(at[cnt+1]<=time) 
      cnt++; 
    else 
      cnt=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
