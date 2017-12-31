#ifndef VIEWPAYMENT_H_INCLUDED
#define VIEWPAYMENT_H_INCLUDED

void viewPayment ()
{
    struct pa readPayment;
    struct cou read_course;
    float totalCredit = 0;
    int totalAmount,match = 0;

    printf("\t\t\t\t\t\t    Payment Information\n");
    printf("\t\t\t-----------------------------------------------------------------------------\n\n");

    f = fopen("payment.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,], %s %s %d %d %d %d %d %d\n",readPayment.semName,readPayment.program,readPayment.shift,&readPayment.intake,&readPayment.semNo,&readPayment.stuID,&readPayment.totalAmount,&readPayment.payAmount,&readPayment.dueAmount);
        if(StudentID == readPayment.stuID && readPayment.dueAmount != 0)
        {
            match = 1; break;
        }
    }fclose(f);

    if(match == 1)
    {
        f = fopen("course.txt","r");
        while(!feof(f))
        {
            fscanf(f,"%s %d %[^,], %[^,], %f %s\n",read_course.program,&read_course.semester,read_course.code,read_course.title,&read_course.credit,read_course.type);
            if(strcmp(readPayment.program,read_course.program)==0 && readPayment.semNo == read_course.semester)
            {
                totalCredit += read_course.credit;
            }

        }fclose(f);

        printf("\t\t\t\t\tSemester\t: %s\n\n",readPayment.semName);
        printf("\t\t\t\t\tTotal Credit\t: %.2f\n\n",totalCredit);
        printf("\t\t\t\t\tPer Credit\t: 1070 tk\n\n");
        printf("\t\t\t\t\tPer Semester\t: 7820 tk\n\n");
        totalAmount = (totalCredit * 1070) + 7820;
        printf("\t\t\t\t\tTotal Amount\t: %d tk\n\n",totalAmount);
        printf("\t\t\t\t\tPay Amount\t: %d tk\n\n",readPayment.payAmount);
        printf("\t\t\t\t\tDue Amount\t: %d tk\n\n",readPayment.dueAmount);

        printf("\t\t\t-----------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tPress Any Key To Go Main Menu...");
        getch();    system("CLS");    title();    student_main_menu();
    }
    else
    {
        printf("\t\t\t\t\t\t*** Your Payment is Paid ***\n\n");
        printf("\t\t\t-----------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tPress Any Key To Go Main Menu...");
        getch();    system("CLS");    title();    student_main_menu();
    }
}

#endif // VIEWPAYMENT_H_INCLUDED
