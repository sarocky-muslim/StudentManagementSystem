#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED

void payment ()
{
    printf("\t\t\t\t\t1.Add Payment | 2.View Payment | 3.Edit Payment\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t    4.Main Menu | 5.Exit\n");
    printf("\t\t--------------------------------------------------------------------------------------------\n\n\n");

    int select_menu;   printf("\t\t\t\t\tPress the Number of Menu: ");   scanf("%d%*c",&select_menu);

    switch(select_menu)
    {
        case 1:     system("CLS");  title();  add_payment_f();  break;

        case 2:     system("CLS");  title();  view_payment_f();  break;

        case 3:     system("CLS");  title();  edit_payment_f();  break;

        case 4:     system("CLS");  title();  admin_main_menu();  break;

        case 5:     break;

        default:    printf("\t\t\t\t\tPress select the right menu");  break;
    }
    exit(0);
}

void add_payment_title()
{
    printf("\t\t\t\t\t\t    Add Payment Info\n");
    printf("\t\t\t-----------------------------------------------------------------------\n\n");
}
void edit_payment_title()
{
    printf("\t\t\t\t\t\t    Edit Payment Info\n");
    printf("\t\t\t-----------------------------------------------------------------------\n\n");
}
void view_payment_title()
{
    printf("\t\t\t\t\t\t    View Payment Info\n");
    printf("\t\t\t\t-----------------------------------------------------------------------\n\n");
}

