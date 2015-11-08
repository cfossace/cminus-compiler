/* Procedure without any parameter. Sums nums 1 through 10 */

void sum(void)
{
    int n; int x; 
    x = 0;
    n = 1;
    while (n <= 10) 
    { 
        x = x + n;
        n = n + 1;
    }
    printf("%d\n", x);
}

void main(void)
{     /*main*/
  sum(); /* should print 55 */
}


