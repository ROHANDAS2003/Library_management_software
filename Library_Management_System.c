#include <stdio.h>
#include <time.h>
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD 20
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void create_account()
void delete_account()
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
