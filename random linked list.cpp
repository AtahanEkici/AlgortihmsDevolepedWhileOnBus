#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

typedef struct LINKED_LIST
{
    int data;
   struct LINKED_LIST * next;
}node;

typedef time_t taym;
typedef int counter;
typedef unsigned int uint;

void addtolast(node *b , int c);
void display(node *r);
void addtofirst(node *n , int a);
void addtoposition(node *n , unsigned int a , int data);
void deleteatposition(node *n , unsigned int a);
void mergelists(node *n , node *r);
void search(node *a , int b);
void quicksort(node *a , uint b);
void mergesort(node *a);
void bubblesort(node *a , uint b);
void shellsort(node *a , uint b , uint counter);
void swap(node *a , node *b);
bool IsEven(uint a);
void Sum(node *a);
void yinangsort(node *a , uint b);




int main()
{
    taym t;
    srand((unsigned) time(&t)) ; /* RNG */
    
    node * root;
    node * root2;
    
    root = (node*)malloc(sizeof(node));
    root2 = (node*)malloc(sizeof(node));
    
    node * iter = root;
    node * iter2 = root2;
    
     uint counter = 1;
    
    while(counter < rand() %1000)
    {
iter -> next =(node*)malloc(sizeof(node));
iter2 -> next =(node*)malloc(sizeof(node));
        
        iter -> data = rand() %1000;
        iter2 -> data = rand() %1000;
        
        iter = iter -> next;
        iter2 = iter2 -> next;
        
        counter++;
    }
   
    addtoposition(root , 5 , 1111);
    addtofirst(root , 1111);
    addtolast(root , 1111);
    deleteatposition(root , 3);
    search(root , 1111);
    
    display(root);
    puts(" \n AFTER SHELLSORT \n ");
    shellsort(root , 1 , counter);
    display(root);
    
    puts(" \n ------------- \n ");
    
    display(root2);
    puts(" \n AFTER BUBBLESORT \n ");
    bubblesort(root2 , counter);
    display(root2);
    
    Sum(root);
    Sum(root2);
}

void Sum(node *a)
{
    node *iter;
    iter = (node*)malloc(sizeof(node));
    iter = a;
    int sum = 0;
    
   while(iter != NULL)
    {
        sum = sum + iter -> data;
        iter = iter -> next;
    }
    
    printf("\n Sum is : %d \n" , sum);
}

void display(node *r)

{
   unsigned int ctr = 1;
    
    while(r -> next != NULL)
{
      printf(" %d-) %d\n" , ctr , r -> data);
        ++ctr;
      r = r -> next;
}
}

void addtofirst(node *n , int a)
{
 node *temp = (node*)malloc(sizeof(node));
    temp = n;
    temp -> next = n -> next;
    temp -> data = a;
}

void addtolast(node *b , int c)
{
 node *temp = (node*)malloc(sizeof(node));
    
    
    bool complete = false;
    
    while( complete == false)
    {
        if(b -> next == NULL)
        {
            b -> data = rand () %1000;
            b -> next =(node*)malloc(sizeof(node));
            temp -> next = b -> next;
            b -> next = temp;
            temp -> data = c;
            complete = true;
        }
        
        else
        {
            b = b -> next;
        }
    }
   
}

void swap(struct LINKED_LIST  *a , struct LINKED_LIST *b)
{
    struct LINKED_LIST *c;
    struct LINKED_LIST *d;
    c = (node*)malloc(sizeof(node));
    d = (node*)malloc(sizeof(node));
    
    c -> data = a -> data;
    d -> data = b -> data;
    
    a -> data = d -> data;
    b -> data = c -> data;
    
}
void addtoposition(node *n , unsigned int a , int data)
{
 node *temp = (node*)malloc(sizeof(node));
  uint ctr = 1;
 bool complete = false;
    
 while(complete == false)
    {
      
        if(ctr == a)
        {
            
            temp -> next = n -> next;
            n -> next = temp;
            temp -> data = data;
            complete = true;
        }
        
        else
        {
            ++ctr;
            n = n -> next;
        }
    }
    }

void deleteatposition(node *n , unsigned int a)
{
        
 unsigned int ctr = 1;
 bool complete = false;
        
     while(complete == false)
        {
            if(ctr == a)
            {
            
           n -> data = 0;
            printf("\n %d. değer başarıyla silindi\n" , a);
           n -> next = n -> next -> next;
           complete = true;
            }
            
            else
            {
                ctr++;
                n = n -> next;
            }
        }

}

