/* From Louden */
/* A program to perform Euclid's
   Algorithm to compute gcd. */

int gcd (int u, int v)
{ if (v == 0) return u;
  else return gcd(v,u-u/v*v);
  /* u-u/v*v == u mod v */
}

void main(void)
{ int x; int y;
  scanf("%d",&x);scanf("%d", &y);
  printf("%d\n", gcd(x,y));
}
