// a.c
#include <stdlib.h>
int main() {
volatile int x = 10, y = 20;
  int *p = malloc(sizeof(*p) * 10);
  free(p);
  *p = 0;
  return 0;
}
