#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef long int lint;
typedef struct LinkedList
{
    long int data;
   struct LinkedList * next;
}node;


bool IsSpecialNumber(lint a);
lint ustu(long int a , long int b);
bool IsDevisableTo(int a , int b);
void Pascal(lint a);
lint faktoriyel(long int a);
lint logarithm(long int a , long int b);
bool Isprime(long int a);
lint Sumofnode(node *a);
bool IsEven(long int a);
lint ebob(long int a , long int b);
lint ekok(long int a , long int b);
void fibonacci(long int a);
lint findmin(long int a , long int b);
lint findmax(long int a , long int b);
void squarenumbers(long int a);
void triangularnumbers(long int a);
bool IsSmithNumber(long int a);
void divisor(long int a);
bool IsArmstrongNumber(long int a);
lint triple(lint a);
bool IsAmicableNumber(lint a , lint b);
void ArithmeticNumber(lint a , lint b , lint c);
void GeometricNumber(lint a , lint b , lint c);
lint Combination(lint a , lint b);


int main(void)
{
   
    printf("\n%ld\n" , ustu(4,5));
    
    printf("\n%d\n" , IsDevisableTo(10, 5));
    
    printf("\n%ld\n" , faktoriyel(7));
    
    printf("\n%ld\n" , logarithm(4,16));
    
    puts("Fibonacci");
    fibonacci(30);
    puts("\nFibonacci");
    
   printf( "\n\n%ld\n" , findmax(120 , 1121));
    
    printf("\n %ld \n" , ebob(91,287));
    
    printf("\n %ld \n" , ekok(45 , 24));
    
    printf("\n %ld \n" , ebob(45,24));
    
    puts("Square Numbers");
    squarenumbers(10);
    puts("Square Numbers");
    
    puts("Triangular Numbers");
    triangularnumbers(10);
    puts("Triangular Numbers");
    
    printf("\n");
    
    printf("%d", Isprime(3));
    
    printf("\n\n");
    
    puts("divisor");
    
    printf("\n");
    
    divisor(92);
    
    printf("\n");
    
    printf("%d" , IsSmithNumber(378));
    
    printf("\n");
    
    printf("\n%d" , IsArmstrongNumber(371));
    
    printf("\n");
    
    printf("\n%d\n" , IsAmicableNumber(200,244));
    
    printf("\n");
    
    printf("\n%d" , IsSpecialNumber(29));
    
    printf("\n");
    
    puts("\n\nArithmetic");
    
    ArithmeticNumber(5 , 3 , 20);
    
    puts("\nGeometric");
    
    GeometricNumber(3 , 7 , 10);
    
    puts("\n ------ PASCAL ------ \n");
    
    Pascal(7);
}

void Pascal(lint a)
{
    lint counter = a;
    
    if(a == 1 )
    {
        puts("\n1");
    }
    
    else if(a == 2)
    {
        puts("1\n1");
    }
    
    else if(a == 3)
    {
        puts("1\n2\n1");
    }
    
    else
    {
       while(counter >= 0)
    {
printf(" %ld",Combination(a,counter));
    counter--;
    }
   }
}

lint Combination(lint a , lint b)
{
    lint temp = a - b;
    
    lint temp2 = faktoriyel(b) * faktoriyel(temp);
    
    lint result = faktoriyel(a) / temp2 ;
    
    return result;
}

void GeometricNumber(lint a , lint b , lint c)
{
    lint counter = 1;
    
    while(counter <= c)
    {
       printf("\n %ld)%ld \n",counter , a);
       a = a * b;
       counter++;
    }
}


void ArithmeticNumber(lint a , lint b , lint c)
{
    // a başlangıç , b katsayı , c bitiş sayısı//
    
    lint counter = 1;
    while(counter <= c)
    {
        printf("\n  %ld)%ld \n " , counter , a);
        a = a + b;
        counter++;
    }
}

bool IsSpecialNumber(lint a)
{
    lint sum = 0;
    lint product = 1;
    lint value = a;
    
    while(a > 0)
    {
        sum = sum + (a % 10);
        product = product * (a % 10);
        a = a / 10;
    }
    
    if(sum + product == value)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}


