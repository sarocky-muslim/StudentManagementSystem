#ifndef COURSE_ENROLL_H_INCLUDED
#define COURSE_ENROLL_H_INCLUDED


void course_enroll ()
{
    printf("\t\t\t\t1.Add Enroll | 2.View Enrolled | 3.Edit Enroll | 4.Delete Enroll\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    5.Main Menu | 6.Exit\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n\n");


    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_course_enroll_f();    break;

        case 2:     system("CLS");  title();  view_course_enroll_f();   break;

        case 3:     system("CLS");  title();  edit_course_enroll_f();   break;

        case 4:     system("CLS");  title();  delete_course_enroll_f(); break;

        case 5:     system("CLS");  title();  admin_main_menu();        break;

        case 6:     break;

        default:    printf("\t\t\t\t\tPress select the right menu");  break;
    }
    exit(0);
}

void add_course_enroll_title()
{
    printf("\t\t\t\t\t\t    Add Course Enroll\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void view_course_enroll_title()
{
    printf("\t\t\t\t\t\t    View Enrolled Course\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void edit_course_enroll_title()
{
    printf("\t\t\t\t\t\t    Edit Enrolled Course\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}

void add_course_enroll_f()
{
    struct cou_en add_course_enroll;
    struct cou_en read_course_enroll;
    struct stu read_student;
    struct pro read_program[100];
    int match = 0,p = 0,programMatch,selectShift;

    add_course_enroll_title();

    printf("\t\t\t\t\tSemester Name: "); scanf(" %[A-Z a-z 0-9]",&add_course_enroll.semester_name);
    system("CLS"); title(); add_course_enroll_title();

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",read_program[p].code,read_program[p].name);
        p++;
    }fclose(f);

    for(i=0; i<p-1; i++)
    {
        printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);
    }
    printf("\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
    strcpy(add_course_enroll.program,read_program[selectProgram-1].code);
    system("CLS"); title(); add_course_enroll_title();

    printf("\t\t\t\t\t\t1.Day\t\t2.Evening\n\n");
    printf("\n\t\t\t\t\t\tSelect Shift: ");  scanf("%d",&selectShift);
    if(selectShift == 1)
        strcpy(add_course_enroll.shift,"Day");
    else
        strcpy(add_course_enroll.shift,"Evening");
    system("CLS"); title(); add_course_enroll_title();

    printf("\t\t\t\t\tAvailable Intake Are : ");
    programMatch = 0;
    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(strcmp(add_course_enroll.program,read_student.program)==0 && strcmp(add_course_enroll.shift,read_student.shift)==0)
        {
            programMatch = 1;
            if(add_course_enroll.intake != read_student.intake)
            {
                add_course_enroll.intake = read_student.intake;
                printf("%d ",add_course_enroll.intake);
            }
        }
    }fclose(f);

    if(programMatch == 0)
    {
        system("CLS"); title(); add_course_enroll_title();
        printf("\t\t\t\t\t!!! Empty Intake in this Program !!!\n\n");
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Add Another Enroll ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    add_course_enroll_f();
        }else
        {
            system("CLS");  title(); course_enroll();
        }

    }
    else
    {
        printf("\n\n\t\t\t\t\tSelect Intake: ");      scanf(" %d",&add_course_enroll.intake);
        system("CLS"); title(); add_course_enroll_title();
        printf("\t\t\t\t\tSemester Name: %s\n",add_course_enroll.semester_name);
        printf("\n\t\t\t\t\tProgram: %s\n",add_course_enroll.program);
        printf("\n\t\t\t\t\tShift: %s\n",add_course_enroll.shift);
        printf("\n\t\t\t\t\tIntake: %d\n",add_course_enroll.intake);
        printf("\n\t\t\t\t\tSemester No: "); scanf(" %d",&add_course_enroll.semester_no);


        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("course_enroll.txt","r");
            while(!feof(f))
            {
                fscanf(f,"%[^,], %s %s %d %d\n",read_course_enroll.semester_name,read_course_enroll.program,read_course_enroll.shift,&read_course_enroll.intake,&read_course_enroll.semester_no);
                if(strcmp(add_course_enroll.semester_name,read_course_enroll.semester_name)==0 && strcmp(add_course_enroll.program,read_course_enroll.program)==0 && strcmp(add_course_enroll.shift,read_course_enroll.shift)==0 && add_course_enroll.intake == read_course_enroll.intake)
                {
                    match = 1;  fclose(f);  break;
                }
            }fclose(f);

            if(match == 0)
            {
                f = fopen("course_enroll.txt","a");
                fprintf(f,"%s, %s %s %d %d\n",add_course_enroll.semester_name,add_course_enroll.program,add_course_enroll.shift,add_course_enroll.intake,add_course_enroll.semester_no);
                fclose(f);

                for (i=0; i<122; i++)   {   printf("\r");   }
                printf("\t\t\t\t\t******* Add Course Enroll Successful *******\n\n");
                printf("\t\t\t\t\tDo You Add More Enroll ? Y / N : "); permission = getch();

                if(permission == 'Y' || permission == 'y')
                {
                    system("CLS");  title();    add_course_enroll_f();
                }else
                {
                    system("CLS");  title(); course_enroll();
                }

            }else
            {
                for (i=0; i<122; i++)   {  printf("\r");   }
                printf("\t\t\t\t\t!!!!!!! The Intake Already Enrolled !!!!!!!\n\n");
                printf("\t\t\t\t\tDo You Enroll Another Intake ? Y / N : "); permission = getch();

                if(permission == 'Y' || permission == 'y')
                {
                    system("CLS");  title();    add_course_enroll_f();
                }else
                {
                    system("CLS");  title(); course_enroll();
                }

            }

        }else
        {
            system("CLS");  title();    course_enroll();
        }
    }
}

void edit_course_enroll_f()
{
    struct cou_en edit_course_enroll[100];
    struct cou view_course;
    struct stu read_student;
    struct pro read_program[100];
    int match = 0,p = 0;
    int n = 0,selectEnroll,programMatch,selectShift,intake=0;

    edit_course_enroll_title();

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",edit_course_enroll[n].semester_name,edit_course_enroll[n].program,edit_course_enroll[n].shift,&edit_course_enroll[n].intake,&edit_course_enroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,edit_course_enroll[i].semester_name,edit_course_enroll[i].program,edit_course_enroll[i].shift,edit_course_enroll[i].intake,edit_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To Edit: ");  scanf("%d",&selectEnroll);
    system("CLS"); title(); edit_course_enroll_title();

    printf("\t\t\t\t\tSemester Name: "); scanf(" %[A-Z a-z 0-9]",&edit_course_enroll[selectEnroll-1].semester_name);
    system("CLS"); title(); edit_course_enroll_title();

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",read_program[p].code,read_program[p].name);
        p++;
    }fclose(f);

    for(i=0; i<p-1; i++)
    {
        printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);
    }
    printf("\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
    strcpy(edit_course_enroll[selectEnroll-1].program,read_program[selectProgram-1].code);
    system("CLS"); title(); edit_course_enroll_title();

    printf("\t\t\t\t\t\t1.Day\t\t2.Evening\n\n");
    printf("\n\t\t\t\t\t\tSelect Shift: ");  scanf("%d",&selectShift);
    if(selectShift == 1)
        strcpy(edit_course_enroll[selectEnroll-1].shift,"Day");
    else
        strcpy(edit_course_enroll[selectEnroll-1].shift,"Evening");
    system("CLS"); title(); edit_course_enroll_title();

    printf("\t\t\t\t\tAvailable Intake Are : ");
    programMatch = 0;

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(strcmp(edit_course_enroll[selectEnroll-1].program,read_student.program)==0 && strcmp(edit_course_enroll[selectEnroll-1].shift,read_student.shift)==0)
        {
            programMatch = 1;
            if(intake != read_student.intake)
            {
                intake = read_student.intake;
                printf("%d ",read_student.intake);
            }
        }
    }fclose(f);

    if(programMatch == 0)
    {
        system("CLS"); title(); edit_course_enroll_title();
        printf("\t\t\t\t\t!!! Empty Intake in this Program !!!\n\n");
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Edit Another Enroll ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    edit_course_enroll_f();
        }else
        {
            system("CLS");  title(); course_enroll();
        }
    }
    else
    {
        printf("\n\n\t\t\t\t\tSelect Intake: ");      scanf(" %d",&edit_course_enroll[selectEnroll-1].intake);
        system("CLS"); title(); edit_course_enroll_title();

        printf("\t\t\t\t\tSemester Name: %s\n",edit_course_enroll[selectEnroll-1].semester_name);
        printf("\n\t\t\t\t\tProgram: %s\n",edit_course_enroll[selectEnroll-1].program);
        printf("\n\t\t\t\t\tShift: %s\n",edit_course_enroll[selectEnroll-1].shift);
        printf("\n\t\t\t\t\tIntake: %d\n",edit_course_enroll[selectEnroll-1].intake);
        printf("\n\t\t\t\t\tSemester No: "); scanf(" %d",&edit_course_enroll[selectEnroll-1].semester_no);


        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Update ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("course_enroll.txt","w");
            for(i=0; i<n; i++)
                fprintf(f,"%s, %s %s %d %d\n",edit_course_enroll[i].semester_name,edit_course_enroll[i].program,edit_course_enroll[i].shift,edit_course_enroll[i].intake,edit_course_enroll[i].semester_no);
            fclose(f);

            for (i=0; i<122; i++)   {   printf("\r");   }
            printf("\t\t\t\t\t******* Update Course Enroll Successful *******\n\n");
            printf("\t\t\t\t\tDo You Update More Enroll ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_course_enroll_f();
            }else
            {
                system("CLS");  title(); course_enroll();
            }

        }else
        {
            system("CLS");  title();    course_enroll();
        }
    }
}

