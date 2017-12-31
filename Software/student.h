#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

void student ()
{
    printf("\t\t\t\t1.Add Student | 2.View Student | 3.Edit Student | 4.Delete Student\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    5.Main Menu | 6.Exit\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_student_f();      break;

        case 2:     system("CLS");  title();  view_student_f();     break;

        case 3:     system("CLS");  title();  edit_student_f();     break;

        case 4:     system("CLS");  title();  delete_student_f();   break;

        case 5:     system("CLS");  title();  admin_main_menu();    break;

        case 6:     break;

        default:    printf("\t\t\t\t\tPress select the right menu");  break;
    }
    exit(0);
}

void add_student_title()
{
    printf("\t\t\t\t\t\t    Add Student Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void edit_student_title()
{
    printf("\t\t\t\t\t\t    Edit Student Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void view_student_title()
{
    printf("\t\t\t\t\t\t    View All Student Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}

void add_student_f ()
{
    struct stu add_student;
    struct stu read_student;
    struct pro read_program[100];
    int match = 0,p = 0,selectProgram;

    add_student_title();

    printf("\t\t\t\t\tSemester Name: ");   scanf(" %[^\n]",&add_student.semester);
    system("CLS"); title(); add_student_title();

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

    printf("\n\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
    strcpy(add_student.program,read_program[selectProgram-1].code);

    system("CLS"); title(); add_student_title();

    printf("\t\t\t\t\tSemester: %s\n",add_student.semester);
    printf("\n\t\t\t\t\tProgram: %s\n",add_student.program);
    printf("\n\t\t\t\t\tStudent Name: ");   scanf(" %[^\n]",&add_student.name);
    printf("\n\t\t\t\t\tShift: ");           scanf(" %s",&add_student.shift);
    printf("\n\t\t\t\t\tIntake: ");         scanf("%d",&add_student.intake);
    printf("\n\t\t\t\t\tSection: ");        scanf("%d",&add_student.section);
    printf("\n\t\t\t\t\tID: ");             scanf("%d",&add_student.id);

    printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        f = fopen("student.txt","r");
        while(!feof(f))
        {
            fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
            if(add_student.id == read_student.id)
            {
                match = 1;  fclose(f);  break;
            }
        }fclose(f);

        if(match == 0)
        {
            f = fopen("student.txt","a");
            fprintf(f,"%d %s, %d %d %s %s %s\n",add_student.id,add_student.name,add_student.section,add_student.intake,add_student.shift,add_student.program,add_student.semester);
            fclose(f);

            for (i=0; i<122; i++)   {   printf("\r");   }
            printf("\t\t\t\t\t******* Student Add Successful *******\n\n");
            printf("\t\t\t\t\tDo You Add More Student ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {

                system("CLS");  title();    add_student_f();

            }else
            {
                system("CLS");  title(); student();
            }

        }else
        {
            for (i=0; i<122; i++)   {  printf("\r");   }
            printf("\t\t\t\t\t!!!!!!! The Student Already Taken !!!!!!!\n\n");
            printf("\t\t\t\t\tDo You Add Another Student ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {

                system("CLS");  title();    add_student_f();

            }else
            {
                system("CLS");  title(); student();
            }

        }

    }else
    {
        system("CLS");  title();    student();
    }
}

void edit_student_f()
{
    struct stu edit_student[100];
    struct pro read_program[100];
    int match = 0,n = 0,p = 0,selectProgram;

    edit_student_title();

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&edit_student[n].id,edit_student[n].name,&edit_student[n].section,&edit_student[n].intake,edit_student[n].shift,edit_student[n].program,edit_student[n].semester);
        n++;
    }fclose(f);

    printf("\t\t\t\t\tEnter Student ID : ");   scanf(" %d",&selectID);

    for(j=0; j<n; j++)
    {
        if(selectID == edit_student[j].id)
        {
            match = 1;  break;
        }
    }
    if(match == 1)
    {
        system("CLS"); title(); edit_student_title();
        printf("\t\t\t\t\tSemester Name: ");   scanf(" %[^\n]",&edit_student[j].semester);
        system("CLS"); title(); edit_student_title();

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

        printf("\n\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
        strcpy(edit_student[j].program,read_program[selectProgram-1].code);
        system("CLS"); title(); edit_student_title();

        printf("\t\t\t\t\tSemester: %s\n",edit_student[j].semester);
        printf("\n\t\t\t\t\tProgram: %s\n",edit_student[j].program);
        printf("\n\t\t\t\t\tStudent Name: ");   scanf(" %[^\n]",&edit_student[j].name);
        printf("\n\t\t\t\t\tSift: ");           scanf(" %s",&edit_student[j].shift);
        printf("\n\t\t\t\t\tIntake: ");         scanf("%d",&edit_student[j].intake);
        printf("\n\t\t\t\t\tSection: ");        scanf("%d",&edit_student[j].section);
        printf("\n\t\t\t\t\tID: ");             scanf("%d",&edit_student[j].id);

        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Update ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("student.txt","w");
            for(j=0; j<n-1; j++)
            {
               fprintf(f,"%d %s, %d %d %s %s %s\n",edit_student[j].id,edit_student[j].name,edit_student[j].section,edit_student[j].intake,edit_student[j].shift,edit_student[j].program,edit_student[j].semester);
            }fclose(f);

            for (k=0; k<70; k++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Student Update Successful *******\n\n");
            printf("\t\t\t\t\tDo You Edit Another Student ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_student_f();
            }else
            {
                system("CLS");  title(); view_student_f();
            }
        }else
        {
            system("CLS");  title(); student();
        }
    }
    else
    {
        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!!!!!! Incorrect ID !!!!!!!\n\n");
        printf("\t\t\t\t\tDo You Edit Another Student ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    edit_student_f();
        }else
        {
            system("CLS");  title(); student();
        }
    }
}

void delete_student_f()
{
    struct stu delete_student[100];
    int n = 0, match = 0;

    printf("\t\t\t\t\t\t    Delete Student Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&delete_student[n].id,delete_student[n].name,&delete_student[n].section,&delete_student[n].intake,delete_student[n].shift,delete_student[n].program,delete_student[n].semester);
        n++;
    }fclose(f);

    printf("\t\t\t\t\tEnter Student ID : ");   scanf(" %d",&selectID);

    for(i=0; i<n-1; i++)
    {
        if(selectID == delete_student[i].id)
        {
            for(j=i; j<n-2; j++)
            {
                strcpy(delete_student[j].semester,delete_student[j+1].semester);
                strcpy(delete_student[j].program,delete_student[j+1].program);
                strcpy(delete_student[j].shift,delete_student[j+1].shift);
                strcpy(delete_student[j].name,delete_student[j+1].name);
                delete_student[j].intake = delete_student[j+1].intake;
                delete_student[j].section = delete_student[j+1].section;
                delete_student[j].id = delete_student[j+1].id;
            }
            match = 1;  break;
        }
    }
    if(match == 1)
    {
        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Delete ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("student.txt","w");
            for(i=0; i<n-2; i++)
            {
                fprintf(f,"%d %s, %d %d %s %s %s\n",delete_student[i].id,delete_student[i].name,delete_student[i].section,delete_student[i].intake,delete_student[i].shift,delete_student[i].program,delete_student[i].semester);
            }fclose(f);

            for (j=0; j<70; j++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Student Delete Successful *******\n\n");
            printf("\t\t\t\t\tDo You Delete Another Student ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    delete_student_f();
            }else
            {
                system("CLS");  title(); view_student_f();
            }
        }
        else
        {
            system("CLS");  title(); student();
        }
    }
    else
    {
        printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!!!!!! Incorrect ID !!!!!!!\n\n");
        printf("\t\t\t\t\tDo You Delete Another Course ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    delete_student_f();
        }else
        {
            system("CLS");  title(); view_student_f();
        }
    }
}

void view_student_f()
{
    struct stu view_student[100];
    struct pro read_program[100];
    int n = 0,p = 0,programMatch,selectShift,selectIntake,intake = 0,selectMenu;
    char shift[10];

    view_student_title();

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&view_student[n].id,view_student[n].name,&view_student[n].section,&view_student[n].intake,view_student[n].shift,view_student[n].program,view_student[n].semester);
        n++;
    }fclose(f);

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",read_program[p].code,read_program[p].name);
        p++;
    }fclose(f);

    backProgram:
    for(i=0; i<p-1; i++)
    {
        printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);
    }
    printf("\n\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
    system("CLS"); title(); view_student_title();

    backShift:
    printf("\t\t\t\t\t\t1.Day\t\t2.Evening\n\n");
    printf("\n\t\t\t\t\t\tSelect Shift: ");  scanf("%d",&selectShift);
    if(selectShift == 1)
        strcpy(shift,"Day");
    else
        strcpy(shift,"Evening");
    system("CLS"); title(); view_student_title();

    backIntake:
    printf("\t\t\t\t\tAvailable Intake Are : ");
    programMatch = 0;
    for(i=0; i<n-1; i++)
    {
        if(strcmp(read_program[selectProgram-1].code,view_student[i].program)==0 && strcmp(shift,view_student[i].shift)==0)
        {
           programMatch = 1;
           if(intake != view_student[i].intake)
            {
                intake = view_student[i].intake;
                printf("%d ",intake);
            }
        }
    }
    if(programMatch == 0)
    {
        system("CLS"); title(); view_student_title();
        printf("\t\t\t\t\t!!! Empty Intake in this Program !!!\n\n");
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");

    }
    else
    {
        printf("\n\n\t\t\t\t\tEnter Intake: "); scanf("%d",&selectIntake);
        system("CLS"); title(); view_student_title();

        for(i=0; i<n-1; i++)
        {
            if(strcmp(read_program[selectProgram-1].code,view_student[i].program)==0 && strcmp(shift,view_student[i].shift)==0 && selectIntake == view_student[i].intake)
            {
                printf("\t\t\t\t\tSESSION\t:\t%s\n\n",view_student[i].semester);
                printf("\t\t\t\t\tPROGRAM\t:\t%s\n\n",view_student[i].program);
                printf("\t\t\t\t\tSHIFT\t:\t%s\n\n",view_student[i].shift);
                printf("\t\t\t\t\tINTAKE\t:\t%d\n",view_student[i].intake);
                break;
            }
        }
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");

        for(i=0; i<n-1; i++)
        {
            if(strcmp(read_program[selectProgram-1].code,view_student[i].program)==0 && strcmp(shift,view_student[i].shift)==0 && selectIntake == view_student[i].intake)
            {
                printf("\t\t\t\t\tSECTION : %d -> ID : %d -> NAME : %s\n",view_student[i].section,view_student[i].id,view_student[i].name);
                printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
            }
        }
    }

    printf("\t\t\t\t\t1. View Another Intake\n\n");
    printf("\t\t\t\t\t2. View Another Shift\n\n");
    printf("\t\t\t\t\t3. View Another Program\n\n");
    printf("\t\t\t\t\t4. Go To Menu\n\n\n");
    printf("\t\t\t\t\tSelect Menu : "); scanf("%d",&selectMenu);

    if(selectMenu == 1)
    {
        system("CLS"); title(); view_payment_title();
        goto backIntake;
    }
    else if(selectMenu == 2)
    {
        system("CLS"); title(); view_payment_title();
        goto backShift;
    }
    else if(selectMenu == 3)
    {
        system("CLS"); title(); view_payment_title();
        goto backProgram;
    }
    else
        system("CLS"); title(); student();
}

#endif // STUDENT_H_INCLUDED
