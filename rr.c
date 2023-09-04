#include<stdio.h>

struct process{
	int name,bt,ct,tat,wt,at;
};

void main(){
	
	int n,i,j=0,tc,total,inter_ct,a[100];
	printf("Enter the number of Processes : ");
	scanf("%d",&n);
	
	struct process p[n];
	
	
	printf("Enter the Burst time : \n");
	for(i=0;i<n;i++){
		p[i].name=i;
		printf("P%d : ",i);
		scanf("%d",&p[i].bt);

		p[i].at=0;
		p[i].ct=0;
	}
	
	int b[n];
	
	for(i=0;i<n;i++)
		b[i]=p[i].bt;
	
	printf("Enter the time quantum : ");
	scanf("%d",&tc);
	
	for(i=0;i<n;i++)
		total = total + b[i];
	
	printf("\n--------GANTT CHART--------\n");
	printf("| 	");
		
	while(inter_ct != total){
		for(i=0;i<n;i++){
			if(b[i]!=0){
				if(b[i]<tc){
					inter_ct=inter_ct+b[i];
					b[i]=0;
					if(b[i]==0)
						p[i].ct=inter_ct;
				}
				else if(b[i]>=tc){
					inter_ct=inter_ct+tc;
					b[i]=b[i]-tc;
					if(b[i]==0)
						p[i].ct=inter_ct;
					}
			}
			a[j++]=inter_ct;
			printf("P%d	|\t",i);
		}
	}
	
	printf("\n---------------------------\n");
	printf("|	");
	for(i=0;a[i]!=0;i++){
		printf("%d	|\t",a[i]);
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
	printf("\nProcess\tB.T\tTAT\tWT");
	for(i=0;i<n;i++){
	printf("\nP%d\t%d\t%d\t%d",p[i].name,p[i].bt,p[i].tat,p[i].wt);
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
