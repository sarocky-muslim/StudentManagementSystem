#ifndef RESULTS_H_INCLUDED
#define RESULTS_H_INCLUDED


void results ()
{
    printf("\t\t\t\t1.Add Results | 2.View Results | 3.View Marksheet | 4.Edit Results\n");
    printf("\t\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    5.Main Menu | 6.Exit\n");
    printf("\t\t\t--------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_results_f();  break;

        case 2:     system("CLS");  title();  view_results_f();  break;

        case 3:     system("CLS");  title();  view_marksheet_f();  break;

        case 4:     system("CLS");  title();  edit_results_f();  break;

        case 5:     system("CLS");  title();  admin_main_menu();  break;

        case 6:     break;

        default:    printf("\t\t\t\t\tPress select the right menu");  break;
    }
    exit(0);
}

void add_results_title()
{
    printf("\t\t\t\t\t\t    Add Results Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

}
void edit_results_title()
{
    printf("\t\t\t\t\t\t    Edit Results Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

}
void view_results_title()
{
    printf("\t\t\t\t\t\t    View Results Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

}
void view_marksheet_title()
{
    printf("\t\t\t\t\t\t    View Student Marksheet\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}

void add_results_f()
{
    struct re add_results;
    struct re add_results2[100];
    struct re read_results;
    struct cou_en read_course_enroll[100];
    struct cou read_course;
    struct stu read_student;
    int match = 1,rmatch,sub,fsize,n=0,selectEnroll;
    FILE *sf,*cf,*rf;

    add_results_title();

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll[n].semester_name,read_course_enroll[n].program,read_course_enroll[n].shift,&read_course_enroll[n].intake,&read_course_enroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,read_course_enroll[i].semester_name,read_course_enroll[i].program,read_course_enroll[i].shift,read_course_enroll[i].intake,read_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To Add Result: ");  scanf("%d",&selectEnroll);

    strcpy(add_results.semester_name,read_course_enroll[selectEnroll-1].semester_name);
    strcpy(add_results.program,read_course_enroll[selectEnroll-1].program);
    strcpy(add_results.shift,read_course_enroll[selectEnroll-1].shift);
    add_results.intake = read_course_enroll[selectEnroll-1].intake;
    add_results.sem_no = read_course_enroll[selectEnroll-1].semester_no;

    system("CLS"); title(); add_results_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    sf = fopen("student.txt","r");
    while(!feof(sf))
    {
        fscanf(sf,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(strcmp(add_results.program,read_student.program)==0 && add_results.intake == read_student.intake)
        {
            add_results.stu_id = read_student.id;
            printf("\t\t\t\t\t\t\tStudent ID : %d\n",add_results.stu_id);
            printf("\t\t\t\t---------------------------------------------------------------\n");

            rmatch = 0;sub = 0;
            cf = fopen("course.txt","r");
            while(!feof(cf))
            {
                fscanf(cf,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
                if(strcmp(add_results.program,read_course.program)==0 && add_results.sem_no == read_course.semester)
                {
                    strcpy(add_results2[sub].course,read_course.code);
                    printf("\n\t\t\t\t\tCourse Code : %s\n",add_results2[sub].course);
                    printf("\n\t\t\t\t\tMid Mark: ");       scanf("%f",&add_results2[sub].midMark);
                    printf("\n\t\t\t\t\tFinal Mark: ");     scanf("%f",&add_results2[sub].finalMark);
                    printf("\n\t\t\t\t\tOut of 30: ");      scanf("%f",&add_results2[sub].sirMark);
                    add_results2[sub].totalMark = add_results2[sub].midMark + add_results2[sub].finalMark + add_results2[sub].sirMark;
                    printf("\n\t\t\t\t\tTotal Mark: %.1f\n",add_results2[sub].totalMark);
                    if(add_results2[sub].totalMark>=80 && add_results2[sub].totalMark<=100)
                    {
                        add_results2[sub].gradePoint = 4.00;
                        strcpy(add_results2[sub].grade,"A+");

                    }else if(add_results2[sub].totalMark>=75 && add_results2[sub].totalMark<=79)
                    {
                        add_results2[sub].gradePoint = 3.75;
                        strcpy(add_results2[sub].grade,"A");

                    }else if(add_results2[sub].totalMark>=70 && add_results2[sub].totalMark<=74)
                    {
                        add_results2[sub].gradePoint = 3.50;
                        strcpy(add_results2[sub].grade,"A-");

                    }else if(add_results2[sub].totalMark>=65 && add_results2[sub].totalMark<=69)
                    {
                        add_results2[sub].gradePoint = 3.25;
                        strcpy(add_results2[sub].grade,"B+");

                    }else if(add_results2[sub].totalMark>=60 && add_results2[sub].totalMark<=64)
                    {
                        add_results2[sub].gradePoint = 3.00;
                        strcpy(add_results2[sub].grade,"B");

                    }else if(add_results2[sub].totalMark>=55 && add_results2[sub].totalMark<=59)
                    {
                        add_results2[sub].gradePoint = 2.75;
                        strcpy(add_results2[sub].grade,"B-");

                    }else if(add_results2[sub].totalMark>=50 && add_results2[sub].totalMark<=54)
                    {
                        add_results2[sub].gradePoint = 2.50;
                        strcpy(add_results2[sub].grade,"C+");

                    }else if(add_results2[sub].totalMark>=45 && add_results2[sub].totalMark<=49)
                    {
                        add_results2[sub].gradePoint = 2.25;
                        strcpy(add_results2[sub].grade,"C");

                    }else if(add_results2[sub].totalMark>=40 && add_results2[sub].totalMark<=44)
                    {
                        add_results2[sub].gradePoint = 2.00;
                        strcpy(add_results2[sub].grade,"D");
                    }
                    else
                    {
                        add_results2[sub].gradePoint = 0.00;
                        strcpy(add_results2[sub].grade,"F");
                    }
                    printf("\n\t\t\t\t\tGrade Point: %.2f\n",add_results2[sub].gradePoint);
                    printf("\n\t\t\t\t\tGrade: %s\n",add_results2[sub].grade);

                    printf("\n\t\t\t\t---------------------------------------------------------------\n");
                    sub++;
                }
            }fclose(cf);

            printf("\n\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                rf = fopen("results.txt","r");

                while(!feof(rf))
                {
                    fscanf(rf,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results.semester_name,read_results.program,read_results.shift,&read_results.intake,&read_results.sem_no,&read_results.stu_id,read_results.course,&read_results.midMark,&read_results.finalMark,&read_results.sirMark,&read_results.totalMark,&read_results.gradePoint,read_results.grade);
                    if(add_results.sem_no == read_results.sem_no && add_results.intake == read_results.intake && add_results.stu_id == read_results.stu_id)
                    {
                        rmatch = 1;  fclose(rf);  break;
                    }
                }
                if(rmatch == 0)
                {
                    fclose(rf);
                    rf = fopen("results.txt","a");
                    for(j=0; j<sub; j++)
                    {
                        fprintf(rf,"%s, %s %s %d %d %d %s, %.1f %.1f %.1f %.1f %.2f %s\n",add_results.semester_name,add_results.program,add_results.shift,add_results.intake,add_results.sem_no,add_results.stu_id,add_results2[j].course,add_results2[j].midMark,add_results2[j].finalMark,add_results2[j].sirMark,add_results2[j].totalMark,add_results2[j].gradePoint,add_results2[j].grade);
                    }fclose(rf);
                    for (j=0; j<70; j++)    {   printf("\b");   }
                    printf("\t\t\t\t\t******* Add Result Successful *******\n\n");

                }else
                {
                    for (j=0; j<70; j++)    {   printf("\b");   }
                    printf("\t\t\t\t\t!!!!!!! The Student Already Taken !!!!!!!\n\n");
                }

            }
            printf("\n\n\t\t\t\t\tDo You Add More Results in this Intake ? y / n : ");
            permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    add_results_title();
                printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
                printf("\t\t\t--------------------------------------------------------------------------------\n\n");
            }
            else
                break;
        }
    }fclose(sf);

    system("CLS");  title();    add_results_title();
    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t1. Add More Results in Another Intake\n\n");
    printf("\t\t\t\t\t2. Back to Results Menu\n\n");

    int select_menu;
    printf("\t\t\t\t\tPress the Number of Menu: ");
    scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:
            system("CLS");  title();    add_results_f();
            break;
        case 2:
            system("CLS");  title(); results();

        default:    printf("\t\t\t\t\tPress select the right menu");  break;
    }
}

void edit_results_f()
{
    struct re edit_results[100];
    struct cou_en read_course_enroll[100];
    char selectCoCode[10];
    int match = 0,rmatch,sub,fsize,m=0,n=0,selectEnroll,selectStuID;
    FILE *sf,*cf,*rf;

    edit_results_title();

    f = fopen("results.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",edit_results[m].semester_name,edit_results[m].program,edit_results[m].shift,&edit_results[m].intake,&edit_results[m].sem_no,&edit_results[m].stu_id,edit_results[m].course,&edit_results[m].midMark,&edit_results[m].finalMark,&edit_results[m].sirMark,&edit_results[m].totalMark,&edit_results[m].gradePoint,edit_results[m].grade);
        m++;
    }fclose(f);

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll[n].semester_name,read_course_enroll[n].program,read_course_enroll[n].shift,&read_course_enroll[n].intake,&read_course_enroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,read_course_enroll[i].semester_name,read_course_enroll[i].program,read_course_enroll[i].shift,read_course_enroll[i].intake,read_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }

    printf("\n\t\t\t\t\tSelect Enrolled To Edit Result: ");    scanf("%d",&selectEnroll);
    printf("\n\t\t\t\t\tEnter Student ID: ");   scanf("%d",&selectStuID);
    system("CLS"); title(); edit_results_title();
    printf("\n\t\t\t\t\tEnter Course CODE: ");  scanf(" %[A-Z 0-9]%*c",&selectCoCode);

    for(j=0; j<m; j++)
    {
        if(strcmp(edit_results[j].semester_name,read_course_enroll[selectEnroll-1].semester_name)==0 && strcmp(edit_results[j].program,read_course_enroll[selectEnroll-1].program)==0 && strcmp(edit_results[j].shift,read_course_enroll[selectEnroll-1].shift)==0 && edit_results[j].intake == read_course_enroll[selectEnroll-1].intake && edit_results[m].sem_no == read_course_enroll[n].semester_no && edit_results[j].stu_id == selectStuID && strcmp(edit_results[j].course,selectCoCode)==0)
        {
            match = 1;  break;
        }
    }

    if(match == 1)
    {
        system("CLS"); title(); edit_results_title();
        printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");

        printf("\t\t\t\t\t\t\tStudent ID : %d\n",selectStuID);
        printf("\t\t\t\t-----------------------------------------------------------------------\n");

        printf("\n\t\t\t\t\tCourse Code : %s\n",selectCoCode);
        printf("\n\t\t\t\t\tMid Mark: ");       scanf("%f",&edit_results[j].midMark);
        printf("\n\t\t\t\t\tFinal Mark: ");     scanf("%f",&edit_results[j].finalMark);
        printf("\n\t\t\t\t\tOut of 30: ");      scanf("%f",&edit_results[j].sirMark);
        edit_results[j].totalMark = edit_results[j].midMark + edit_results[j].finalMark + edit_results[j].sirMark;
        printf("\n\t\t\t\t\tTotal Mark: %.1f\n",edit_results[j].totalMark);
        if(edit_results[j].totalMark>=80 && edit_results[j].totalMark<=100)
        {
            edit_results[j].gradePoint = 4.00;
            strcpy(edit_results[j].grade,"A+");

        }else if(edit_results[j].totalMark>=75 && edit_results[j].totalMark<=79)
        {
            edit_results[j].gradePoint = 3.75;
            strcpy(edit_results[j].grade,"A");

        }else if(edit_results[j].totalMark>=70 && edit_results[j].totalMark<=74)
        {
            edit_results[j].gradePoint = 3.50;
            strcpy(edit_results[j].grade,"A-");

        }else if(edit_results[j].totalMark>=65 && edit_results[j].totalMark<=69)
        {
            edit_results[j].gradePoint = 3.25;
            strcpy(edit_results[j].grade,"B+");

        }else if(edit_results[j].totalMark>=60 && edit_results[j].totalMark<=64)
        {
            edit_results[j].gradePoint = 3.00;
            strcpy(edit_results[j].grade,"B");

        }else if(edit_results[j].totalMark>=55 && edit_results[j].totalMark<=59)
        {
            edit_results[j].gradePoint = 2.75;
            strcpy(edit_results[j].grade,"B-");

        }else if(edit_results[j].totalMark>=50 && edit_results[j].totalMark<=54)
        {
            edit_results[j].gradePoint = 2.50;
            strcpy(edit_results[j].grade,"C+");

        }else if(edit_results[j].totalMark>=45 && edit_results[j].totalMark<=49)
        {
            edit_results[j].gradePoint = 2.25;
            strcpy(edit_results[j].grade,"C");

        }else if(edit_results[j].totalMark>=40 && edit_results[j].totalMark<=44)
        {
            edit_results[j].gradePoint = 2.00;
            strcpy(edit_results[j].grade,"D");
        }
        else
        {
            edit_results[j].gradePoint = 0.00;
            strcpy(edit_results[j].grade,"F");
        }
        printf("\n\t\t\t\t\tGrade Point: %.2f\n",edit_results[j].gradePoint);
        printf("\n\t\t\t\t\tGrade: %s\n",edit_results[j].grade);

        printf("\n\t\t\t\t-----------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();
        if(permission == 'Y' || permission == 'y')
        {
            rf = fopen("results.txt","w");

            for(j=0; j<m; j++)
                fprintf(rf,"%s, %s %s %d %d %d %s, %.1f %.1f %.1f %.1f %.2f %s\n",edit_results[j].semester_name,edit_results[j].program,edit_results[j].shift,edit_results[j].intake,edit_results[j].sem_no,edit_results[j].stu_id,edit_results[j].course,edit_results[j].midMark,edit_results[j].finalMark,edit_results[j].sirMark,edit_results[j].totalMark,edit_results[j].gradePoint,edit_results[j].grade);

            fclose(rf);

            for (j=0; j<70; j++)    {   printf("\b");   }
            printf("\t\t\t\t\t******* Update Result Successful *******\n\n");
            printf("\t\t\t\t\tDo You Edit Another Result ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_results_f();
            }else
            {
                system("CLS");  title(); results();
            }
        }else
        {
            system("CLS");  title(); results();
        }

    }else
    {
        fclose(f);
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!!!!!! The Info Is Not Matched !!!!!!!\n\n");
        printf("\t\t\t\t\tDo You Search Another ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {

            system("CLS");  title();    edit_results_f();

        }else
        {
            system("CLS");  title(); results();
        }

    }
}

void view_results_f()
{
    struct pro read_program[100];
    struct re read_results[100];
    struct cou_en read_course_enroll[100];
    struct stu read_student;
    struct cou read_course;
    int match,n = 0,p = 0,selectShift,selectIntake,intake = 0,semNo,countCGPA,countSGPA,c,selectID,selectMenu,programMatch,selectEnroll;
    char shift[10],selectSemester[15];
    float sumofCGP,sumofSGP,CGPA,SGPA;

    view_results_title();

    f = fopen("results.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results[n].semester_name,read_results[n].program,read_results[n].shift,&read_results[n].intake,&read_results[n].sem_no,&read_results[n].stu_id,read_results[n].course,&read_results[n].midMark,&read_results[n].finalMark,&read_results[n].sirMark,&read_results[n].totalMark,&read_results[n].gradePoint,read_results[n].grade);
        n++;
    }fclose(f);

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll[p].semester_name,read_course_enroll[p].program,read_course_enroll[p].shift,&read_course_enroll[p].intake,&read_course_enroll[p].semester_no);
        p++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<p; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,read_course_enroll[i].semester_name,read_course_enroll[i].program,read_course_enroll[i].shift,read_course_enroll[i].intake,read_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To View Result: ");  scanf("%d",&selectEnroll);
    system("CLS"); title(); view_results_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    c = 1;
    printf("\t\t\tStu ID\t|  CGPA  |  SGPA  ");
    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
        if(strcmp(read_course.program,read_course_enroll[selectEnroll-1].program)==0 && read_course.semester == read_course_enroll[selectEnroll-1].semester_no)
        {
            printf("| Subject %d\t",c);
            c++;
        }
    }fclose(f);

    printf("\n\t\t\t---------------------------------------------------------------------------------------------\n\n");

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        sumofCGP = 0,sumofSGP = 0, countSGPA = 0,countCGPA = 0,match = 0;

        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(strcmp(read_course_enroll[selectEnroll-1].program,read_student.program)==0 && strcmp(read_course_enroll[selectEnroll-1].shift,read_student.shift)==0 && read_course_enroll[selectEnroll-1].intake == read_student.intake)
        {
            for(i=0; i<n; i++)
            {
                if(read_student.id == read_results[i].stu_id)
                {
                    match = 1;
                    sumofSGP += read_results[i].gradePoint;
                    countCGPA++;

                    if(strcmp(read_course_enroll[selectEnroll-1].semester_name,read_results[i].semester_name) == 0)
                    {
                        sumofCGP += read_results[i].gradePoint;
                        countSGPA++;
                    }
                }
            }
            if(match == 1)
            {
                CGPA = sumofCGP / countCGPA;
                SGPA = sumofSGP / countSGPA;

                printf("\t\t\t%d\t|  %.2f  |  %.2f  ",read_student.id,CGPA,SGPA);
                for(i=0; i<n; i++)
                {
                    if(strcmp(read_course_enroll[selectEnroll-1].semester_name,read_results[i].semester_name) == 0 && read_student.id == read_results[i].stu_id)
                    {
                        match = 1;
                        printf("| %s(%s)\t",read_results[i].course,read_results[i].grade);
                    }
                }printf("\n\t\t\t---------------------------------------------------------------------------------------------\n\n");
            }
        }
    }fclose(f);

    printf("\t\t\t\t\tDo You View Another Result ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        system("CLS");  title();    view_results_f();
    }else
    {
        system("CLS");  title(); results();
    }

}

void view_marksheet_f ()
{
    struct pro read_program[100];
    struct re read_results[100];
    struct cou_en read_course_enroll[100];
    struct stu read_student;
    struct cou read_course;
    int match,n = 0,p = 0,selectShift,selectIntake,intake = 0,semNo,countCGPA,countSGPA,c,selectID,selectMenu,programMatch,studentMatch,selectEnroll;
    char shift[10],selectSemester[15];
    float sumofCGP,sumofSGP,CGPA,SGPA;

    view_marksheet_title();

    f = fopen("results.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %[^,], %f %f %f %f %f %s\n",read_results[n].semester_name,read_results[n].program,read_results[n].shift,&read_results[n].intake,&read_results[n].sem_no,&read_results[n].stu_id,read_results[n].course,&read_results[n].midMark,&read_results[n].finalMark,&read_results[n].sirMark,&read_results[n].totalMark,&read_results[n].gradePoint,read_results[n].grade);
        n++;
    }fclose(f);

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll[p].semester_name,read_course_enroll[p].program,read_course_enroll[p].shift,&read_course_enroll[p].intake,&read_course_enroll[p].semester_no);
        p++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<p; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,read_course_enroll[i].semester_name,read_course_enroll[i].program,read_course_enroll[i].shift,read_course_enroll[i].intake,read_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To View Result: ");  scanf("%d",&selectEnroll);
    printf("\n\t\t\t\t\tEnter Student ID : ");  scanf("%d",&selectID);
    system("CLS"); title(); view_marksheet_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\tMark Sheet of Student ID : %d\n",selectID);
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    printf("\t\t\tCourse Code | Mid Mark | Final Mark | Out of 30 | Total Mark | Grad Point | Grade\n");
    printf("\t\t\t-------------------------------------------------------------------------------------------------\n\n");

    studentMatch = 0;
    for(i=0; i<n; i++)
    {
        if(strcmp(read_course_enroll[selectEnroll-1].semester_name,read_results[i].semester_name) == 0 && strcmp(read_course_enroll[selectEnroll-1].program,read_results[i].program)==0 && strcmp(read_course_enroll[selectEnroll-1].shift,read_results[i].shift)==0 && read_course_enroll[selectEnroll-1].intake == read_results[i].intake && selectID == read_results[i].stu_id)
        {
            studentMatch = 1;
            printf("\t\t\t%s     |   %.1f   |   %.1f     |   %.1f    |   %.1f     |   %.2f     |   %s\n",read_results[i].course,read_results[i].midMark,read_results[i].finalMark,read_results[i].sirMark,read_results[i].totalMark,read_results[i].gradePoint,read_results[i].grade);
            printf("\t\t\t-------------------------------------------------------------------------------------------------\n\n");
        }
    }
    if(studentMatch == 0)
    {
        printf("\t\t\t\t\t!!! Empty Marksheet of the Student !!!\n\n");
        printf("\t\t\t-------------------------------------------------------------------------------------------------\n\n");
    }

    printf("\t\t\t\t\tDo You View Marksheet ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        system("CLS");  title();    view_marksheet_f();
    }else
    {
        system("CLS");  title(); results();
    }
}

#endif // RESULTS_H_INCLUDED
