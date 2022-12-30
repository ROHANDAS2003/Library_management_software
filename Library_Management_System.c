#include <stdio.h>
#include <time.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD 20
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void add_books();
void search_books();
void delete_books();
void view_books();
void edit_books();
void delete_account();
void return_books();
void issue_books();
void view_issue();
void search_menu();
void search_author();
void search_category();
void create_account();

int IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

Date duedate;

// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    // check range of year,month and day
    if (validDate->yyyy > 9999 ||
        validDate->yyyy < 1000)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;

    // Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }

    // handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
        validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);

    return 1;
}

struct books
{
    int books_id;        // declare the integer data type
    char bookName[50];   // declare the character data type
    char authorName[50]; // declare the character data type
    int total_copy;
    int available;
    int book_status; // 1=active 0=inactive
    char category[30];
    int edition;
};

struct books_issue
{
    int books_id;       // declare the integer data type
    char studentID[50]; // declare the character data type
    Date Issue_date;
    Date return_date;
};

struct person
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
    int type_account;
    int status;
};

void printMessageCenter(const char *message)
{
    int len = 0;
    int pos = 0;

    // calculate how many space need to print
    len = (78 - strlen(message)) / 2;
    printf("\t\t\t");
    for (pos = 0; pos < len; pos++)
    {
        // print space
        printf(" ");
    }
    // print message
    printf("%s", message);
}

void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void create_account()
{
    FILE *outfile;

    headMessage("Create Account");
    struct person inp[50];
    int i = 0;

    // open file for writing
    outfile = fopen("account.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\n\n\n\t\t\t\tError opening file\n");
        exit(1);
    }

    printf("\n\n\n\t\t\t\tUsername:");
    scanf("%s", inp[i].username);

    printf("\n\t\t\t\tPassword:");
    scanf("%s", inp[i].password);

    inp[i].status = 1;
    // write struct to file

    fwrite(&(inp[i]), sizeof(struct person), 1, outfile);
    if (fwrite != 0)
        printf("\n\t\t\t\tcontents to file written successfully !\n");
    else
        printf("\n\t\t\t\terror writing file !\n");

    fclose(outfile);

    i = i + 1;
    getch();
    system("cls");
}

void delete_account()
{
    headMessage("CLOSE ACCOUNT");
    FILE *infile;
    struct person inp[50];
    struct person out[50];
    char username[30];
    int check_user;
    int i = 0;
    if (infile == NULL)
    {
        fprintf(stderr, "\n\n\n\t\t\t\tError opening file\n");
        exit(1);
    }

    printf("\n\n\n\t\t\t\tEnter Username for Closing account:  ");
    scanf("%s", username);

    // Open person.dat for reading
    infile = fopen("account.txt", "r+");
    int found = 0;

    while (fread(&(inp[i]), sizeof(struct person), 1, infile))
    {
        out[i] = inp[i];
        check_user = strcmpi(username, inp[i].username);
        if (inp[i].status)
        {
            if (!check_user)
            {
                printf("\n\n\t\t\t\t User Found !");
                found = 1;
                printf("\n\t\t\t\tUser Name = %s \n", inp[i].username);
                printf("\n\t\t\t\tType of Account = %d \n", inp[i].type_account);

                out[i].status = 0;
                // fseek(infile,i*sizeof(struct person),SEEK_SET);
                // fwrite(&inp,sizeof(struct person),1,infile);
                break;
            }
        }
        i++;
    }
    fclose(infile);
    if (!found)
        printf("\n\n\t\t\t\tUser Not Found");
    else
    {
        infile = fopen("account.txt", "w+");
        fwrite(&out, sizeof(struct person), i, infile);
    }
    getch();
    system("cls");
}

void menu_librarian()
{
    int choice = 0;
    do
    {
        headMessage("LIBRARIAN MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Book");
        printf("\n\t\t\t2.Search Book");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Edit Book");
        printf("\n\t\t\t5.Delete Book");
        printf("\n\t\t\t6.Issue Book");
        printf("\n\t\t\t7.Return Book");
        printf("\n\t\t\t8.View Issued Books");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_books();
            break;
        case 2:
            search_menu();
            break;
        case 3:
            view_books();
            break;
        case 4:
            edit_books();
            break;
        case 5:
            delete_books();
            break;
        case 6:
            issue_books();
            break;
        case 7:
            return_books();
            break;
        case 8:
            view_issue();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            // exit(1);
            getch();
            continue;
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
        }                  // Switch Ended
    } while (choice != 0); // Loop Ended
    getch();
}

void acc_login()
{
    FILE *infile;
    char login_username[30];
    char login_password[20];

    int pass_check, user_check;
    headMessage("ACCOUNT LOGIN");
    struct person inp[50];
    int c = 0, i = 0;

    infile = fopen("account.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\n\n\n\t\t\t\tError opening file\n");
        exit(1);
    }

    printf("\n\n\n\t\t\t\tUsername:");
    scanf("%s", login_username);

    printf("\n\t\t\t\tPassword:");
    scanf("%s", login_password);

    while (fread(&(inp[i]), sizeof(struct person), 1, infile))
    {
        // printf("%s,%s",inp[i].username,inp[i].password);
        user_check = strcmp(inp[i].username, login_username);
        pass_check = strcmp(inp[i].password, login_password);
        if ((!user_check) && (!pass_check) && (inp[i].status))
        {
            c = 1;
            printf("\n\n\t\t\t\tLogin successful !");
            time_t t; // not a primitive datatype
            time(&t);
            printf("\n\t\t\t\tYou are logging in at (date and time): %s", ctime(&t));
            getch();
            menu_librarian();
        }
        i++;
    }

    if (!c)
    {
        printf("\n\n\t\t\t\tLogin failed ,Retry !");
        getch();
    }
    fclose(infile);
}

