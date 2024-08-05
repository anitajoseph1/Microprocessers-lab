#include<stdio.h>
void main(){
  int n,j=1,totwt=0,tottat=0,TQ,total=0,completed=0;
  float avgwt,avgtat;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the time quantum:");
  scanf("%d",&TQ);
  int P[n],BT[n],WT[n],TAT[n],remBT[n],a[50];
  printf("Enter the processes and their corresponding burst time:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&P[i]);
    scanf("%d",&BT[i]);
    remBT[i]=BT[i];
  }
  
  while(completed<n){
   for(int i=0;i<n;i++){
    if(remBT[i]>0){
      if(remBT[i]>TQ){
        printf("| P%d ",P[i]);
        total+=TQ;
        remBT[i]-=TQ;
      }
      else{
        printf("| P%d ",P[i]);
        total+=remBT[i];
        TAT[i]=total;
        WT[i]=TAT[i]-BT[i];
        remBT[i]=0;
        completed++;
        
     }
     a[j]=total;
     j++;
    }
   }
  }
  printf("\n");
  a[0]=0;
  for(int i=0;i<j;i++){
    printf(" %d   ",a[i]);
  }
  printf("\n");
  
  printf("Process\t\tBT\tWT\tTAT\n");
  for(int i=0;i<n;i++){
    printf("%d\t\t\t%d\t%d\t%d\n",P[i],BT[i],WT[i],TAT[i]);
    totwt+=WT[i];
    tottat+=TAT[i];
  }
  avgwt=(float)totwt/n;
  avgtat=(float)tottat/n;
  printf("Total WT= %d\n",totwt);
  printf("Total TAT= %d\n",tottat);
  printf("Average WT= %f\n",avgwt);
  printf("Average TAT= %f",avgtat);
}   
