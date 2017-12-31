#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_variables.h"
#include "program.h"
#include "course.h"
#include "student.h"
#include "course_enroll.h"
#include "results.h"
#include "payment.h"

void title()
{
    printf("\n\n\t\t\t\t\t********** STUDENT MANAGEMENT SYSTEM **********\n\n\n");
    printf("\t\t\t\t\t\t    Admin Dashboard Panel");
    printf("\n\t\t\t\t\t-----------------------------------------------\n\n\n");
}
void admin_main_menu ()
{
    printf("\t\t     1.Program /\\ 2.Course /\\ 3.Student /\\ 4.Course Enroll /\\ 5.Result /\\ 6.Payment /\\ 7.Exit");
    printf("\n\t\t--------------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\t\tPress the Number of Menu: ");   scanf("%d",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  program();            break;

        case 2:     system("CLS");  title();  course();             break;

        case 3:     system("CLS");  title();  student();            break;

        case 4:     system("CLS");  title();  course_enroll();      break;

        case 5:     system("CLS");  title();  results();            break;

        case 6:     system("CLS");  title();  payment();            break;

        case 7:     break;

        default:
            printf("\n\t\t\t\t\t!!! You Press Wrong Menu !!! Tray Again Y / N :");
            permission = getch();
            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title(); admin_main_menu();
            }
            break;
    }
}
void login()
{
    char email[30],pass[10];

    printf("\n\n\n\n\n\t\t\t\t\t\t\tAdmin Login Panel\n");
    printf("\t\t\t\t\t---------------------------------------------------\n\n");

    printf("\t\t\t\t\t\tEnter Email\t:   ");         scanf("%s",email);
    printf("\n\n\t\t\t\t\t\tEnter Password\t:   ");  scanf("%s",pass);

    if(strcmp(email,"admin@gmail.com")==0 && strcmp(pass,"admin123")==0)
    {
        system("CLS");    title();  admin_main_menu();
    }
    else
    {
      printf("\n\t\t\t\t\t---------------------------------------------------\n\n");
      printf("\t\t\t\t\t\t!!! Invalid Email / Password !!!\n\n");
      printf("\t\t\t\t\t\t\tTry Again ? y / n ");  permission = getch();

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
