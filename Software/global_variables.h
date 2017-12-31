#ifndef GLOBAL_VARIABLES_H_INCLUDED
#define GLOBAL_VARIABLES_H_INCLUDED

struct pro
{
    char code[20],name[100];
};
struct cou
{
    char program[10],code[20],title[100],type[10];
    int semester;
    float credit;
};
struct stu
{
    int id,intake,section;
    char name[20],program[50],shift[10],semester[30];
};
struct cou_en
{
    int intake,semester_no,stu_id;
    char program[10],course[100],semester_name[20],shift[10];
};
struct re
{
    int intake,sem_no,stu_id;
    float midMark,finalMark,sirMark,totalMark,gradePoint;
    char program[10],course[10],semester_name[20],shift[10],grade[5];
};
struct pa
{
    int intake,semNo,stuID,totalAmount,payAmount,dueAmount;
    char semName[15],program[10],shift[10];
};
struct semesterInfo
{
    char semesterName[20],program[10],shift[10];
    int intake,semesterNo;
};

char permission,StuNameTitle[20];
int match = 0,selectID,i,j,k,selectProgram,StudentID;
FILE *f;

#endif // GLOBAL_VARIABLES_H_INCLUDED
