#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "stack.h"
#include "pokemon_tables.h"
#include "pokecards.h"

stack_t very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(stack_t a, size_t sizehint);
int main(void) {
  srand(time(NULL));
  stack_t cards = NULL;
  size_t num_of_cards = 164;
  for (int i = 1; i <= num_of_cards; i++) {
    cards = stack_push(cards, i);
  }

  cards = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(cards, num_of_cards);
  cards = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(cards, num_of_cards);
  cards = very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(cards, num_of_cards);

  int c;
  while(cards = stack_pop(cards, &c)) {
    printf("%s\n", pokecard_repr_str_salloc(c));
  }

  return 0;
}

// likes to leave a small unsorted section in the top, call it multiple times to "fix" it
stack_t very_inefficient_but_respecting_of_the_stack_api_shuffle_algo(stack_t a, size_t sizehint) {
  size_t depth = 0;
  stack_t b = NULL;
  for (; a && depth < sizehint/2; depth++) {
    int val;
    a = stack_pop(a, &val);
    b = stack_push(b, val);
  }

  uint32_t choice;
  size_t needle = 0;
  stack_t result = NULL;
  while (a && b) {
    if (needle % (sizeof(choice) * 8) == 0) {
      choice = random();
    }
    printf("needle %d: %s%s\n" "%s\n" "%s\n" "%s\n",
        needle,
        (needle % (sizeof(choice) * 8) == 0)? "random call! ":"",
        (choice & 0b1)? "right" : "left",
        stack_debug_str_sall4(a),
        stack_debug_str_sall4(b),
        stack_debug_str_sall4(result)
      );
    int selv;
    if (choice & 0b1) {
      b = stack_pop(b, &selv);
    } else {
      a = stack_pop(a, &selv);
    }
    choice >>= 1;
    result = stack_push(result, selv);
    needle++;
  }
  // get any leftovers
  while (a) {
    int val;
    a = stack_pop(a, &val);
    result = stack_push(result, val);
  }
  while (b) {
    int val;
    b = stack_pop(b, &val);
    result = stack_push(result, val);
  }
  return result;
}
