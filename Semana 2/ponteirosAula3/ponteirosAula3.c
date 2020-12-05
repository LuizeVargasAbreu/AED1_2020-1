#include <stdio.h>
#include <stdlib.h>

void main()
{

  int t, j = 1, *p, *g;
  
  printf("\nT = %d\n", t);
  printf("J = %d\n", j);
  printf("P = %p\n", p);
  printf("G = %p\n", g);

  t = 5;
  p = &t;
  j = 3;
  g = &j;

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);

  *p = (*g + t) * 2;

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);

  *g = 4;

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);

  g = p;

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);

  for (j = 0; j < 2; j++)
  {
    *g = t * j + 1;
    printf("\nT = %d\n", t);
    printf("P = %p e P = %d\n", p, *p);
    printf("J = %d\n", j);
    printf("G = %p, e G = %d\n", g, *g);
  }

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);

  *p = t + j + *g;

  printf("\nT = %d\n", t);
  printf("P = %p e P = %d\n", p, *p);
  printf("J = %d\n", j);
  printf("G = %p, e G = %d\n", g, *g);
}
