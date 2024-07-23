#include <stdio.h>
#include "stack.h"

int main(void) {
  stack_t a, b;
  for (int i = 0; i < 32; i++) {
    a = stack_push(a, i);
  }

  int c;
  while(a = stack_pop(a, &c)) {
    printf("%d\n", c);
  }

  return 0;
}
