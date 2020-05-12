#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool IsExistsNegative(char a[]);
bool IsExistsPositive(char a[]);
void catcherNegative(char a[]);
void catcherPositive(char a[]);
bool checker(char a[]);
bool YesOrNo(char a[]);

int main()
{
    bool finished = false;

    while(finished == false)
    {
        char a[100];
        char b[2];

          puts("Enter an algebraic command line");
          fgets(a, 100, stdin);

          if(checker(a) == true)
          {
          catcherPositive(a);
          puts("Again?");
          fgets(b, 2, stdin);
          }
          else if(checker(a) == false)
          {
          catcherNegative(a);
          puts("Again?");
          fgets(b, 2, stdin);
          }
          else
          {
            puts("Input format: Operand1 Operator Operand2");
          }

          if(YesOrNo(b) == true)
          {
          fgets(a, 100, stdin);
          }

          else if(YesOrNo(b) == false)
          {
             finished = true;
          }

          else
          {
              puts("Error!!");
          }
}

}
bool checker(char a[])
{
    if(IsExistsPositive(a) == true )
   {
     return true;
   }

  else if(IsExistsNegative(a) == true)
   {
     return false;
   }
   else
   {
    return NULL;
   }

}

void catcherNegative(char a[])
{
char delim[] = "-";
char *ptr = strtok(a, delim);
int first;
int last;
first = atoi(ptr);
    if(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
		last = atoi(ptr);
	}
printf("Result: %d\n",CalculateNeg(first,last));
}

void catcherPositive(char a[])
{
char delim[] = "+";
char *ptr = strtok(a, delim);
int first;
int last;
first = atoi(ptr);
    if(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
		last = atoi(ptr);
	}
printf("Result: %d\n",CalculateSum(first,last));
}


bool IsExistsNegative(char a[])
{
    if(strstr(a,"-") != NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool YesOrNo(char a[])
{
  if(strstr(a,"Y") || strstr(a,"y") != NULL)
  {
    return true;
  }
  else if(strstr(a,"N") || strstr(a,"n")!= NULL)
  {
    return false;
  }
  else
  {
    puts("Error!!");
    return true;
  }
}

bool IsExistsPositive(char a[])
{
    if(strstr(a,"+") != NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int CalculateSum(int a , int b)
{
   return (a) + (b);
}

int CalculateNeg(int a , int b)
{
   return (a) - (b);
}