void acc_menu()
{
    int choice = 0;
    do
    {
        headMessage("LOGIN ACCESS MENU");
        printf("\n\n\n\t\t\t1.Login");
        printf("\n\t\t\t2.Sign-Up");
        printf("\n\t\t\t3.Close Account");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            acc_login();
            break;
        case 2:
            create_account();
            break;
        case 3:
            delete_account();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n");
            time_t t; // not a primitive datatype
            time(&t);
            printf("\n\t\t\t\tYou are logging out at (date and time): %s", ctime(&t));
            getch();
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
        }                  // Switch Ended
    } while (choice != 0); // Loop Ended
}

void search_menu()
{
    int choice = 0;
    do
    {
        headMessage("SEARCH BOOKS MENU");
        printf("\n\n\n\t\t\t1.Search by Book Name");
        printf("\n\t\t\t2.Search by Author Name");
        printf("\n\t\t\t3.Search by Category");
        printf("\n\t\t\t0.Back to Main Menu");
        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            search_books();
            break;
        case 2:
            search_author();
            break;
        case 3:
            search_category();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n");
            getch();
            continue;
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
        }                  // Switch Ended
    } while (choice != 0); // Loop Ended
}

void add_books()
{
    FILE *outfile;
    int i = 0;
    int num;
    headMessage("ADD BOOKS: ");
    struct books Book[50];
    char temp;
    // open file for writing
    outfile = fopen("book.txt", "a");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    // fseek(outfile,i*sizeof(struct books),SEEK_SET);
    do
    {
        printf("\n\n\n\t\t\t\tBook ID NO  (Integers Only)  = ");
        scanf("%d", &(Book[i]).books_id);
        num = (Book[i].books_id > 0) && (Book[i].books_id < 100001);
        // printf("\n%d",num);

        if (!num)
        {
            printf("\n\t\t\t\tEnter valid input");
            // scanf("%c",&temp);
            fflush(stdin);
        }
    } while (!num);

    printf("\t\t\t\tBook Name  = ");
    scanf("%c", &temp);
    scanf("%[^\n]", Book[i].bookName);
    // scanf("%s",Book[i].bookName);

    printf("\t\t\t\tAuthor Name  = ");
    scanf("%c", &temp);
    scanf("%[^\n]", Book[i].authorName);

    do
    {
        printf("\t\t\t\tTotal number of copies  (Integers Only) = ");
        scanf("%d", &(Book[i]).total_copy);
        num = (Book[i].total_copy > 0) && (Book[i].total_copy < 101);
        printf("\n%d", num);

        if (!num)
        {
            printf("\n\t\t\t\tEnter valid input");
            // scanf("%c",&temp);
            fflush(stdin);
        }
    } while (!num);

    Book[i].available = Book[i].total_copy;
    Book[i].book_status = 1;

    printf("\t\t\t\tCategory  = ");
    scanf("%c", &temp);
    scanf("%[^\n]", Book[i].category);

    do
    {
        printf("\t\t\t\tEdition  (Integers Only) = ");
        scanf("%d", &(Book[i]).edition);
        num = (Book[i].edition > 0) && (Book[i].edition < 100);
        printf("\n%d", num);

        if (!num)
        {
            printf("\n\t\t\t\tEnter valid input");
            // scanf("%c",&temp);
            fflush(stdin);
        }
    } while (!num);

    // write structures to file
    fwrite(&(Book[i]), sizeof(struct books), 1, outfile);

    if (fwrite != 0)
        printf("\n\t\t\t\tcontents to file written successfully !\n");
    else
        printf("\n\t\t\t\terror writing file !\n");
    fclose(outfile);
    i++;
    getch();
    system("cls");
}

void view_books()
{
    headMessage("VIEW BOOKS");
    FILE *infile;
    struct books Book;

    infile = fopen("book.txt", "r");

    int i = 1;
    if (infile == NULL)
    {
        fprintf(stderr, "\n\n\n\t\t\tError opening file\n");
        exit(1);
    }

    // fseek(infile,0,2);
    // size=ftell(infile);
    // printf("\n %d",size);
    printf("\n\n");
    while (fread(&Book, sizeof(struct books), 1, infile))
    {
        if (Book.book_status)
        {
            printf("\n\t\t\tSerial no. %d", i);
            printf("\n\t\t\t\tBook ID = %d ", Book.books_id);
            printf("\n\t\t\t\tBook Name = %s ", Book.bookName);
            printf("\n\t\t\t\tAuthor Name = %s ", Book.authorName);
            printf("\n\t\t\t\tCategory = %s ", Book.category);
            printf("\n\t\t\t\tEdition = %d ", Book.edition);
            printf("\n\t\t\t\tTotal copies = %d ", Book.total_copy);
            printf("\n\t\t\t\tAvailable Copies = %d ", Book.available);
            printf("\n");
            i++;
        }
    }
    fclose(infile);
    getch();
    system("cls");
}

int main()
{
    acc_menu();

    return 0;
}
