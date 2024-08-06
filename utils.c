#include "utils.h"

uint64_t powil(uint8_t base, uint8_t exp) {
  uint64_t acc = 1;
  while(exp) {
    acc *= base;
    exp--;
  }
  return acc;
}
