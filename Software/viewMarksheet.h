#ifndef VIEWSEMESTERINFO_H_INCLUDED
#define VIEWSEMESTERINFO_H_INCLUDED

void markSheet ()
{
    struct stu read_student;
    struct semesterInfo si;
    struct cou_en read_course_enroll;
    struct cou read_course;
    struct re read_results;
    FILE *rf;
    float sumofGP = 0,GPA;
    int n = 0;
    char totalGrade[5];

    printf("\t\t\t\t\t\t    View Semester Mark sheet\n");
    printf("\t\t-------------------------------------------------------------------------------------------------\n\n");

    printf("\t\t\t\t\t\tEnter Semester Name : ");
    scanf(" %[^\n]",si.semesterName);
    for (k=0; k<130; k++)   {   printf("\b");   }
    printf("\t\t\t\t\t\tResult of Semester : %s     \n",si.semesterName);
    printf("\t\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tCourse Code | Mid Mark | Final Mark | Out of 30 | Total Mark | Grad Point | Grade\n");
    printf("\t\t-------------------------------------------------------------------------------------------------\n\n");

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(StudentID == read_student.id)
        {
            strcpy(si.program,read_student.program);
            strcpy(si.shift,read_student.shift);
            si.intake = read_student.intake;
            break;
        }
    }fclose(f);

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll.semester_name,read_course_enroll.program,read_course_enroll.shift,&read_course_enroll.intake,&read_course_enroll.semester_no);
        if(strcmp(si.semesterName,read_course_enroll.semester_name)==0 && strcmp(si.program,read_course_enroll.program)==0 && strcmp(si.shift,read_course_enroll.shift)==0 && si.intake == read_course_enroll.intake)
        {
            si.semesterNo = read_course_enroll.semester_no;
            break;
        }
    }fclose(f);

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
        if(strcmp(si.program,read_course.program)==0 && si.semesterNo == read_course.semester)
        {
            rf = fopen("results.txt","r");
            while(!feof(rf))
            {
                fscanf(rf,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results.semester_name,read_results.program,read_results.shift,&read_results.intake,&read_results.sem_no,&read_results.stu_id,read_results.course,&read_results.midMark,&read_results.finalMark,&read_results.sirMark,&read_results.totalMark,&read_results.gradePoint,read_results.grade);
                if(strcmp(si.semesterName,read_results.semester_name)==0 && strcmp(si.program,read_results.program)==0 && strcmp(si.shift,read_results.shift)==0 && si.intake == read_results.intake && si.semesterNo == read_results.sem_no && StudentID == read_results.stu_id && strcmp(read_course.code,read_results.course)==0)
                {
                    printf("\t\t\t%s     |   %.1f   |   %.1f     |   %.1f    |   %.1f     |   %.2f     |   %s\n",read_course.code,read_results.midMark,read_results.finalMark,read_results.sirMark,read_results.totalMark,read_results.gradePoint,read_results.grade);
                    printf("\n\t\t-------------------------------------------------------------------------------------------------\n\n");
                    sumofGP += read_results.gradePoint;
                    n++;
                }
            }fclose(rf);
        }
    }fclose(f);
    GPA = sumofGP / n;
    if(GPA == 4.00)
        strcpy(totalGrade,"A+");

    else if(GPA >= 3.75 && GPA <= 3.99)
        strcpy(totalGrade,"A");

    else if(GPA >= 3.50 && GPA <= 3.74)
        strcpy(totalGrade,"A-");

    else if(GPA >= 3.25 && GPA <= 3.49)
        strcpy(totalGrade,"B+");

    else if(GPA >= 3.00 && GPA <= 3.24)
        strcpy(totalGrade,"B");

    else if(GPA >= 2.75 && GPA <= 2.99)
        strcpy(totalGrade,"B-");

    else if(GPA >= 2.50 && GPA <= 2.74)
        strcpy(totalGrade,"C+");

    else if(GPA >= 2.25 && GPA <= 2.49)
        strcpy(totalGrade,"C");

    else if(GPA >= 2.00 && GPA <= 2.24)
        strcpy(totalGrade,"D");

    else
        strcpy(totalGrade,"F");

    printf("\t\t\t\t\t\tSGPA : %.2f    |    GRADE : %s\n\n\n",GPA,totalGrade);
    printf("\t\t\t\t\tDo you want to view another marksheet ? y / n...");   permission = getch();
    if(permission == 'Y' || permission == 'y')
    {
        system("CLS");    title(); markSheet();
    }
    else
    {
      system("CLS");    title();    student_main_menu();
    }

}

#endif // VIEWSEMESTERINFO_H_INCLUDED
