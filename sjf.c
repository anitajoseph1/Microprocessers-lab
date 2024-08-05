#include<stdio.h>
void main(){
  int n,temp,totwt=0,tottat=0;
  float avgwt,avgtat;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  int P[n],BT[n],WT[n],TAT[n];
  printf("Enter the processes and their corresponding burst time:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&P[i]);
    scanf("%d",&BT[i]);
  }
  //sorting the processes based on burst time
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(BT[j]<BT[i]){
        temp=BT[i];
        BT[i]=BT[j];
        BT[j]=temp;
        
        temp=P[i];
        P[i]=P[j];
        P[j]=temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i==0){
      WT[i]=0;
      TAT[i]=BT[i];
      tottat=TAT[i];
    }
    else{
      WT[i]=WT[i-1]+BT[i-1];
      totwt+=WT[i];
      TAT[i]=WT[i]+BT[i];
      tottat+=TAT[i];
    }
  }
  //gantt chart
  printf("Gantt chart:\n");
  for(int i=0;i<n;i++){
    printf("| P%d ",P[i]);
  }
  printf("|\n");
  for(int i=0;i<n;i++){
    printf(" %d   ",WT[i]);
  }
  printf("%d\n  ",TAT[n-1]);
  
  avgwt=(float)totwt/n;
  avgtat=(float)tottat/n;
  printf("Process\t\tBT\tWT\tTAT\n");
  for(int i=0;i<n;i++){
    printf("%d\t\t\t%d\t%d\t%d\n",P[i],BT[i],WT[i],TAT[i]);
  }
  printf("Total WT= %d\n",totwt);
  printf("Total TAT= %d\n",tottat);
  printf("Average WT= %f\n",avgwt);
  printf("Average TAT= %f",avgtat);
}

