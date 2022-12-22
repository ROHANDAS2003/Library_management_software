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

    printf("Book added successfully");

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
    
    fclose(fp);
}
