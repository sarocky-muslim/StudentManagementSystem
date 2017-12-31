#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED


void program ()
{
    printf("\t\t\t\t1.Add Program | 2.View Program | 3.Edit Program | 4.Delete Program");
    printf("\n\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    5.Main Menu | 6.Exit");
    printf("\n\t\t--------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_program_f();  break;

        case 2:     system("CLS");  title();  view_program_f();  break;

        case 3:     system("CLS");  title();  edit_program_f();  break;

        case 4:     system("CLS");  title();  delete_program_f();  break;

        case 5:     system("CLS");  title();  admin_main_menu();  break;

        case 6:     break;

        default:
            printf("\n\t\t\t\t\t!!! You Press Wrong Menu !!! Tray Again Y / N :");
            permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title(); program();
            }
            break;
    }
    exit(0);
}
void edit_program_title()
{
    printf("\t\t\t\t\t\t    Edit Program Info\n");
    printf("\t\t\t-----------------------------------------------------------------------\n\n");
}
void add_program_f ()
{
    struct pro add_program;
    struct pro read_program;
    int match = 0;

    printf("\t\t\t\t\t\t    Add Program Info\n");
    printf("\t\t\t-----------------------------------------------------------------------\n\n");

    printf("\t\t\t\t\tProgram Code: ");   scanf("%s%*c",&add_program.code);
    printf("\n\t\t\t\t\tProgram Name: ");      scanf("%[^\n]",&add_program.name);

    printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        f = fopen("program.txt","r");

        while(!feof(f))
        {
            fscanf(f,"%s %[^\n]",read_program.code,read_program.name);
            if(strcmp(add_program.code,read_program.code)==0)
            {
                match = 1;  fclose(f);  break;
            }
        }
        fclose(f);
        if(match == 0)
        {
            f = fopen("program.txt","a");
            fprintf(f,"%s %s\n",add_program.code,add_program.name);
            fclose(f);

            for (i=0; i<122; i++)   {   printf("\r");   }
            printf("\t\t\t\t\t******* Program Add Successful *******\n\n");
            printf("\t\t\t\t\tDo You Add More Program ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {

                system("CLS");  title();    add_program_f();

            }else
            {
                system("CLS");  title(); program();
            }

        }else
        {
            for (i=0; i<122; i++)   {  printf("\r");   }
            printf("\t\t\t\t\t!!!!!!! The Program Already Taken !!!!!!!\n\n");
            printf("\t\t\t\t\tDo You Add Another Program ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {

                system("CLS");  title();    add_program_f();

            }else
            {
                system("CLS");  title(); program();
            }

        }

    }else
    {
        system("CLS");  title();    program();
    }

}
void edit_program_f ()
{
    struct pro edit_program[100];
    char select_code[20];
    int match = 0,n = 0;

    edit_program_title();

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",edit_program[n].code,edit_program[n].name);
        n++;
    }
    fclose(f);

    printf("\t\t\t\t\tEnter Program CODE : ");   scanf("%s%*c",&select_code);

    for(i=0; i<n-1; i++)
    {
        if(strcmp(select_code,edit_program[i].code)==0)
        {
            match = 1;
            break;
        }
    }
    if(match == 1)
    {
        system("CLS");  title(); edit_program_title();

        printf("\t\t\t\t\tProgram Code: ");   scanf("%s%*c",&edit_program[i].code);
        printf("\n\t\t\t\t\tProgram Name: ");      scanf("%[^\n]",&edit_program[i].name);

        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Update ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("program.txt","w");

            for(i=0; i<n-1; i++)
            {
               fprintf(f,"%s %s\n",edit_program[i].code,edit_program[i].name);
            }

            fclose(f);

            for (j=0; j<70; j++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Program Update Successful *******\n\n");
            printf("\t\t\t\t\tDo You Edit Another Program ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_program_f();
            }else
            {
                system("CLS");  title(); view_program_f();
            }
        }else
        {
            system("CLS");  title(); program();
        }
    }
    else
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!! Incorrect Program CODE !!!\n\n");
        printf("\t\t\t\t\tDo You Edit Another Program ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    edit_program_f();
        }else
        {
            system("CLS");  title(); program();
        }
    }
}
void delete_program_f ()
{
    struct pro delete_program[100];
    char select_code[20];
    int n = 0, match = 0;

    printf("\t\t\t\t\t\t    Delete Program Info\n");
    printf("\t\t\t-----------------------------------------------------------------------\n\n");

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",delete_program[n].code,delete_program[n].name);
        n++;
    }
    fclose(f);

    printf("\t\t\t\t\tEnter Program CODE : ");   scanf("%s%*c",&select_code);

    for(i=0; i<n-1; i++)
    {
        if(strcmp(select_code,delete_program[i].code)==0)
        {
            for(j=i; j<n-2; j++)
            {
                strcpy(delete_program[j].code,delete_program[j+1].code);
                strcpy(delete_program[j].name,delete_program[j+1].name);
            }
            match = 1;  break;
        }
    }
    if(match == 1)
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Delete ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("program.txt","w");
            for(i=0; i<n-2; i++)
            {
                fprintf(f,"%s %s\n",delete_program[i].code,delete_program[i].name);
            }
            fclose(f);
            for (j=0; j<70; j++)   {   printf("\b");   }
            printf("\t\t\t\t\t******* Program Delete Successful *******\n\n");
            printf("\t\t\t\t\tDo You Delete Another Program ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    delete_program_f();
            }else
            {
                system("CLS");  title(); view_program_f();
            }
        }
        else
        {
            system("CLS");  title(); program();
        }
    }
    else
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!! Incorrect Program CODE !!!\n\n");
        printf("\t\t\t\t\tDo You Delete Another Program ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    delete_program_f();
        }else
        {
            system("CLS");  title(); view_program_f();
        }
    }

}
void view_program_f ()
{
    struct pro view_program[100];
    int n = 0;

    printf("\t\t\t\t\t\t    View Program Info\n");
    printf("\t\t\t\t-----------------------------------------------------------------------\n\n");

    f = fopen("program.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %[^\n]",view_program[n].code,view_program[n].name);
        n++;
    }
    fclose(f);

    for(i=0; i<n-1; i++)
    {
        printf("\t\t\t\t\t* %s (%s)\n\n",view_program[i].name,view_program[i].code);
    }


    printf("\t\t\t\t-----------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\tPress Any Key To Go Back..."); permission = getch();

    if(permission)
    {
        system("CLS");  title(); program();
    }
}

#endif // PROGRAM_H_INCLUDED
