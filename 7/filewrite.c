#include<stdio.h>
#include "student_info.h"
#include"file.h"


void insert(char *fileName, stud s)
{
    FILE *fp = fopen(fileName, "ab");
    if(!fp)
    {
        printf("\n something is wrong...!");
        return;
    }
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    return;
}



