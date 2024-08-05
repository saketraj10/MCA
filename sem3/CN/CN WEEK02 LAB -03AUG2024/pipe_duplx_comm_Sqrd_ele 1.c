#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){ 
 int pp[2],pc[2], pid;
 int a[10],b[10],c[10],d[10];
  pipe(pp);
  pipe(pc);
  pid=fork();
  if(pid==0) {   ///Child
   sleep(5);
   close(pc[1]); //pc - write close
   read(pc[0],b,5*sizeof(int));
   printf(" CHILD - received array b \n");
	   for(int j=0;j<5;j++){
	     printf(" %d \t",b[j]);
	     c[j]=b[j]*b[j];
	   }  
   close(pp[0]); 
   write(pp[1],c,5*sizeof(int)); 
   }	
  else {   //Parent
  printf(" Enter elements to array \n");
	  for(int i=0;i<5;i++){
	     scanf("%d",&a[i]);
	  }
  close(pc[0]);  // pc -read close
  write(pc[1],a,5*sizeof(int));
  close(pp[1]);
  read(pp[0],d,5*sizeof(int));
  printf("\n PARENT - Received squared arrayd \n");
	  for(int k=0;k<5;k++){
	     printf(" %d \t",d[k]);
	  }
  printf("\n");
  wait(0);
 }
 }	
