int x;
int y;
void main(void) {
  y = 1;
  x = 5;
  while (x) {
    y = y * 2;
    x = x - 1;
   
  }
  printf("%d\n", y); /* should print 2^5 that is 32 */
}
