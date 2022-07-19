#include<stdio.h>
#include "student_info.h"
#include"file.h"


void display_file(char *fileName)
{
     FILE *fp = fopen(fileName, "rb");
    if(!fp)
    {
        printf("\n something is wrong...!");
        return;
    }
  
  stud s;
  //fread(&s1,sizeof(s1),1,fp);
  while(fread(&s,sizeof(s),1,fp) == 1)
  {
  printf("%d\t %s\t %s\t %f",s.mis,s.name,s.stream,s.CGPA);
  printf("\n");
  }
  fclose(fp);
  return;
  
}

void update_content(char *fileName, int mis)
{
	int count =0;
	FILE *fp = fopen(fileName, "rb+");
    if(!fp)
    {
        printf("\n something is wrong...!");
        return;
    }
    
    stud s,s1;
    int flag = 0;
  while(fread(&s,sizeof(s),1,fp) == 1)
  {
  	if(s.mis == mis)
  	{
  		printf("\nEnter MIS = ");
		scanf("%d",&s.mis);
		printf("\nEnter Name = ");
		scanf("%s",s.name);
		printf("\nEnter Stream = ");
		scanf("%s",s.stream);
		printf("\nEnter CGPA = ");
		scanf("%f",&s.CGPA);
  		fseek(fp,-(sizeof(s)),SEEK_CUR);
  		fwrite(&s,sizeof(s),1,fp);
  		fread(&s,sizeof(s),1,fp);
  		flag = 1;
  	 	break;	 
  	 	
  	}
  }
  if(flag == 0)
  	printf("\nStudent not found...!");
  else
  	printf("\nStudent information updated...!");
  
  fclose(fp);
}


void search_content(char *fileName, int mis)
{
	int count =0;
	FILE *fp = fopen(fileName, "rb+");
    if(!fp)
    {
        printf("\n something is wrong...!");
        return;
    }
    
    stud s,s1;
    int flag = 0;
  while(fread(&s,sizeof(s),1,fp) == 1)
  {
  	if(s.mis == mis)
  	{
  		printf("\n%d\t%s\t%s\t%f",s.mis,s.name,s.stream,s.CGPA);
  		flag = 1;
  	 	break;	 
  	 	
  	}
  }
  if(flag == 0)
  	printf("\nStudent not found...!");
  else
  	printf("\nStudent found...!");
  
  fclose(fp);
}

void delete_content(char *fileName, int mis)
{
	
	FILE *fp = fopen(fileName, "rb");
	FILE *fp1 = fopen("temp.bin", "wb");
    if(!fp)
    {
        printf("\n something is wrong...!");
        return;
    }
    
    stud s;
    int flag = 0;
  while(fread(&s,sizeof(s),1,fp) == 1)
  {
  	if(s.mis == mis)
  	{
  		//printf("\n%d\t%s\t%s\t%f",s.mis,s.name,s.stream,s.CGPA);
  		flag = 1;
  		continue;
  	 	
  	}
  	else
  	{
  		fwrite(&s,sizeof(s),1,fp1);
  	}
  }
  
  fclose(fp);
  fclose(fp1);
  fp = fopen(fileName, "wb");
  fp1 = fopen("temp.bin", "rb");
  while(fread(&s,sizeof(s),1,fp1) == 1)
  {
  	fwrite(&s,sizeof(s),1,fp);
  }
  
  if(flag == 0)
  	printf("\nStudent not found...!");
  else
  	printf("\nStudent found...!");
  fclose(fp1);
  fclose(fp);
}
