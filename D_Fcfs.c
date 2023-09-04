#include <stdio.h>
#include <stdlib.h>
void main(){
	int i,h,n,seek=0;
	
	printf("\nEnter the head : ");
	scanf("%d",&h);
	printf("\nEnter the number of jobs : ");
	scanf("%d",&n);
	
	int j[n+1];
	printf("\nEnter the sequence : ");
	for(i=1;i<n+1;i++)
		scanf("%d",&j[i]);
	
	j[0]=h;
	for(i=0;i<n;i++){
		printf("\nDistance between %d and %d : %d",j[i],j[i+1],abs(j[i]-j[i+1]));
		seek=seek+abs(j[i+1]-j[i]);
	}
	
	printf("\nSeek Time : %d",seek);
}


