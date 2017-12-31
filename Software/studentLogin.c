#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_variables.h"
#include "viewMarksheet.h"
#include "viewTotalCourse.h"
#include "viewSummery.h"
#include "viewPayment.h"

void title()
{
    printf("\n\n\n\t\t\t\t\t********** STUDENT MANAGEMENT SYSTEM **********\n\n\n\n");
    printf("\t\t\t\t\t\t    Hi, %s\n",StuNameTitle);
    printf("\t\t\t\t\t-----------------------------------------------\n\n");
}
void student_main_menu ()
{
    printf("\t\t---------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t    1.Summery / 2.Mark Sheet / 3.Payment Info / 4.Total Course / 5.Exit\n\n");
    printf("\t\t---------------------------------------------------------------------------------------------\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();    viewSummery();    break;

        case 2:     system("CLS");  title();    markSheet();  break;

        case 3:     system("CLS");  title();    viewPayment();  break;

        case 4:     system("CLS");  title();    totalCourse();  break;

        case 5:     break;

        default:    printf("\t\t\t\tPress select the right menu");  break;
    }
    exit(1);
}
void login()
{
    struct stu read_student;
    char readPass[10],pass[10];
    int match = 0,match2 = 0,readID,id;

    printf("\n\n\n\n\n\t\t\t\t\t\t\tStudent Login Panel\n");
    printf("\t\t\t\t\t-----------------------------------------------\n\n");

    printf("\t\t\t\t\t\tEnter ID\t:   ");         scanf("%d",&id);

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&read_student.id,read_student.name,&read_student.section,&read_student.intake,read_student.shift,read_student.program,read_student.semester);
        if(id == read_student.id)
        {
            match = 1;  break;
        }
    }fclose(f);

    if(match == 1)
    {
        f = fopen("studentLogin.txt","r");
        while(!feof(f))
        {
            fscanf(f,"%d %s",&readID,readPass);
            if(id == readID)
            {
                match2 = 1;
                printf("\n\n\t\t\t\t\t\tEnter Password\t:   ");  scanf("%s",pass);
                if(strcmp(pass,readPass) == 0)
                {
                    strcpy(StuNameTitle,read_student.name);
                    StudentID = read_student.id;
                    system("CLS");  title();    student_main_menu();
                    break;
                }
                else
                {
                    printf("\n\t\t\t\t\t-----------------------------------------------\n\n");
                    printf("\t\t\t\t\t!!! Incorrect Password !!!, Try Again ? y / n : "); permission = getch();

                    if(permission == 'Y' || permission == 'y')
                    {
                        system("CLS");    login();
                    }
                    else
                        exit(1);
                }
            }
        }fclose(f);

        if(match2 == 0)
        {
            printf("\n\n\t\t\t\t\t\tCreate Password\t:   ");  scanf("%s",pass);
            printf("\n\t\t\t\t\t-----------------------------------------------\n\n");
            printf("\t\t\t\t\t\tDo you want to save ? y / n...");   permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                f = fopen("studentLogin.txt","a");
                fprintf(f,"%d %s\n",id,pass);
                fclose(f);

                for (k=0; k<100; k++)   {   printf("\b");   }
                printf("\n\t\t\t\t\t\t*** Account has been created ***\n");
                printf("\n\t\t\t\t\t\tPress Any Key To LOGIN...");
                getch();    system("CLS");    login();
            }
            else
            {
              system("CLS");    login();
            }
        }
    }else
    {
        printf("\n\t\t\t\t\t-----------------------------------------------\n\n");
        printf("\t\t\t\t\t!!! Incorrect ID !!!, Try Again ? y / n : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");    login();
        }
        else
            exit(1);
    }
}

main ()
{
    system("COLOR F0");
    login();

}