void add_payment_f()
{
    struct pa addPayment;
    struct pa readPayment;
    struct stu readStudent;
    struct cou_en readCourseEnroll[100];
    struct cou readCourse;
    int stuMatch = 0,couEnMatch = 0,couMatch = 0,payMatch = 0,n = 0,selectEnroll,programMatch;
    float totalCredit = 0;

    add_payment_title();

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",readCourseEnroll[n].semester_name,readCourseEnroll[n].program,readCourseEnroll[n].shift,&readCourseEnroll[n].intake,&readCourseEnroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,readCourseEnroll[i].semester_name,readCourseEnroll[i].program,readCourseEnroll[i].shift,readCourseEnroll[i].intake,readCourseEnroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To Add Payment: ");  scanf("%d",&selectEnroll);
    system("CLS"); title(); add_payment_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",readCourseEnroll[selectEnroll-1].semester_name,readCourseEnroll[selectEnroll-1].program,readCourseEnroll[selectEnroll-1].shift,readCourseEnroll[selectEnroll-1].intake,readCourseEnroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    printf("\t\t\t\t\t\tStudent ID\t: ");    scanf("%d",&addPayment.stuID);

    f = fopen("student.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%d %[^,], %d %d %s %s %[^\n]",&readStudent.id,readStudent.name,&readStudent.section,&readStudent.intake,readStudent.shift,readStudent.program,readStudent.semester);
        if(strcmp(readCourseEnroll[selectEnroll-1].semester_name,readStudent.semester)==0 && strcmp(readCourseEnroll[selectEnroll-1].program,readStudent.program)==0 && strcmp(readCourseEnroll[selectEnroll-1].shift,readStudent.shift)==0 && readCourseEnroll[selectEnroll-1].intake == readStudent.intake && addPayment.stuID == readStudent.id)
        {
            stuMatch = 1;  fclose(f);  break;
        }
    }fclose(f);

    if(stuMatch == 1)
    {
        f = fopen("course.txt","r");
        while(!feof(f))
        {
            fscanf(f,"%s %d %[^,], %[^,], %f %s\n",readCourse.program,&readCourse.semester,readCourse.code,readCourse.title,&readCourse.credit,readCourse.type);
            if(strcmp(readCourseEnroll[selectEnroll-1].program,readCourse.program)==0 && readCourseEnroll[selectEnroll-1].semester_no == readCourse.semester)
            {
                totalCredit = totalCredit + readCourse.credit;
                couMatch = 1;
            }
        }fclose(f);

        if(couMatch == 1)
        {
            strcpy(addPayment.semName,readCourseEnroll[selectEnroll-1].semester_name);
            strcpy(addPayment.program,readCourseEnroll[selectEnroll-1].program);
            strcpy(addPayment.shift,readCourseEnroll[selectEnroll-1].shift);
            addPayment.intake = readCourseEnroll[selectEnroll-1].intake;
            addPayment.semNo = readCourseEnroll[selectEnroll-1].semester_no;

            printf("\n\t\t\t\t\t\tTotal Credit\t: %.2f\n\n",totalCredit);
            printf("\t\t\t\t\t\tPer Credit\t: 1070 tk\n\n");
            printf("\t\t\t\t\t\tPer Semester\t: 7820 tk\n\n");
            addPayment.totalAmount = (totalCredit * 1070) + 7820;
            printf("\t\t\t\t\t\tTotal Amount\t: %d tk\n\n",addPayment.totalAmount);
            //payAmount:
            printf("\t\t\t\t\t\tPay Amount\t: ");   scanf("%d",&addPayment.payAmount);
//            if(addPayment.payAmount>addPayment.totalAmount)
//            {
//                for (i=0; i<130; i++)   {   printf("\b");   }
//                goto payAmount;
//            }
            addPayment.dueAmount = addPayment.totalAmount - addPayment.payAmount;
            printf("\n\t\t\t\t\t\tDue Amount\t: %d tk\n",addPayment.dueAmount);
            printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
            printf("\t\t\t\t\tDo You Want To Save ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                f = fopen("payment.txt","r");
                while(!feof(f))
                {
                    fscanf(f,"%[^,], %s %s %d %d %d %d %d %d\n",readPayment.semName,readPayment.program,readPayment.shift,&readPayment.intake,&readPayment.semNo,&readPayment.stuID,&readPayment.totalAmount,&readPayment.payAmount,&readPayment.dueAmount);
                    if(strcmp(addPayment.semName,readPayment.semName)==0 && strcmp(addPayment.program,readPayment.program)==0 && strcmp(addPayment.shift,readPayment.shift)==0 && addPayment.intake == readPayment.intake && addPayment.semNo == readPayment.semNo && addPayment.stuID == readPayment.stuID)
                    {
                        payMatch = 1;  fclose(f);  break;
                    }
                }fclose(f);

                if(payMatch == 0)
                {
                    f = fopen("payment.txt","a");
                    fprintf(f,"%s, %s %s %d %d %d %d %d %d\n",addPayment.semName,addPayment.program,addPayment.shift,addPayment.intake,addPayment.semNo,addPayment.stuID,addPayment.totalAmount,addPayment.payAmount,addPayment.dueAmount);
                    fclose(f);

                    for (i=0; i<122; i++)   {   printf("\r");   }
                    printf("\t\t\t\t\t******* Add Payment Successful *******\n\n");
                    printf("\t\t\t\t\tDo You Add More Payment ? Y / N : "); permission = getch();

                    if(permission == 'Y' || permission == 'y')
                    {
                        system("CLS");  title();    add_payment_f();
                    }else
                    {
                        system("CLS");  title(); payment();
                    }

                }else
                {
                    for (i=0; i<122; i++)   {  printf("\r");   }
                    printf("\t\t\t\t\t!!!!!!! The Payment Already Added !!!!!!!\n\n");
                    printf("\t\t\t\t\tDo You Add More Payment ? Y / N : "); permission = getch();

                    if(permission == 'Y' || permission == 'y')
                    {
                        system("CLS");  title();    add_payment_f();
                    }else
                    {
                        system("CLS");  title(); payment();
                    }

                }
            }else
            {
                system("CLS");  title();    payment();
            }

        }else
        {
            printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
            printf("\t\t\t\t\t!!!!!!! Course Not Found !!!!!!!\n\n");
        }

    }else
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!!!!!! The Student Is Not Match !!!!!!!\n\n");

        printf("\t\t\t\t\tDo You Search Another Student ? Y / N : "); permission = getch();
        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    add_payment_f();
        }else
        {
            system("CLS");  title(); payment();
        }
    }
}

