#include <stdio.h>
#include <stdlib.h>

// DEFINE COLOR
#define BLUE "\033[7;34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// FUNCTIONS PROTOTYPE
void header();
void choices();
void pause();
void clear();
int basic_operation(int choice, float num1, float num2, float *result);
int main()
{
    int choice;
    float num1, num2, result;
    char history[10][30];
    char op[] = "+-*/";
    int count = 0;

    while (1)
    {
        // PRINT HEADER
        header();
        // PRINT CHOICES
        choices();

        // PRINT HISTORY
        printf(YELLOW "          HISTORY     \n");
        printf("---------------------------\n" RESET);

        if (count == 0)
        {
            printf("(Empty)\n");
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                printf(GREEN "%d) %s \n" RESET, i + 1, history[i]);
            }
        }

        // CHOOSE OPTION
        printf("Choose an option: ");
        scanf("%d", &choice);

        // CHOICES CONDITON
        if (choice < 1 || choice > 5)
        {
            printf(RED "INVALID INPUT..." RESET);
            return 0;
        }
        else if (choice == 5)
        {
            return 0;
        }

        // READ FIRST AND SECOND NUMBER
        printf("enter first num: ");
        scanf("%f", &num1);
        printf("enter second num: ");
        scanf("%f", &num2);

        // BASIC OPERATION CONDITION
        if (basic_operation(choice, num1, num2, &result) != 1)
        {
            printf(RED "Can not devided by zero \n" RESET);
            return 0;
        }

        // STORE RESULT IN HISTORY
        if (count < 10)
        {
            sprintf(history[count], "%.2f %c %.2f = %.2f", num1, op[choice - 1], num2, result);
            count++;
        }

        // PRINT RESULT
        printf(GREEN "Result: %.2f \n\n" RESET, result);
        // PAUSE THE SCREEN
        pause();
        // CLEAR THE SCREEN
        clear();
    }
    return 0;
}

//  CALCULATOR HEADER
void header()
{
    printf(BLUE "\t\t\t\t :---------------------------: \n");
    printf("\t\t\t\t |      Basic Calculator     | \n");
    printf("\t\t\t\t :---------------------------: \n" RESET);
}

// PRINT CHOICES
void choices()
{
    printf(" 1. Addition\t\t(+) \n 2. Subtraction\t\t(-) \n 3. Multiplication\t(*) \n 4. Division\t\t(/) \n 5. Exit\n");
}

// PAUSE THE SCREEN
void pause()
{
    printf("Press enter to continue: ");
    getchar();
    getchar();
}

// CLEAR THE SCREEN
void clear()
{
    if (_WIN32)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}

// BASIC OPERATIONS
int basic_operation(int choice, float num1, float num2, float *result)
{
    switch (choice)
    {
    case 1:
        *result = num1 + num2;
        return 1;
    case 2:
        *result = num1 - num2;
        return 1;
    case 3:
        *result = num1 * num2;
        return 1;
    case 4:
        if (num2 == 0)
        {
            return 0;
        }
        else
        {
            *result = num1 / num2;
            return 1;
        }
    }
    return 0;
}
