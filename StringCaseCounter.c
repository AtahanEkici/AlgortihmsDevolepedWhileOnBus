#include <stdio.h>
#include <string.h>
#include <ctype.h>

void LowerCaseCounter(char String[]);
void UpperCaseCounter(char String[]);
void DigitCounter(char String[]);
void OtherCharacters(char String[]);
void CallAllTypeFunctions(char String[]);

int main()
{
    char Array[200];

    puts("Input String:"); gets(Array);

    CallAllTypeFunctions(Array);

    char a;

    a = getchar();

    return 0;
}

void UpperCaseCounter(char String[])
{
    unsigned int counter = 0;
    unsigned int i;
    unsigned int len = strlen(String);

     for(i = 0;i<len;i++)
{
    if(isupper(String[i]) > 0)
        {
            counter++;
        }
}
    printf("\nContains: %u Capital Letter(s)\n",counter);

}

void LowerCaseCounter(char String[])
{
    unsigned int counter = 0;
    unsigned int i;
    unsigned int len = strlen(String);

    for(i = 0;i<len;i++)
{
    if(islower(String[i]) > 0)
        {
            counter++;
        }
}
    printf("\nContains: %u lower case letter(s)\n",counter);
}

void DigitCounter(char String[])
{
    unsigned int counter = 0;
    unsigned int i;
    unsigned int len = strlen(String);

    for(i = 0;i<len;i++)
{
    if(isdigit(String[i]) > 0)
        {
            counter++;
        }
}
    printf("\nContains: %u digit(s)\n",counter);
}

void OtherCharacters(char String[])
{
    unsigned int counter = 0;
    unsigned int i;
    unsigned int len = strlen(String);

    for(i = 0;i<len;i++)
{
    if(ispunct(String[i]) > 0)
        {
            counter++;
        }

    else if(isspace(String[i]) > 0)
        {
            counter++;
        }
}
    printf("\nContains: %u Other Character(s)\n",counter);
}

void CallAllTypeFunctions(char String[])
{
    UpperCaseCounter(String);
    LowerCaseCounter(String);
    DigitCounter(String);
    OtherCharacters(String);
}
