#include <stdio.h>
#include <time.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD 20
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void create_account()
{
    FILE *outfile;

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

void acc_login()
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

int main()
{
    acc_menu();

    return 0;
}
