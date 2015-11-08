/* sorts an array data in ascending order. reads from input */

int max;

int data[10];             /*array of 10 elements--index 0 thru 9*/
int i;
int j; int mindex; int tmp;

void main(void)
{
   i = 0;
   max = 9;
   j = 9;
   /*loop to read*/
   /* let user know how many elements */
   printf("%d\n", 10);
   while (i <= max) 
   {
      scanf("%d", &tmp);
      data[i] = tmp;
      j = j - 1;
      i = i + 1; 

   }    /*read loop*/

   i = 0;

   /*loop through whole array*/
   while (i <= max) 
   {     /*outer loop*/
      mindex = i;
      j = i + 1;

      /*find index of the minimum*/
      while (j <= max) 
         {     /*inner loop*/
            if (data[j] < data[mindex])
                    mindex = j;
            else mindex = mindex;
            j = j + 1;
         }    /*inner loop*/

      /*swap the current element with the minimum*/
      tmp = data[mindex];
      data[mindex] = data[i];
      data[i] = tmp;
      i = i + 1;
   }    /*outer loop*/

   i = 0;

   /*loop to print*/
   while (i <= max) 
      {
      printf("%d\n", data[i]);
      i=i+1;
      }
}    /*of program*/




