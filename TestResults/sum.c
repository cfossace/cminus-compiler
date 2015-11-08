/* Sum integers 0 thru x */

int x; int count; int ans;

void main(void)
{
   x = 10;
   ans = 0;
   count = 0; 
   
   while (count <= x) 
   {
      ans = ans + count;
      count = count + 1;
   }
   printf("%d\n", ans);


}    /*of program*/

