CC=gcc  #compiler
TARGET=output#target file name
 
 all:	fileread.o filewrite.o main.o student_info.o
	$(CC) fileread.c filewrite.c main.c student_info.c -o $(TARGET)
 
clean:
	rm -r *.o $(TARGET)


