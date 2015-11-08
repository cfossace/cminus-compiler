int x;

int f(int x)
{
   int result;
   if (x <= 1)  
        result = 1; 
    else 
        result = x * f(x-1);
   return result;
}    /* f */


void main(void)
{
   x = 5;
   printf("%d\n", f(x));
}