void edit_payment_f()
{
    struct pa addPayment;
    struct pa readPayment;
    struct pa editPayment[100];
    struct stu readStudent;
    struct cou_en readCourseEnroll[100];
    struct cou readCourse;
    int stuMatch = 0,couEnMatch = 0,couMatch = 0,payMatch = 0,perCredit = 1000,n = 0,m = 0,selectEnroll;
    float totalCredit = 0;

    edit_payment_title();

    f = fopen("course_enroll.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d\n",readCourseEnroll[n].semester_name,readCourseEnroll[n].program,readCourseEnroll[n].shift,&readCourseEnroll[n].intake,&readCourseEnroll[n].semester_no);
        n++;
    }fclose(f);

    printf("\t\t\tS/N\t|  SEMESTER\t|  PROGRAM\t|  SHIFT\t|  INTAKE\t|  SEM NO\n");
    printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    for(i=0; i<n; i++)
    {
        printf("\t\t\t%d\t|  %s\t|  %s\t\t|  %.3s\t\t|  %d\t\t|  %d\n",i+1,readCourseEnroll[i].semester_name,readCourseEnroll[i].program,readCourseEnroll[i].shift,readCourseEnroll[i].intake,readCourseEnroll[i].semester_no);
        printf("\t\t\t---------------------------------------------------------------------------------------------\n\n");
    }
    printf("\n\t\t\t\t\tSelect Enrolled To Edit Payment: ");  scanf("%d",&selectEnroll);
    system("CLS"); title(); edit_payment_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",readCourseEnroll[selectEnroll-1].semester_name,readCourseEnroll[selectEnroll-1].program,readCourseEnroll[selectEnroll-1].shift,readCourseEnroll[selectEnroll-1].intake,readCourseEnroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    printf("\t\t\t\t\tStudent ID : ");    scanf("%d",&addPayment.stuID);

    f = fopen("payment.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %d %d %d\n",editPayment[m].semName,editPayment[m].program,editPayment[m].shift,&editPayment[m].intake,&editPayment[m].semNo,&editPayment[m].stuID,&editPayment[m].totalAmount,&editPayment[m].payAmount,&editPayment[m].dueAmount);
        m++;
    }fclose(f);

    for(i=0; i<m; i++)
    {
        if(strcmp(readCourseEnroll[selectEnroll-1].semester_name,editPayment[i].semName)==0 && strcmp(readCourseEnroll[selectEnroll-1].program,editPayment[i].program)==0 && strcmp(readCourseEnroll[selectEnroll-1].shift,editPayment[i].shift)==0 && readCourseEnroll[selectEnroll-1].intake == editPayment[i].intake && addPayment.stuID == editPayment[i].stuID)
        {
            if(editPayment[i].dueAmount != 0)
            {
                printf("\n\t\t\t\t\tTotal Amount : %d\n\n",editPayment[i].totalAmount);
                printf("\t\t\t\t\tPaid Amount : %d\n\n",editPayment[i].payAmount);
                printf("\t\t\t\t\tDue Amount : %d\n\n",editPayment[i].dueAmount);
                //payAmount:
                printf("\t\t\t\t\tPay Amount : ");  scanf("%d",&addPayment.payAmount);
//                if(addPayment.payAmount>editPayment[i].dueAmount)
//                {
//                    for (i=0; i<130; i++)   {   printf("\b");   }
//                    goto payAmount;
//                }
                editPayment[i].payAmount += addPayment.payAmount;
                editPayment[i].dueAmount = editPayment[i].totalAmount - editPayment[i].payAmount;
                printf("\n\t\t\t\t\tDue Amount : %d\n",editPayment[i].dueAmount);
                stuMatch = 1;  fclose(f);  break;
            }
            else
            {
                printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
                printf("\t\t\t\t\t*** The Payment is Paid ***\n\n");
                printf("\t\t\t\t\tDo You Update Another Payment ? Y / N : "); permission = getch();

                if(permission == 'Y' || permission == 'y')
                {
                    system("CLS");  title();    edit_payment_f();
                }else
                {
                    system("CLS");  title(); payment();
                }
            }
        }
    }

    if(stuMatch == 1)
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tDo You Want To Update ? Y / N : "); permission = getch();

        if(permission == 'Y' || permission == 'y')
        {
            f = fopen("payment.txt","w");

            for(j=0; j<m; j++)
                fprintf(f,"%s, %s %s %d %d %d %d %d %d\n",editPayment[j].semName,editPayment[j].program,editPayment[j].shift,editPayment[j].intake,editPayment[j].semNo,editPayment[j].stuID,editPayment[j].totalAmount,editPayment[j].payAmount,editPayment[j].dueAmount);

            fclose(f);

            for (i=0; i<122; i++)   {   printf("\r");   }
            printf("\t\t\t\t\t******* Update Payment Successful *******\n\n");
            printf("\t\t\t\t\tDo You Update More Payment ? Y / N : "); permission = getch();

            if(permission == 'Y' || permission == 'y')
            {
                system("CLS");  title();    edit_payment_f();
            }else
            {
                system("CLS");  title(); payment();
            }

        }else
        {
            system("CLS");  title();    payment();
        }

    }else
    {
        printf("\n\t\t\t-----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t!!!!!!! The Student Is Not Match !!!!!!!\n\n");

        printf("\t\t\t\t\tDo You Search Another Student ? Y / N : "); permission = getch();
        if(permission == 'Y' || permission == 'y')
        {
            system("CLS");  title();    edit_payment_f();
        }else
        {
            system("CLS");  title(); payment();
        }
    }
}