void mergelists(node *n , node *r)
{
    bool atlast = false;
    
while (atlast == false)
    {
        if (n -> next == NULL)
        {
            n -> next = (node*)malloc(sizeof(node));
            n -> next = r;
            
        }
        
        else
        {
            n = n -> next;
        }
    }
}

void search(node *a , int b )
    {
        node *iter = a;
        int c = 0;
    
        while(iter -> next != NULL)
    
        {
            if( b == iter -> data)
        {
            c++;
            iter = iter -> next;
            
        }
        
        else
        
        {
            iter = iter -> next;
        }
            }
    
    
    if(c == 0)
    {
        puts("\nNOT FOUND\n");
    }
    
    else 
    {
    printf("\nThe value %d have been found %d times in this list\n" , b , c);
}
    
    
}

bool IsEven(uint a)
{
    if(a % 2 == 0)
    {
        return false;
    }
    
    else 
    {
        return true;
    }
    
}
    

void bubblesort(node *a , uint b )
  {
    
    taym simdi = clock();
    
    double time_spent;
    
       node *prev;
       node *current;
 
    current = (node*)malloc(sizeof(node));
    prev = (node*)malloc(sizeof(node));
    
    prev = a;
    current = a -> next;
    
    uint ctr1 = b;
    
      while(ctr1 != 0)
    {
        if(current -> next == NULL)
        {
            ctr1--;
            prev = a;
            current = a -> next;
        }
           
        else if(prev -> data > current -> data)
        {
            swap(prev , current);
            prev = prev -> next;
            current = current -> next;
        }
        
        else
        {
            prev = prev -> next;
            current = current -> next;
        }
    } 
    
    taym sonra = clock();
    
    time_spent = (double) (sonra - simdi) / CLOCKS_PER_SEC;
    
    printf("\n It took %f seconds \n\n" , time_spent);
    
  }

/*
void quicksort(node *a , uint b)
    {
    
    float time_spent;
    taym once = clock();
    
    node *pivot;
    pivot = (node*)malloc(sizeof(node));
    
    node *biter;
    biter = (node*)malloc(sizeof(node));
    
    node *siter;
    siter = (node*)malloc(sizeof(node));
    
    uint ctr1;
    uint ctr2;
    
    
    
    pivot = a;
    
        if(IsEven(b) == true)
    {
        while(pivot -> data  ==! b / 2)
        {
            pivot = pivot -> next;
        }
        ctr1 = b / 2;
        ctr2 = ctr1;
    }
        else
        {
      while(pivot -> data ==! (b+1) / 2)
            {
                pivot = pivot -> next;
            }
        
        ctr1 = (b + 1) / 2;
        ctr2 = ctr1;
        }
    
    biter = a;
    siter = pivot;
    
   
  

    taym sonra = clock();
    time_spent = (float)(sonra - once) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n" , time_spent);

    } */

void shellsort(node *a , uint b , uint c)
{
    taym once = clock();
    float time_spent;
    
    node *before;
    node *current;
    uint ctr1 = 1;
    
    before = (node*)malloc(sizeof(node));
    current = (node*)malloc(sizeof(node));
    
    before = a;
    current = a -> next;
    
    while(current != NULL)
    {
        
        if(b == 1)
        {
            bubblesort(a , c);
            break;
        }
        
       else if(ctr1 ==! b)
        {
            ctr1++;
            current = current -> next;
        }
        
        else if(ctr1 == b)
        {
    if(before -> data > current -> data)
            {
               swap(before , current);
               before = current;
               ctr1 = 1;
            }
            
            else
            {
                before = current;
                current = current -> next;
                ctr1 = 1;
            }
        }
        
        else
        {
           current = current -> next;
            ctr1++;
        }
 }
    
    taym sonra = clock();
    time_spent = (float)(sonra - once) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n" , time_spent);
    

}

/*
void yinangsort(node* a , uint b)
{
    node *iter;
    node *max;
    node *min;
    
    uint ctr1 = b;
    
    iter = (node*)malloc(sizeof(node));
    max = (node*)malloc(sizeof(node));
    min = (node*)malloc(sizeof(node));
    
    iter = a;
    max = a;
    min = a;
    
    while(ctr1 ==! 0)
    {
        if()
        {
        
    }
    }
}
*/