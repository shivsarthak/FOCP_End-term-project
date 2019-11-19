//
//  main.c
//  FOCP
//
//  Created by Shiv Sarthak Sabhlok on 18/11/19.
//  Copyright © 2019 Shiv Sarthak Sabhlok. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void newNotice()
{
    FILE *fptr;
    fptr=fopen("notice.txt", "w");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }
}


void createUID(){                   //Create Unique user ID for user
    
}
struct staffUserDetails{
    char name[30];
    char UID[12];
    int age;
    int staffCode;
    char pass[5];
    
};
struct stUserDetails{               //structure to hold student details
    char name[30];
    char UID[12];
    int age;
    int admNo;
    char pass[5];
};
void registerStudent()                  //function to take student details and update the staff database
{   struct stUserDetails st;        //structure variable to store data for student which
                                    //will further be written in binary file
    int p=0;
    FILE *stDt;
    printf("\nSchool Bus Management System\n\t\t\tRegister User (Student)\n");
    printf("\nFull Name:");
    scanf("%s",st.name);
    printf("\nAge:");
    scanf("%d",&st.age);
    printf("\nAdmission Number:");
    scanf("%d",&st.admNo);
    printf("\nInput password(4 characters):");
    do {

        st.pass[p]=getch();
        if(st.pass[p]!='\r')
            {
            printf("*");
        }

        p++;
        if(p==4)
            break;
    } while(st.pass[p-1]!='\r');
    st.pass[4]='\0';
    
    if((stDt=fopen("/studentData.bin","wb"))==NULL){
        printf("\nError Opening the file exiting program");
        exit(1);
    }
    else{
    fwrite(&stDt, sizeof(struct stUserDetails), 1, stDt);
        fclose(stDt);
        printf("\nSuccessfully Updated the database");
    }
}

void registerSaff()                 //function to take input the staff details and update the staff databse
{   struct staffUserDetails st;        //structure variable to store data which
                                        //will further be written in binary file
    int p=0;
    FILE *stDt;
    printf("\nSchool Bus Management System\n\t\t\tRegister User (Student)\n");
    printf("\nFull Name:");
    scanf("%s",st.name);
    printf("\nAge:");
    scanf("%d",&st.age);
    printf("\nStaff Code:");
    scanf("%d",&st.staffCode);
    printf("\nInput password(4 characters):");
    do {

        st.pass[p]=getch();
        if(st.pass[p]!='\r')
            {
            printf("*");
        }

        p++;
        if(p==4)
            break;
    } while(st.pass[p-1]!='\r');
    st.pass[4]='\0';
    
    if((stDt=fopen("/staffData.bin","wb"))==NULL){
        printf("\nError Opening the file exiting program");
        exit(1);
    }
    else{
    fwrite(&stDt, sizeof(struct stUserDetails), 1, stDt);
        fclose(stDt);
        printf("\nSuccessfully Updated the database");
    }
}

void registerScreen(){              //function to show register menu
    int ch,ex=1;
    while(ex){
    printf("School Bus Management System\n\t\t\tRegister User\n1.Staff\n2.Student\nChoice:");
    scanf("%d",&ch);
    switch(ch)      //check choice
    {
        case 1:
            ex=0;
            break;
        case 2:
            ex=0;
            break;
        default:
            printf("\nWrong Choice Try Again\n");
            ex=1;
            break;
    }
    }
}

void menu(){
    int ch,ex=1;         //choice variable
    while(ex){
    printf("School Bus Management System\n1.Login\n2.Register\nChoice:");
    scanf("%d",&ch);
    switch(ch)      //check choice
    {
        case 1:
            ex=0;
            break;
        case 2:
            registerScreen();
            ex=0;
            break;
        default:
            printf("\nWrong Choice Try Again\n");
            ex=1;
            break;
    }
    }
    
}

int main() {
    menu();         //call main menu
    return 0;
}


