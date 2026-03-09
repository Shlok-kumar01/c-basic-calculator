#include <stdio.h>
#include <stdlib.h>

// define colors
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// function prototype
void header();
void choices();
void pause();
int basic_operation(int choice, float num1, float num2, float *result);
int main()
{
    int choice;
    float num1, num2, result;
    header();

    char history[10][30];
    char op[] = "+-*/";
    int i = 0;
    int count = 1;

    while (1)
    {
        choices();

        //printing history
        printf(YELLOW "          HISTORY     \n");
        printf("---------------------------\n" RESET);
        for (int i = 0; i < count; i++)
        {

            printf(GREEN "%d) %s \n" RESET, i, history[i]);
        }

        // choose option
        printf("Choose an option: ");
        scanf("%d", &choice);

        // choice condition
        if (choice < 1 || choice > 5)
        {
            printf(RED "INVALID INPUT..." RESET);
            return 0;
        }
        else if (choice == 5)
        {
            return 0;
        }

        // taking num input
        printf("enter first num: ");
        scanf("%f", &num1);
        printf("enter second num: ");
        scanf("%f", &num2);
        
        //
        if (basic_operation(choice, num1, num2, &result) != 1)
        {
            printf(RED "Can not devided by zero \n" RESET);
            return 0;
        }

        //store result in history 
        if (count < 10)
        {
            sprintf(history[count], "%.2f %c %.2f = %.2f", num1, op[choice - 1], num2, result);
            count++;
        }
       

        // print result
        printf(GREEN "Result: %.2f \n\n" RESET, result);

        // pause the screen
        pause();
    }
    return 0;
}

//  Header
void header()
{
    printf(BLUE "\t\t\t\t |---------------------------|\n");
    printf("\t\t\t\t |      Basic Calculator     |\n");
    printf("\t\t\t\t |---------------------------|\n" RESET);
}

// user choices
void choices()
{
    printf(" 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division\n 5. Exit\n");
}

// pause the screen
void pause()
{
    printf("Press enter to continue: ");
    getchar();
    getchar();
}

// basic operations
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
