int n;
int m;

int gcd(int first, int second)
{
   int result;
   if (second == 0)
           result = first;
   else
      if (first < second)
              result = gcd(first, second - first);
      else result = gcd(second, first - second);
   return result;
}    /*gcd*/

void main(void)
{     /*main*/
   n = 10;
   m = 15;
   printf("%d\n",gcd(n,m));

}
