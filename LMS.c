#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

struct books{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;

struct student
{
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
}s;

FILE *fp;

int main(){
    int ch;

    while (1)
    {
        system("CLS");
        printf("<=== Library Management system ===>\n\n");
        printf("Choose what you wanna do.\n");
        printf("1. Add book \n 2. Book list \n 3. Remove book \n 4. Issue book \n 5. Issued book list \n 6. Exit software. \n  : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addBook();
            break;
        
        case 2:
            bookList();
            break;
        
        case 3:
            dele();
            break;
        
        case 4:
            issueBook();
            break;
        
        case 5:
            issueList();
            break;
        
        case 6:
            exit(0);
            break;
        
        default:
            break;
        }
        printf("Press any ke to continue ...");
        getch();
    }

    return 0;    
}

