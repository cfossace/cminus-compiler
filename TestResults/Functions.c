int i;

int a[10];

int f(void){
  int y;
  y = 2;
  y = y + 300;
  return y;
}

int g(int b, int c[]){
  int z[5];
  z[2]= b+ c [3];
  return z[2];
}

void main (void){
  int w; 
  
  w = f();
  w = g(i,a);
}
