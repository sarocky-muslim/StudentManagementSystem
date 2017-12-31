#ifndef VIEWTOTALCOURSE_H_INCLUDED
#define VIEWTOTALCOURSE_H_INCLUDED

void totalCourse ()
{
    struct stu read_student;
    struct semesterInfo si;
    struct cou read_course;
    struct re read_results;
    char status[12];
    FILE *rf;

    printf("\t\t\t\t\t\t    All Course List Info\n");
    printf("\t\---------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\t\t   STATUS\t| SEM NO | COURSE CODE  | CREDIT  |   TYPE\t|\tCOURSE TITLE\n\n");
    printf("\t\---------------------------------------------------------------------------------------------------------------------\n");

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(StudentID == read_student.id)
        {
            strcpy(si.program,read_student.program);
            break;
        }
    }fclose(f);

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
        if(strcmp(si.program,read_course.program)==0)
        {
            rf = fopen("results.txt","r");
            while(!feof(rf))
            {
                fscanf(rf,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results.semester_name,read_results.program,read_results.shift,&read_results.intake,&read_results.sem_no,&read_results.stu_id,read_results.course,&read_results.midMark,&read_results.finalMark,&read_results.sirMark,&read_results.totalMark,&read_results.gradePoint,read_results.grade);
                if(StudentID == read_results.stu_id && strcmp(read_course.code,read_results.course)==0)
                {
                    if(strcmp(read_results.grade,"F")==0)
                        strcpy(status,"Incomplete");
                    else
                        strcpy(status,"Complete");

                    break;
                }
                else
                    strcpy(status,"Incomplete");

            }fclose(rf);

            printf("\t\t%s\t|   %d\t |   %s\t|   %.1f\t  |   %s   \t| %s",status,read_course.semester,read_course.code,read_course.credit,read_course.type,read_course.title);
            printf("\n\t---------------------------------------------------------------------------------------------------------------------\n");
        }
    }fclose(f);

    printf("\n\t\t\t\t\tPress Any Key To Go Main Menu...");
    getch();    system("CLS");    title();    student_main_menu();

}

#endif // VIEWTOTALCOURSE_H_INCLUDED
