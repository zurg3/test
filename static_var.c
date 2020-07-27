#include <stdio.h>

int counter() {
  int count = 0;
  
  count++;
  
  return count;
}

int static_counter() {
  static int count = 0;
  
  count++;
  
  return count;
}

int main() {
  printf("counter() call #1: %d\n", counter());
  printf("counter() call #2: %d\n", counter());
  printf("counter() call #3: %d\n", counter());
  
  printf("static_counter() call #1: %d\n", static_counter());
  printf("static_counter() call #2: %d\n", static_counter());
  printf("static_counter() call #3: %d\n", static_counter());

  return 0;
}
