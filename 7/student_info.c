#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "student_info.h"
#include "file.h"

void insert_stud(char *fileName)
{
	
	stud s;
	//s.name= malloc(sizeof(char) * 1);
	printf("\nEnter MIS = ");
	scanf("%d",&s.mis);
	printf("\nEnter Name = ");
	scanf("%s",s.name);
	printf("\nEnter Stream = ");
	scanf("%s",s.stream);
	printf("\nEnter CGPA = ");
	scanf("%f",&s.CGPA);
	insert(fileName, s);
}

void update(char *fileName)
{
	int mis;
	printf("\nEnter Mis = ");
	scanf("%d",&mis);
	update_content(fileName,mis);
}

void search(char *fileName)
{
	int mis;
	printf("\nEnter Mis = ");
	scanf("%d",&mis);
	search_content(fileName,mis);
}

void delete_stud(char *fileName)
{
	int mis;
	printf("\nEnter Mis = ");
	scanf("%d",&mis);
	delete_content(fileName,mis);
}

void dept_vise_cnt(char *fileName)
{
	int comp=0,metch=0,civil=0,ele=0,entc=0,intru=0,meta=0;
	
	FILE *fp = fopen(fileName, "rb");
	
	if(!fp)
    	{
        printf("\n something is wrong...!");
        return;
    	}
    	
    	stud s;
    	while(fread(&s,sizeof(s),1,fp) == 1)
  	{
  		
	  	if(strcmp(s.stream,"comp") == 0)
	  	{
	  		comp++; 
	  	 	
	  	}
	  	
	  	if(strcmp(s.stream,"metch") ==0)
	  	{
	  		metch++; 
	  	 	
	  	}
	  	
	  	if(strcmp(s.stream,"ele") == 0)
	  	{
	  		ele++; 
	  	 	
	  	}
	  	
	  	if(strcmp(s.stream,"entc") == 0)
	  	{
	  		entc++; 
	  	 	
	  	}
	  	
	  	if(strcmp(s.stream,"intru") == 0)
	  	{
	  		intru++; 
	  	 	
	  	}
	  	
	  	if(strcmp(s.stream,"meta") == 0)
	  	{
	  		meta++; 
	  	 	
	  	}
  	}
  	printf("\nComputer Student = %d\n\nMechanical student = %d\n\nElectrical student = %d\n\nElectronic student = %d\n\nInstumentation student = %d\n\nMetalleragy student = %d\n\nCivil student = %d",comp,metch,ele,entc,intru,meta,civil);
}

