#include <stdio.h>
#include <stdlib.h>

void main(){
	int i,j,n,head,end,head_pos,seek;
	
	printf("Enter the number of jobs : ");
	scanf("%d",&n);
	n=n+3;
	int job[n],vis[n];
	
	printf("\nEnter the head : ");
	scanf("%d",&head);
	printf("\nEnter the maximum of the jobs : ");
	scanf("%d",&end);
	
	job[0]=0;job[1]=head;job[2]=end;
	printf("\nEnter the job values : ");
	for(i=3;i<n;i++)
		scanf("%d",&job[i]);
	
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(job[j]>job[j+1]){
				int temp=job[j];
				job[j]=job[j+1];
				job[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++){
	printf("\n%d",job[i]);
	}
	
	for(i=0;i<n;i++){
		if(job[i]==head){
			head_pos=i;
			break;
		}
	}
	
	for(i=head_pos;i<n-1;i++){
		printf("\nDistance between %d and %d : %d",job[i],job[i+1],abs(job[i]-job[i+1]));
		seek+=abs(job[i]-job[i+1]);
	}
	
	printf("\nDistance between %d and 0 : %d",end,abs(0-end));
	seek+=abs(0-end);
	
	for(i=0;i<head_pos;i++){
		printf("\nDistance between %d and %d : %d",job[i],job[i+1],abs(job[i]-job[i+1]));
		seek+=abs(job[i]-job[i+1]);
	}
	
	printf("\nTotal Seek time : %d",seek);
}
