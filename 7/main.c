#include <stdio.h>
#include<stdlib.h>
#include "student_info.h"
#include"file.h"



void main()
{
	int choice;
	while(1)
	{
		printf("\n1.Insert.\n2.Display all students.\n3.Search\n4.Update.\n5.Delete.\n6.Depart vise student.\n7.Exit.\n  Enter Choice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_stud("demo.bin");
			break;
			
			case 2:
				display_file("demo.bin");
			break;
			
			case 3:
				search("demo.bin");
			break;
			
			case 4:
				update("demo.bin");
			break;
			
			case 5:
				delete_stud("demo.bin");
			break;
			
			case 6:
				dept_vise_cnt("demo.bin");
			break;
			
			case 7:
				return;
			break;
			
			default:
				printf("\nwrongchoice...!");
		}
	}
	
	//
	return;
}
