/* Function to sum nums 0 through n */

int sum(int n)
{
    int c; int x; 
    x = 0;
    c = 0;
    while (c <= n) 
    { 
        x = x + c;
        c = c + 1;
    }
    return x;
}

void main(void)
{     
  printf("%d\n",sum(20)); /* should print 210 */
}


