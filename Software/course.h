#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED


void course ()
{
    printf("\t\t\t\t1.Add Course | 2.View course | 3.Edit course | 4.Delete course\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    5.Main Menu | 6.Exit\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_course_f();  break;

        case 2:     system("CLS");  title();  view_course_f();  break;

        case 3:     system("CLS");  title();  edit_course_f();  break;

        case 4:     system("CLS");  title();  delete_course_f();  break;

        case 5:     system("CLS");  title();  admin_main_menu();  break;

        case 6:     break;

        default:
            printf("\n\t\t\t\t\t!!! You Press Wrong Menu !!! Tray Again Y / N :");
            permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title(); course();
            }
            break;
    }
    exit(0);
}

void add_course_title()
{
    printf("\t\t\t\t\t\t    Add Course Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void edit_course_title()
{
    printf("\t\t\t\t\t\t    Edit Course Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void view_course_title()
{
    printf("\t\t\t\t\t\t    View All Course Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}
void delete_course_title()
{
    printf("\t\t\t\t\t\t    Delete Course Info\n");
    printf("\t\t\t\t------------------------------------------------------------------\n\n");
}

void add_course_f ()
{
    struct cou add_course;
    struct cou read_course;
    struct pro read_program[100];
    int match = 0,p = 0;

    add_course_title();

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

    printf("\n\t\t\t\t\tSelect Program : ");  scanf("%d",&selectProgram);
    strcpy(add_course.program,read_program[selectProgram-1].code);

    system("CLS"); title(); add_course_title();
    printf("\t\t\t\t\tProgram: %s\n",add_course.program);
    printf("\n\t\t\t\t\tSemester No: ");       scanf(" %d",&add_course.semester);
    printf("\n\t\t\t\t\tCourse Code: ");    scanf(" %[A-Z 0-9]%*c",&add_course.code);
    printf("\n\t\t\t\t\tCourse Title: ");   scanf("%[^\n]",&add_course.title);
    printf("\n\t\t\t\t\tCredit: ");         scanf("%f",&add_course.credit);
    printf("\n\t\t\t\t\tType: ");           scanf("%s",&add_course.type);

    printf("\n\t\t\t\t------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        f = fopen("course.txt","r");
        while(!feof(f))
        {
            fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
            if(strcmp(add_course.program,read_course.program)==0 && strcmp(add_course.code,read_course.code)==0)
            {
                match = 1;  fclose(f);  break;
            }
        }fclose(f);

        if(match == 0)
        {
            f = fopen("course.txt","a");
            fprintf(f,"%s %d %s, %s, %.2f %s\n",add_course.program,add_course.semester,add_course.code,add_course.title,add_course.credit,add_course.type);
            fclose(f);

            for (i=0; i<122; i++)   {   printf("\r");   }
            printf("\t\t\t\t\t******* Course Add Successful *******\n\n");
            printf("\t\t\t\t\tDo You Add More Course ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    add_course_f();
            }else
            {
                system("CLS");  title(); course();
            }

        }else
        {
            for (i=0; i<122; i++)   {  printf("\r");   }
            printf("\t\t\t\t\t!!!!!!! The Course Already Taken !!!!!!!\n\n");
            printf("\t\t\t\t\tDo You Add Another Course ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {

                system("CLS");  title();    add_course_f();

            }else
            {
                system("CLS");  title(); course();
            }

        }

    }else
    {
        system("CLS");  title();    course();
    }
}
void edit_course_f ()
{
    struct cou edit_course[100];
    struct pro read_program[100];
    char select_code[20];
    int match = 0,n = 0,p = 0;

    edit_course_title();

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",edit_course[n].program,&edit_course[n].semester,edit_course[n].code,edit_course[n].title,&edit_course[n].credit,edit_course[n].type);
        n++;
    }
    fclose(f);

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",read_program[p].code,read_program[p].name);
        p++;
    }fclose(f);

    for(i=0; i<p-1; i++)
        printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);

    printf("\n\t\t\t\t\tSelect Program : ");  scanf("%d",&selectProgram);
    system("CLS"); title(); edit_course_title();
    printf("\t\t\t\t\tEnter Course CODE : ");   scanf(" %[A-Z 0-9]%*c",&select_code);

    for(j=0; j<n; j++)
    {
        if(strcmp(read_program[selectProgram-1].code,edit_course[j].program)==0 && strcmp(select_code,edit_course[j].code)==0)
        {
            match = 1; break;
        }
    }
    if(match == 1)
    {
        system("CLS"); title(); edit_course_title();

        for(i=0; i<p-1; i++)
        {
            printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);
        }

        printf("\n\t\t\t\t\tSelect Program: ");  scanf("%d",&selectProgram);
        strcpy(edit_course[j].program,read_program[selectProgram-1].code);

        system("CLS"); title(); edit_course_title();
        printf("\t\t\t\t\tProgram: %s\n",edit_course[j].program);
        printf("\n\t\t\t\t\tSemester: ");       scanf(" %d",&edit_course[j].semester);
        printf("\n\t\t\t\t\tCourse Code: ");    scanf(" %[A-Z 0-9]%*c",&edit_course[j].code);
        printf("\n\t\t\t\t\tCourse Title: ");   scanf("%[^\n]",&edit_course[j].title);
        printf("\n\t\t\t\t\tCredit: ");         scanf("%f",&edit_course[j].credit);
        printf("\n\t\t\t\t\tType: ");           scanf("%s",&edit_course[j].type);

        printf("\n\t\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Update ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("course.txt","w");

            for(j=0; j<n; j++)
            {
               fprintf(f,"%s %d %s, %s, %.2f %s\n",edit_course[j].program,edit_course[j].semester,edit_course[j].code,edit_course[j].title,edit_course[j].credit,edit_course[j].type);
            }

            fclose(f);

            for (j=0; j<70; j++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Course Update Successful *******\n\n");
            printf("\t\t\t\t\tDo You Edit Another Course ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_course_f();
            }else
            {
                system("CLS");  title(); view_course_f();
            }
        }else
        {
            system("CLS");  title(); course();
        }
    }
    else
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!! Incorrect Course Code !!!\n\n");
        printf("\t\t\t\t\tDo You Edit Another Course ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    edit_course_f();
        }else
        {
            system("CLS");  title(); course();
        }
    }
}
void delete_course_f ()
{
    struct cou delete_course[100];
    struct pro read_program[100];
    char select_code[20];
    int n = 0, match = 0,p = 0;

    delete_course_title();

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",delete_course[n].program,&delete_course[n].semester,delete_course[n].code,delete_course[n].title,&delete_course[n].credit,delete_course[n].type);
        n++;
    }
    fclose(f);

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",read_program[p].code,read_program[p].name);
        p++;
    }fclose(f);

    for(i=0; i<p-1; i++)
        printf("\t\t\t\t\t%d. %s (%s)\n\n",i+1,read_program[i].name,read_program[i].code);

    printf("\n\t\t\t\t\tSelect Program : ");  scanf("%d",&selectProgram);
    system("CLS"); title(); delete_course_title();

    printf("\t\t\t\t\tSelect Course CODE : ");   scanf(" %[A-Z 0-9]",&select_code);

    for(i=0; i<n; i++)
    {
        if(strcmp(read_program[selectProgram-1].code,delete_course[i].program)==0 && strcmp(select_code,delete_course[i].code)==0)
        {
            for(j=i; j<n-1; j++)
            {
                strcpy(delete_course[j].program,delete_course[j+1].program);
                delete_course[j].semester = delete_course[j+1].semester;
                strcpy(delete_course[j].code,delete_course[j+1].code);
                strcpy(delete_course[j].title,delete_course[j+1].title);
                delete_course[j].credit = delete_course[j+1].credit;
                strcpy(delete_course[j].type,delete_course[j+1].type);
            }
            match = 1;  break;
        }
    }
    if(match == 1)
    {
        printf("\n\t\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Delete ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("course.txt","w");
            for(i=0; i<n-1; i++)
            {
                fprintf(f,"%s %d %s, %s, %.2f %s\n",delete_course[i].program,delete_course[i].semester,delete_course[i].code,delete_course[i].title,delete_course[i].credit,delete_course[i].type);
            }
            fclose(f);
            for (j=0; j<70; j++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Course Delete Successful *******\n\n");
            printf("\t\t\t\t\tDo You Delete Another Course ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    delete_course_f();
            }else
            {
                system("CLS");  title(); view_course_f();
            }
        }
        else
        {
            system("CLS");  title(); course();
        }
    }
    else
    {
        printf("\n\t\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!! Incorrect Course Code !!!\n\n");
        printf("\t\t\t\t\tDo You Delete Another Course ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    delete_course_f();
        }else
        {
            system("CLS");  title(); view_course_f();
        }
    }
}
void view_course_f ()
{
    struct cou view_course[100];
    struct pro read_program[100];
    int n = 0,p = 0,match = 0;

    view_course_title();

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",view_course[n].program,&view_course[n].semester,view_course[n].code,view_course[n].title,&view_course[n].credit,view_course[n].type);
        n++;
    }
    fclose(f);

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

    printf("\n\t\t\t\t\tSelect Program : ");  scanf("%d",&selectProgram);
    system("CLS"); title(); view_course_title();

    printf("\t\t\t\t\t\t    Course Structure of %s\n",read_program[selectProgram-1].code);
    printf("\t\t\t\t------------------------------------------------------------------\n\n");

    printf("\t\t\tSEM NO   | COURSE CODE  | CREDIT  |   TYPE\t|  COURSE TITLE\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    for(i=0; i<n; i++)
    {
        if(strcmp(read_program[selectProgram-1].code,view_course[i].program)==0)
        {
            match = 1;
            printf("\t\t\t   %d\t |   %s\t|   %.1f\t  |   %s   \t| %s",view_course[i].semester,view_course[i].code,view_course[i].credit,view_course[i].type,view_course[i].title);
            printf("\n\t\t\t---------------------------------------------------------------------------------------------\n\n");
        }
    }

    if(match == 0)
    {
        system("CLS"); title(); view_course_title();
        printf("\t\t\t\t\t!!!!! Empty Course In This Program !!!!!\n\n");
        printf("\t\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }

    printf("\t\t\t\t\tDo You Select Another Program ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        system("CLS");  title();    view_course_f();
    }else
    {
        system("CLS");  title(); course();
    }

}

#endif // COURSE_H_INCLUDED
