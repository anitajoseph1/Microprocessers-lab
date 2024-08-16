#include <stdio.h>
void fcfs();
void sjf();
void priority();
void roundrobin();
int n,temp,totwt=0,tottat=0;
float avgwt,avgtat;
void main(){
    int choice;
    while(choice<5){
        printf("\nCPU Scheduling algorithms:\n1.FCFS Scheduling\n2.SJF Scheduling\n3.Priority Scheduling\n4.Round Robin Scheduling\n5.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                fcfs();
                break;
            case 2:
                sjf();
                break;
            case 3:
                priority();
                break;
            case 4:
                roundrobin();
                break;
            default:
                printf("Exited");
                break;
        }
    }
}
void fcfs(){
  printf("\n");
  printf("FCFS Scheduling:\n");
  printf("Enter the number of processes:");
  scanf("%d",&n);
  int P[n],BT[n],WT[n],TAT[n];
  printf("Enter the processes and their corresponding burst time:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&P[i]);
    scanf("%d",&BT[i]);
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
void sjf(){
  printf("\n");
  printf("SJF Scheduling:\n");
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
void priority(){
  printf("\n");
  printf("Priority Scheduling:\n");
  printf("Enter the number of processes:");
  scanf("%d",&n);
  int P[n],BT[n],WT[n],TAT[n],Pri[n];
  printf("Enter the processes and their corresponding burst time and priority:\n");
  for(int i=0;i<n;i++){
    scanf("%d",&P[i]);
    scanf("%d",&BT[i]);
    scanf("%d",&Pri[i]);
  }
  //sorting the processes based on burst time
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(Pri[j]<Pri[i]){
        temp=Pri[i];
        Pri[i]=Pri[j];
        Pri[j]=temp;
       
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
void roundrobin(){
  int total=0,completed=0,TQ,j=1;
  printf("\n");
  printf("Round Robin Scheduling:\n");
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
  printf("Gantt chart:\n");
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
