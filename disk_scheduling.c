#include<stdio.h>
#include<stdlib.h>
int n,head,temp,seektime=0,distance,size,a=0,a1=0,a2=0,q[20],q1[20],q2[20],t;
void fcfs();
void scan();
void cscan();
void main(){
  int choice;
  while(choice<4){
    printf("\nDisk Scheduling algorithms:\n1.FCFS\n2.SCAN\n3.CSCAN\n4.Exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
          fcfs();
          break;
      case 2:
          scan();
          break;
      case 3:
          cscan();
          break;
      default:
          printf("Exited");
          break;
    }
  }
}

void fcfs(){
  printf("\nFCFS:\n");
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  int RQ[n];
  printf("Enter the head:");
  scanf("%d",&head);
  printf("Enter the request queue: ");
  for(int i=1;i<=n;i++){
    scanf("%d",&RQ[i]);
  }
  RQ[0]=head;
  for(int i=0;i<n;i++){
    distance=abs(RQ[i+1]-RQ[i]);
    printf("Head movement from %d to %d: %d\n",RQ[i],RQ[i+1],distance);
    seektime+=distance;
  }
  printf("Total head movement: %d",seektime);
}

void scan(){
  printf("\nSCAN:\n");
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  printf("Enter the head:");
  scanf("%d",&head);
  printf("Enter disk size: ");
  scanf("%d",&size);
  for(int i=1;i<=n;i++){
    printf("Enter request: ");
    scanf("%d",&temp);
    if(temp>head){
      q1[a1]=temp;
      a1++;
    }
    else{
      q2[a2]=temp;
      a2++;
    }
  }
  
  for(int i=0;i<a1;i++){
    for(int j=i+1;j<a1;j++){
      if(q1[i]>q1[j]){
        t=q1[i];
        q1[i]=q1[j];
        q1[j]=t;
      }
    }
  }
  for(int i=0;i<a2;i++){
    for(int j=i+1;j<a2;j++){
      if(q2[i]<q2[j]){
        t=q2[i];
        q2[i]=q2[j];
        q2[j]=t;
      }
    }
  }
  
  q[a]=head;
  a++;
  for(int i=0;i<a1;i++){
    q[a]=q1[i];
    a++;
  }
  q[a]=size-1;
  a++;
  for(int i=0;i<a2;i++){
    q[a]=q2[i];
    a++;
  }
  q[a]=0;
  for(int i=0;i<a-1;i++){
    distance=abs(q[i+1]-q[i]);
    printf("Head movement from %d to %d: %d\n",q[i],q[i+1],distance);
    seektime+=distance;
  }
  printf("Total head movement: %d",seektime);
}

void cscan(){
  printf("\nCSCAN:\n");
  printf("Enter the number of requests: ");
  scanf("%d",&n);
  printf("Enter the head:");
  scanf("%d",&head);
  printf("Enter disk size: ");
  scanf("%d",&size);
  for(int i=1;i<=n;i++){
    printf("Enter request: ");
    scanf("%d",&temp);
    if(temp>head){
      q1[a1]=temp;
      a1++;
    }
    else{
      q2[a2]=temp;
      a2++;
    }
  }
  
  for(int i=0;i<a1;i++){
    for(int j=i+1;j<a1;j++){
      if(q1[i]>q1[j]){
        t=q1[i];
        q1[i]=q1[j];
        q1[j]=t;
      }
    }
  }
  for(int i=0;i<a2;i++){
    for(int j=i+1;j<a2;j++){
      if(q2[i]>q2[j]){
        t=q2[i];
        q2[i]=q2[j];
        q2[j]=t;
      }
    }
  }
  
  q[a]=head;
  a++;
  for(int i=0;i<a1;i++){
    q[a]=q1[i];
    a++;
  }
  q[a]=size-1;
  a++;
  for(int i=0;i<a2;i++){
    q[a]=q2[i];
    a++;
  }
  q[a]=0;
  for(int i=0;i<a-1;i++){
    distance=abs(q[i+1]-q[i]);
    printf("Head movement from %d to %d: %d\n",q[i],q[i+1],distance);
    seektime+=distance;
  }
  printf("Total head movement: %d",seektime);
}


