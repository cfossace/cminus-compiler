int x;

void incX(void) {
  x = x + 1;
}

void main(void) {
  x = 1;
  incX();
  printf("%d\n", x); 
}