void delete_course_enroll_f()
{
    printf("\t\t\t\t\t\t    Delete Enrolled Course\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

    struct cou_en delete_course_enroll[100];
    int n = 0,selectEnroll;

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",delete_course_enroll[n].semester_name,delete_course_enroll[n].program,delete_course_enroll[n].shift,&delete_course_enroll[n].intake,&delete_course_enroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,delete_course_enroll[i].semester_name,delete_course_enroll[i].program,delete_course_enroll[i].shift,delete_course_enroll[i].intake,delete_course_enroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }

    printf("\n\t\t\t\t\tSelect Enrolled To Delete: ");  scanf("%d",&selectEnroll);

    for(j=selectEnroll-1; j<n-1; j++)
    {
        strcpy(delete_course_enroll[j].semester_name,delete_course_enroll[j+1].semester_name);
        strcpy(delete_course_enroll[j].program,delete_course_enroll[j+1].program);
        strcpy(delete_course_enroll[j].shift,delete_course_enroll[j+1].shift);
        delete_course_enroll[j].intake = delete_course_enroll[j+1].intake;
        delete_course_enroll[j].semester_no = delete_course_enroll[j+1].semester_no;
    }

    printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tDo You Want To Delete ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        f = fopen("course_enroll.txt","w");
        for(i=0; i<n-1; i++)
            fprintf(f,"%s, %s %s %d %d\n",delete_course_enroll[i].semester_name,delete_course_enroll[i].program,delete_course_enroll[i].shift,delete_course_enroll[i].intake,delete_course_enroll[i].semester_no);
        fclose(f);

        for (j=0; j<70; j++)   {   printf("\b");   }
        printf("\t\t\t\t\t******* Enroll Delete Successful *******\n\n");
        printf("\t\t\t\t\tDo You Delete Another Enroll ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    delete_course_enroll_f();
        }else
        {
            system("CLS");  title(); course_enroll();
        }
    }
    else
    {
        for (j=0; j<70; j++)   {   printf("\b");   }
        printf("\t\t\t\t\tDo You Delete Another Enroll ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    delete_course_enroll_f();
        }else
        {
            system("CLS");  title(); course_enroll();
        }
    }
}

