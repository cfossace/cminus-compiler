int x;

void f(int a) {
  x = a;
}

void main(void) {
  f(20);
  printf("%d\n", x); 
}
