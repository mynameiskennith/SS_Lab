#include<stdio.h>

struct process{
	int name,bt,ct,tat,wt,at,pri;
}temp;



void main(){
	
	int n,i;
	printf("Enter the number of Processes : ");
	scanf("%d",&n);
	
	struct process p[n];
	
	
	printf("Enter the Burst time and Priority: \n");
	for(i=0;i<n;i++){
		p[i].name=i;
		printf("P%d : ",i);
		printf("Bt : ");
		scanf("%d",&p[i].bt);
		printf("Pri : ");
		scanf("%d",&p[i].pri);
		p[i].at=0;
		p[i].ct=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(p[j].pri>p[j+1].pri){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	//Calculating completion time
	p[-1].ct=0;
	for(i=0;i<n;i++){
		p[i].ct=p[i-1].ct+p[i].bt;
	}
	
	//Displaying GANTT CHART
	printf("\n--------GANTT CHART--------\n");
	printf("|  ");
	for(i=0;i<n;i++){
		printf("P%d	|\t",p[i].name);
	}
	printf("\n---------------------------\n");
	printf("|  ");
	for(i=0;i<n;i++){
		printf("%d	|\t",p[i].ct);
	}
	printf("\n---------------------------\n");
	
	//Calculating TAT
	for(i=0;i<n;i++){
		p[i].tat= p[i].ct-p[i].at;
	}
	
	//Calculating WT
	for(i=0;i<n;i++){
		p[i].wt=p[i].tat-p[i].bt;
	}
	
	//TABLE
	printf("\nProcess\tB.T\tPri\tTAT\tWT");
	for(i=0;i<n;i++){
		printf("\nP%d\t%d\t%d\t%d\t%d ",p[i].name,p[i].bt,p[i].pri,p[i].tat,p[i].wt);
	}
	
	float tsum=0.0,wsum=0.0;
	for(i=0;i<n;i++){
		tsum =tsum+p[i].tat;
	}
	printf("\n\nTotal Turn Around Time : %f",tsum);
	
	for(i=0;i<n;i++){
		wsum =wsum+p[i].wt;
	}
	printf("\nToatal Waiting Time : %f",wsum);
	
	float tavg=(tsum/n),wavg=(wsum/n);
	printf("\n\nAverage of Turn Around Time : %f",tavg);
	printf("\nAverage of Waiting Time : %f",wavg);
}
