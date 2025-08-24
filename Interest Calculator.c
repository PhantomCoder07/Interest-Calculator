#include <stdio.h>
#include <math.h>
float simple (float m, float t, float i)
{
    return (m*t*i)/100;
}
float compound (float m, float t, float i)
{
    return m*((pow((1+i/100),t)));
}
int main()
{
    float main,time,interest,main_i;
    int n,i=1;
    FILE *fp;
    fp = fopen("History.txt","w");
    printf("---------------//Welcome to Interest Calculator\\\\---------------\n\n");
    while (1)
    {
        printf("Which kind of interest you want to calculate?\n");
        printf("1 - Simple Interest\n");
        printf("2 - Compound Interest\n");
        printf("------------------------------------------------------------------\n");
        printf("Enter number of your choice: ");
        scanf("%d",&n);
        printf("------------------------------------------------------------------\n");
        switch (n)
        {
        case 1:
            printf ("Enter the main amount    : ");
            scanf ("%f",&main);
            printf ("Enter interest rate      : ");
            scanf ("%f",&interest);
            printf ("Enter time(annual)       : ");
            scanf ("%f",&time);
            main_i=main+simple(main,time,interest);
            printf ("Total amount of interest : %.2f\n",simple(main,time,interest));
            printf ("Total amount of money    : %.2f\n",main_i);
            fprintf (fp,"For case %d :\n",i++);
            fprintf (fp,"Total amount of interest : %.2f\n",simple(main,time,interest));
            fprintf (fp,"Total amount of money    : %.2f\n",main_i);
            break;
        case 2:
            printf ("Enter the main amount    : ");
            scanf ("%f",&main);
            printf ("Enter interest rate      : ");
            scanf ("%f",&interest);
            printf ("Enter time(annual)       : ");
            scanf ("%f",&time);
            main_i=compound(main,time,interest)-main;
            printf ("Total amount of interest : %.2f\n",main_i);
            printf ("Total amount of money    : %.2f\n",compound(main,time,interest));
            fprintf (fp,"For case %d :\n",i++);
            fprintf (fp,"Total amount of interest : %.2f\n",main_i);
            fprintf (fp,"Total amount of money    : %.2f\n",compound(main,time,interest));
            break;
        default:
            printf("Wrong entry\n");
            printf("Choice carefully\n");
            printf("------------------------------------------------------------------\n");
            continue;
        }
        printf("------------------------------------------------------------------\n");
        printf("Want to calculate more?\n");
        printf("1 - Yes\n");
        printf("0 - No\n");
        printf("------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        if (n==0)
        {
            printf("------------------------------------------------------------------\n");
            printf("Thank you.\n");
            printf("------------------------------------------------------------------\n");
            break;
        }
        else
            continue;
    }
    fclose(fp);
    printf("Here's the history:\n");
    printf("----------------------------------------------------------------------\n");
    char ch;
    fp = fopen("History.txt","r");
    while (!feof(fp))
    {
        ch=getc(fp);
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
