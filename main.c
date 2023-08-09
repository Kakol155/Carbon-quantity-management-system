#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char r;
    float purchased_coal;
    float spent_coal;
    char information_from_the_file[50];
    char information_from_the_file_2[50];
    float information_from_the_file_float;
    float coal_update;
    char file_1[30];

    file = fopen("Coal.txt","r");

    fgets(file_1,20,file);

    fclose(file);

    file = fopen("Coal.txt","w");

    fprintf(file,"%s",file_1);

    fclose(file);

    printf("1.Enter how much coal you have \n");
    printf("2.Enter how much coal you used \n");
    printf("3.Reset the amount of Coal you have \n");
    printf("4.Exit \n\n");

    file = fopen("Coal.txt","r");

    fgets(information_from_the_file_2,50,file);

    printf("The current amount of carbon in kg %s\n\n",information_from_the_file_2);

    fclose(file);

    printf("Enter the number\n");
    scanf("%c",&r);

    switch(r)
    {
        case'1':

        printf("How much coal did you buy in kg\n");
        scanf("%f",&purchased_coal);

        file = fopen("Coal.txt","r");

        fgets(information_from_the_file,50,file);

        fclose(file);
        sscanf(information_from_the_file,"%f",&information_from_the_file_float);

        coal_update = information_from_the_file_float + purchased_coal;

        file = fopen("Coal.txt","w");

        fprintf(file,"%.2f",coal_update);

        fclose(file);

        printf("The current amount of carbon in kg %.2f\n",coal_update);


        break;

        case'2':

        printf("How much coal did you lose in kg\n");
        scanf("%f",&spent_coal);

        file = fopen("Coal.txt","r");

        fgets(information_from_the_file,50,file);



        sscanf(information_from_the_file,"%f",&information_from_the_file_float);

        coal_update = information_from_the_file_float - spent_coal;

        file = fopen("Coal.txt","w");

        fprintf(file,"%.2f",coal_update);

        printf("The current amount of carbon in kg %.2f\n",coal_update);

        fclose(file);



        break;

        case'3':

        file = fopen("Coal.txt","w");

        fprintf(file,"0");

        fclose(file);

        printf("The amount of Coal you have has been reset\n");

        break;

        case'4':

        return;

        break;

    }


    return 0;
}
