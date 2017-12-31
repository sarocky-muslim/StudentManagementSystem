#ifndef VIEWSUMMERY_H_INCLUDED
#define VIEWSUMMERY_H_INCLUDED

void viewSummery ()
{
    struct stu read_student;
    struct re read_results;
    struct semesterInfo si;
    struct cou read_course;
    float sumofGP = 0,CGPA,totalCredit = 0, comCredit = 0;
    int n = 0,totalCourse = 0, comCourse = 0;
    FILE *rf;

    printf("\t\t\t\t\t\t    Summary Information\n");
    printf("\t\t\t-----------------------------------------------------------------------------\n\n");

    f = fopen("results.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results.semester_name,read_results.program,read_results.shift,&read_results.intake,&read_results.sem_no,&read_results.stu_id,read_results.course,&read_results.midMark,&read_results.finalMark,&read_results.sirMark,&read_results.totalMark,&read_results.gradePoint,read_results.grade);
        if(StudentID == read_results.stu_id)
        {
            sumofGP += read_results.gradePoint;
            n++;
        }
    }fclose(f);

    CGPA = sumofGP / n;

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
                    if(strcmp(read_results.grade,"F")!=0)
                    {
                        comCredit += read_course.credit;
                        comCourse++;
                    }
                    break;
                }

            }fclose(rf);

            totalCredit += read_course.credit;
            totalCourse++;
        }
    }fclose(f);

    printf("\t\t\t\t\tID\t\t\t: %d\n\n",read_student.id);
    printf("\t\t\t\t\tName\t\t\t: %s\n\n",read_student.name);
    printf("\t\t\t\t\tIntake\t\t\t: %d\n\n",read_student.intake);
    printf("\t\t\t\t\tSection\t\t\t: %d\n\n",read_student.section);
    printf("\t\t\t\t\tShift\t\t\t: %s\n\n",read_student.shift);
    printf("\t\t\t\t\tCGPA\t\t\t: %.2f\n\n",CGPA);
    printf("\t\t\t\t\tComplete Credit\t\t: %.2f out of %.2f\n\n",comCredit,totalCredit);
    printf("\t\t\t\t\tComplete Courses\t: %d out of %d\n\n",comCourse,totalCourse);

    printf("\t\t\t-----------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tPress Any Key To Go Main Menu...");
    getch();    system("CLS");    title();    student_main_menu();
}

#endif // VIEWSUMMERY_H_INCLUDED