bool IsAmicableNumber(lint a , lint b)
{
    lint sumof1 = 0;
    
    lint counter = 1;
    
    lint min = findmin(a , b);
    
    lint sumof2 = 0;
    
    while(counter < findmax(a , b))
    {
        if( a % counter == 0)
        {
            sumof1 = sumof1 + counter;
        }
        
        if(b % counter == 0)
        {
            sumof2 = sumof2 + counter;
            counter++;
        }
        
        else
        {
            counter++;
        }
    }
    
    if(min == a)
    {
       sumof1 = sumof1 - a;
    }
    
    else
    {
        sumof2 = sumof2 - b;
    }
    
    if(sumof1 == b && sumof2 == a)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

bool IsArmstrongNumber(long int a)
{
    lint sum = 0;
    
    lint temp = a;
    
    while(a > 0)
    {
        sum = sum + triple(a%10);
        a = a / 10;
    }
    
    if(sum == temp)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}


bool IsEven(long int a)
{
    if(a % 2 == 0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

void divisor(long int a)
{
    node * root;
    
    root = (node*)malloc(sizeof(node));
    
    node * iter = root;
    
    long int counter = 2;
    
    while(counter <= a)
    {
        if(a % counter != 0)
        {
           counter++;
        }
        
        else
        {
            iter -> next = (node*)malloc(sizeof(node));
            iter -> data = counter;
            iter = iter -> next;
            counter++;
        }
    }
    iter = root;
    
    while(iter -> next != NULL)
    {
        printf("\n%ld\n" , iter -> data);
        iter = iter -> next;
    }
}

bool IsSmithNumber(long int a)
{
    lint sum1 = 0;
    lint sum2 = 0;
    lint result1 = a;
    lint counter = 2;
    lint result2 = a;
    
    while(result1 != 1)
    {
        if(result1 % counter == 0)
        {
            sum1 = counter + sum1;
            result1 = result1 / counter;
        }
        
        else
        {
            counter++;
        }
    }
    
    while(result2 > 0)
    {
        sum2 = sum2 + (result2 % 10);
        result2 = result2 / 10;
    }
    
    if(sum1 == sum2)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

lint triple(lint a)
{
    a = a * a * a;
    return a;
}

bool Isprime(long int a)
{
   long int counter = 2;
    
   while(counter < a)
    {
        if(a % counter == 0)
        {
            printf("\n %ld divides at %ld\n\n" , a ,counter);
           return 0;
        }
        
        else
        {
            counter++;
        }
    }
    return 1;
}

void triangularnumbers(long int a)
{
    long int ctr = 1;
    
    while(ctr <= a)
    {
        
    long int ctr2 = ctr + 1;
    long int fct = ctr * ctr2;
        
        printf("\n %ld " , fct / 2);
        ctr++;
    }
    printf("\n");
}

void squarenumbers(long int a)
{
    long int counter = 1;
    
    while(counter < a)
    {
        printf("\n %ld" , counter * counter);
        counter++;
    }
    printf("\n");
}

long int ekok(long int a , long int b)
{
    long int result = 1;
    long int counter = 2;
    long int max = findmax(a,b);
    
    while(counter < max)
    {
        
         if(a == 1 || b == 1)
        {
            return result * a * b;
        }
        
       else if(a % counter == 0 && b % counter == 0)
        {
            result = result * counter;
            a = a / counter;
            b = b / counter;
        }
        
        else if(a % counter == 0)
        {
            result = result * counter;
            a = a / counter;
        }
        
        else if(b % counter == 0)
        {
            result = result * counter;
            b = b / counter;
        }
  
        else
        {
            counter++;
        }
    }
    return result;
}

long int ebob(long int a , long int b)
{
    long int min = findmin(a,b);
    long int max = findmax(a,b);
    long int counter = 2;
    long int result = 1;
    
    while(counter != max + 1)
    {
if(max % counter == 0 && min % counter == 0)
        {
            result = counter * result;
            min = min / counter;
            max = max / counter;
        }
        
        else
        {
           counter++;
        }
    }
    return result;
}

long int findmin(long int a , long int b)
{
    if(a < b)
    {
        return a;
    }
    
    else
    {
        return b;
    }
}

long int findmax(long int a , long int b)
{
    if(a > b)
    {
        return a;
    }
    
    else
    {
        return b;
    }
}
void fibonacci(long int a)
{
   lint before;
   lint after;
   lint aft; // temp //
   lint counter = 0;
    
    before = 0;
    after = 1;
    aft = after;
    
    while(counter <= a)
    {
        printf("\n%ld)%ld" ,counter, before);
        after = before + after;
        before = aft;
        aft = after;
        counter++;
    }
    printf("\n");
}

bool IsDevisableTo(int a , int b)
{
    if(a % b == 0)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

long int logarithm(long int a , long int b)
{
    long int counter = 0;
    
    if (a > b || b == 1)
    {
        return -1;
    }
    
    else if(a == 0 || b == 0)
    {
        return 0;
    }
    
    else if(a == 1)
    {
        return -1;
    }
    
    else if(b % a != 0)
    {
        return -1;
    }
    
    else
    {
        while(b >= a)
        {
            b = b / a;
            counter++;
        }
        return counter;
    }
}

lint faktoriyel(long int a)
{
   if(a < 0)
    {
        return (faktoriyel(a) * -1);
    }
    
    else if(a == 0 || a == 1)
    {
        return 1;
    }
    
    else
    {
        return a * faktoriyel(a-1);
    }
}


 long int ustu(long int a , long int b)
{
     long int ust = a;
     long int counter = b;
    
    if(a == 0 || b == 0)
    {
        return 0;
    }
    
    else if(b == 1)
    {
        return a;
    }
    
    else 
    {
        while(counter != 1)
    {
        --counter;
        ust = ust * a;
    }
    return ust;
    }
}