void view_payment_f ()
{
    struct pro read_program[100];
    struct pa readPayment[100];
    struct cou_en read_course_enroll[100];
    struct stu read_student;
    struct cou read_course;
    int n = 0,p = 0,selectShift,selectIntake,intake = 0,semNo,selectMenu,totalAmount,programMatch,selectEnroll;
    char shift[10],selectSemester[15];
    float totalCredit = 0;

    view_payment_title();

    f = fopen("payment.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %d %d %d\n",readPayment[n].semName,readPayment[n].program,readPayment[n].shift,&readPayment[n].intake,&readPayment[n].semNo,&readPayment[n].stuID,&readPayment[n].totalAmount,&readPayment[n].payAmount,&readPayment[n].dueAmount);
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
    printf("\n\t\t\t\t\tSelect Enrolled To View Payment: ");  scanf("%d",&selectEnroll);
    system("CLS"); title(); view_payment_title();

    printf("\t\t\tSemester: %s -> Program: %s -> Shift: %s -> Intake: %d -> Sem No: %d\n",read_course_enroll[selectEnroll-1].semester_name,read_course_enroll[selectEnroll-1].program,read_course_enroll[selectEnroll-1].shift,read_course_enroll[selectEnroll-1].intake,read_course_enroll[selectEnroll-1].semester_no);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    f = fopen("course.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
        if(strcmp(read_course_enroll[selectEnroll-1].program,read_course.program)==0 && read_course.semester == read_course_enroll[selectEnroll-1].semester_no)
        {
            totalCredit += read_course.credit;
        }
    }fclose(f);

    printf("\t\t\t\t\t\tTotal Credit\t: %.2f\n\n",totalCredit);
    printf("\t\t\t\t\t\tPer Credit\t: 1070 tk\n\n");
    printf("\t\t\t\t\t\tPer Semester\t: 7820 tk\n\n");
    totalAmount = (totalCredit * 1070) + 7820;
    printf("\t\t\t\t\t\tTotal Amount\t: %d tk\n",totalAmount);
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");

    for(i=0; i<n; i++)
    {
        if(strcmp(read_course_enroll[selectEnroll-1].semester_name,readPayment[i].semName) == 0 && strcmp(read_course_enroll[selectEnroll-1].program,readPayment[i].program)==0 && strcmp(read_course_enroll[selectEnroll-1].shift,readPayment[i].shift)==0 && read_course_enroll[selectEnroll-1].intake == readPayment[i].intake)
        {
            printf("\t\t\t\tStudent ID: %d || Pay Amount: %d || Due Amount: %d\n",readPayment[i].stuID,readPayment[i].payAmount,readPayment[i].dueAmount);
            printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        }
    }

    printf("\t\t\t\t\tDo You View Another Payment ? Y / N : "); permission = getch();

    if(permission == 'Y' || permission == 'y')
    {
        system("CLS");  title();    view_payment_f();
    }else
    {
        system("CLS");  title(); payment();
    }
}

#endif // PAYMENT_H_INCLUDED
