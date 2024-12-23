/******************************************************************************

This program is a student record management system implemented in C. It allows users to add, delete, search, and sort records of students.

Each student record consists of a name, age, and grade. Here's a breakdown of the functionality.

Core Functions

1. Add
2. Display
3. Delete
4. Search
5. Sort
6. Swap

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Add(char Names[][20],int Ages[],float Grades[],int *count)
{

    printf("Enter Student name:");
    scanf("%s",&Names[*count]);


    printf("Enter Student age:");
    scanf("%d",&Ages[*count]);

    printf("Enter Student grades:");
    scanf("%f",&Grades[*count]);

    (*count)++;
    printf("Student added!\n");

}



void Display(char Names[][20],int Ages[],float Grades[],int count)
{

    if (count==0)
    {
        printf("Empty!");
        return;

    }
    for (int i=0; i<count ; i++){
        printf("%s\n", Names[i]);
        printf("%d\n", Ages[i]);
        printf("%f\n", Grades[i]);
        printf("\n");
    }
}




void Delete(char Names[][20], int Ages[], float Grades[], int count)
{

    printf("Enter the name of ss:\n");
    char ss_name[20];
    scanf("%s:",&ss_name);

    int index;
    for (int i=0;i<count; i++)
    {
        if (ss_name==Names[i])
        {
            index=i;
            break;

        }
    }


    for (int i=index; i<= count-2; i++)
    {
        strcpy(Names[i], Names[i+1]);
        Ages[i]=Ages[i+1];
        Grades[i]=Grades[i+1];
    }

    count--;

}



void  Search (char Names[][20], int Ages[], float Grades[], int count)
{

    printf("Enter the name of ss to be searched:\n");
    char ss_name[20];
    scanf("%s:",&ss_name);


    for ( int i=0; i< count ; i++)
    {

        if ( strcmp(Names[i], ss_name) == 0)
        {

            printf("Student is found\n!");
            printf("Student name is %s \n", Names[i]);
            printf("Student age is %d \n", Ages[i]);
            printf("Student grade is %f \n", Grades[i]);

        }


    }

    printf("The search was not sucessful!");

}


void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

void Sort(char Names[][20], int Ages[], float Grades[], int count){

    for( int i=0; i<count-1;i++)
    {
        for (int j=0;j<count-i-1;i++)
        {
            if (strcmp (Names[i] , Names[j]) > 0)
            {
                char temp[100];
                strcpy(temp,Names[i]);
                strcpy(Names[i],Names[j]);
                strcpy(Names[j],temp);

                //swap(&Names[i],&Names[j])
            }

        }
    }





}




int main() {

    int count;
    char Names[100][20];
    int Ages[100];
    float Grades[100];




    int choice;

    while (1)
    {

    printf("The operations are as follows:\n");

    printf("\n  1.Add & Display\n  2.Delete & display\n  3.Search\n  4.Sort & display ");
    printf("\n Please choose an operation:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("You chose the Add & Display operation:\n");
            Add(Names,Ages,Grades,&count);
            Display(Names,Ages,Grades,count);
            break;

        case 2:
            printf("You chose the delete & display operation:\n");
            Delete(Names,Ages,Grades,count);
            Display(Names,Ages,Grades,count);
            break;

        case 3:
            printf("You chose the search operation:\n");
            Search(Names,Ages,Grades,count);
            break;


        case 4:
            printf("You chose the sort operation:\n");
            Sort(Names,Ages,Grades,count);
            Display(Names,Ages,Grades,count);
            break;




        case 5:
            printf("Exit!");
            exit(0);

        default:
            printf("Invalid choice\n");

    }


    }


    return 0;










}