void view_course_enroll_f ()
{
    struct cou_en view_course_enroll;
    struct cou_en read_course_enroll[100];
    struct cou view_course;
    int n = 0,selectEnroll;

    view_course_enroll_title();

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
    printf("\n\t\t\t\t\tSelect Enrolled To View Course: ");  scanf("%d",&selectEnroll);
    view_course_enroll.semester_no = read_course_enroll[selectEnroll-1].semester_no;
    system("CLS"); title(); view_course_enroll_title();

    printf("\t\t\tSEM NO   | COURSE CODE  | CREDIT  |   TYPE\t|  COURSE TITLE\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",view_course.program,&view_course.semester,view_course.code,view_course.title,&view_course.credit,view_course.type);
        if(strcmp(read_course_enroll[selectEnroll-1].program,view_course.program)==0 && view_course_enroll.semester_no == view_course.semester)
        {
            printf("\t\t\t   %d\t |   %s\t|   %.1f\t  |   %s   \t| %s",view_course.semester,view_course.code,view_course.credit,view_course.type,view_course.title);
            printf("\n\t\t\t---------------------------------------------------------------------------------------------\n\n");
        }
    }
    fclose(f);

    printf("\n\t\t\t\t\tDo You View Another Enrolled ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {

        system("CLS");  title();    view_course_enroll_f();

    }else
    {
        system("CLS");  title(); course_enroll();
    }

}

#endif // COURSE_ENROLL_H_INCLUDED
