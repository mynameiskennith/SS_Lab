#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void main(){
    FILE *f1,*f2,*assem,*symtab,*opp;
    int lc,sa,len =18,op1,oplen;
    char m1[20],la[20],op[20],hex[20],op2[20],adr[20],sym[20],shex[20];

    f1=fopen("inter.txt","r");
    f2=fopen("optab.txt","r");
    symtab=fopen("symtab.txt","r");
    assem=fopen("assembly_listing.txt","w");
    opp=fopen("object_program.txt","w");
    

    fscanf(f1,"%s\t%s\t%d",la,m1,&op1);

    if(strcmp(m1,"START")==0){
    	sa=op1;
        fprintf(assem,"\tPRGM1\t%s\t%d\n",m1,op1);
    }
    fprintf(opp,"H%cPRGM1%c00%d%c0000%d\n",'^','^',op1,'^',len); //Header Record added
    
    fscanf(f1,"%s\t%s\t%s\t%s",adr,la,m1,op2);	  //First line from intermediate file
    
    while(strcmp(m1,"END")!=0){
    	if(strcmp(m1,"RESW")!=0)
    		fprintf(opp,"T^00%s^03",adr);
        fprintf(assem,"%s\t%s\t%s\t%s\t",adr,la,m1,op2); //adress,label,opcode,operand in assembly listing
        
        while(!feof(f2)){								 //finding opcode for operator
        	fscanf(f2,"%s\t%s\n",op,hex);
        	if(strcmp(m1,op)==0)
            		break;
        }
        while(!feof(symtab)){							 //finding symbol address from symtab
        	fscanf(symtab,"%s\t%s\n",sym,shex);
        	if(strcmp(op2,sym)==0)
            		break;
        }
        
        if(strcmp(la,"**")==0){		//if label is null
		    strcat(hex,shex);		//created object code
		    
		    fprintf(assem,"%s\n",hex);  //added object code to assembly listing
		    fprintf(opp,"^%s\n",hex);		//sdded object code to text record
		    
        }else{	//if label is not null
        	if(strcmp(m1,"WORD")==0){	//if opcode is word
        		int word_len = strlen(op2);
        		char word_c[6]="";
        		while(word_len!=6){		//concatanating until 6 digits
        			word_len++;
        			strcat(word_c,"0");
        		}
        		strcat(word_c,op2);
        		fprintf(assem,"%s\n",word_c);	//writing opcode to sassembly listing
        		fprintf(opp,"%c%s\n",'^',word_c);
        	}
        }
        fscanf(f1,"%s\t%s\t%s\t%s",adr,la,m1,op2);
    }
    fprintf(assem,"\n%s\t%s\t%s\t",adr,la,m1);
    if(strcmp(m1,"RESW")==0)
    	fprintf(opp,"\n");
    fprintf(opp,"E%c00%d",'^',sa);
}
