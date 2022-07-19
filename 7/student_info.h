typedef struct student
{
    int mis;
    char name[100];
    char stream[100];
    float CGPA;
}stud;

void insert_stud(char *fileName);
void display(char *fileName);
void search(char *fileName);
void delete_stud(char *fileName);
void update(char *fileName);
void dept_vise_cnt(char *fileName);
