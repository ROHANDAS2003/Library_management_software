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

void addBook(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%02d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("book.txt", "ab");

    printf("Enter the book id:  ");
    scanf("%d", &b.id);

    printf("Enter the book name:  ");
    fflush(stdin);
    gets(b.bookName);

    printf("Enter author's name:  ");
    fflush(stdin);
    gets(b.authorName);

    printf("Book added successfully\n\n");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}

void bookList(){

    system("CLS");
    printf("<=== Available books ===>\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book name", "Author name", "Date");

    fp = fopen("book.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %s\n\n", b.id, b.bookName, b.authorName, b.date);
    }
    
    printf("\n");

    fclose(fp);
}

void dele(){
    int id, f=0;

    system("CLS");
    printf("<=== Remove book ===>\n\n");
    printf("Enter the book id to remove:  ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("book.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (id == b.id)
        {
            f=1;
        }
        else{
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if (f==1)
    {
        printf("\n\n Deleted Successfully.\n\n");
    }
    else{
        printf("\n\nRecord not found.\n\n");
    }
    
    fclose(fp);
    fclose(ft);

    remove("book.txt");
    rename("temp.txt", "book.txt");
}

void issueBook(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%02d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int f = 0;

    system("CLS");
    printf("<=== Issue Book ===>\n\n");

    printf("Enter the book id to issue:  ");
    scanf("%d", &s.id);

    fp = fopen("book.txt", "rb");

    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if(b.id == s.id){
            strcpy(s.bookName, b.bookName);
            f = 1;
            break;
        }
    }

    if (f == 0)
    {
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }
    
    fp = fopen("issue.txt", "ab");

    printf("Enter the student name:  ");
    fflush(stdin);
    gets(s.sName);

    printf("Enter the student class:  ");
    fflush(stdin);
    gets(s.sClass);

    printf("Enter Student Roll:  ");
    scanf("%d", &s.sRoll);

    printf("Book Issued successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void issueList(){
    system("CLS");
    printf("<=== Issued Book List ===>\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "S.id", "Name", "Class", "Roll", "Book name", "Date");

    fp = fopen("issue.txt", "rb");
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", s.id, s.sName, s.sClass, s.sRoll, s.bookName, s.date);
    }

    printf("\n");
    
    fclose(fp);
}

int main(){
    int ch;

    while (1)
    {
        system("CLS");
        printf("<=== Library Management system ===>\n\n");
        printf("Choose what you wanna do.\n");
        printf(" 1. Add book \n 2. Book list \n 3. Remove book \n 4. Issue book \n 5. Issued book list \n 6. Exit software. \n  : ");
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
