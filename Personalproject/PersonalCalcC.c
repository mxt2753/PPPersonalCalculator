#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int InputValidQuest(const char *UserOInput);
double TheResult(const char *UserOInput);
int main() 
{
    char UserOInput[100];
    printf("A Calculator App\n");
    printf("Enter a math problem (ex,100 * 100)or 'exit' to quit:\n");
    while(1) 
    {
        fgets(UserOInput,100,stdin);
        UserOInput[strcspn(UserOInput,"\n")]=0; // Remove newline character
        if(strcmp(UserOInput,"exit")==0) 
        {
            break;
        }
        if (InputValidQuest(UserOInput)) 
        {
            double Outcome=TheResult(UserOInput);
            printf("Result: %.2f\n",Outcome);
        } else 
        {
            printf("Invalid input. Please enter a valid math problem.\n");
        }
        printf("\nEnter math problem or type 'exit' to quit:\n");
    }
    printf("Exiting Calculator App.\n");
    return 0;
}
int InputValidQuest(const char *UserOInput) 
{
    int Increment=0;
    int PrevIntger=0;
    int OPPrev=0;
    while (UserOInput[Increment]!='\0') 
    {
        if (isdigit(UserOInput[Increment])) 
        {
            PrevIntger=1;
        } 
        else if(UserOInput[Increment]=='+'||UserOInput[Increment]=='-'||UserOInput[Increment]=='*'||UserOInput[Increment]=='/') 
        {
            if(PrevIntger) 
            {
                OPPrev=1;
                PrevIntger=0; // Reset for second number
            } 
            else
            {
                // Operator without preceding digit
                return 0;
            }
        } 
        else if (!isspace(UserOInput[Increment])) // Has to deal if it's not a valid character
        {
            return 0;
        }
        Increment++;
    }
    return PrevIntger && OPPrev;
}
double TheResult(const char *UserOInput) 
{
    char OP;
    double NOne;
    double NTwo;
    sscanf(UserOInput,"%lf %c %lf",&NOne,&OP,&NTwo);
    switch (OP) 
    {
        case'+':
            return NOne+NTwo;
        case'-':
            return NOne-NTwo;
        case'*':
            return NOne*NTwo;
        case'/':
            if(NTwo!=0)return NOne/NTwo;
            printf("Error: / by Zero doesn't work.\n");
            return 0;
        default:
            printf("Invalid operation.\n");
            return 0;
    }
}
