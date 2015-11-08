/* *************************************************
          Bubble Sorting Algorithm Example
          --------------------------------
Program takes a hardcoded array of certain numbers
and sorts them using a simple bubble sort algorithm

************************************************** */

int max;

/* **************************************************************
                      The Bubble Sort Function
                      ------------------------
The function consists of nested loops and sifts through the array swapping 
pairs of numbers over and over again until it is finally sorted.
When it makes it's first pass, it compares the first two numbers
(or elements) of the array. If the first number is greater than
the second number, it is swapped with that number. Then it 
compares the second and third numbers (or elements) of the array. 
If the second number is greater than the third, it is swapped with
that number. It continues down the line until it has gone through
the entire array. Then it makes another pass through it doing
the same thing. It makes a pass for each element. So if an array
has 8 elements, the array will be sifted through 8 times. 
The function takes 2 arguments--the array itself(int a[]) and 
the number of elements in the array(int n). 
************************************************************** */
void bubbleSort( int a[], int n )  
{   
  int i; int j; int tmp;
  i = 0;
  while (i < n)   
    {   
      j = 1;
      while (j < (n-i))
        {              
	  if(a[j-1] > a[j]) 
	    {/* swap */
	      tmp = a[j-1];
	      a[j-1] = a[j];
	      a[j] = tmp;
	    } else ;
	  j = j + 1;
        }
      i = i + 1;
    }
}

void printArray(int a[]) 
{
  int i;
  i = 0;
  while (i < max) 
    {
      printf("%d\n", a[i]);
      i = i + 1;
    }
}

void main(void) 
{
   int array[8];
   max = 8;
   /* initialize array */
   array[0] = 12; array[1] = 9; array[2] = 4; array[3] = 99;
   array[4] = 120;  array[5] = 1; array[6] = 3; array[7] = 10;
   
   printArray(array);        /* print before sorting */
   bubbleSort(array, max);        /* sort the array */
   printArray(array);      /* print after sorting */ 
} 

          
