#include <stdio.h>

int counter() {
  int count = 0;

  count++;

  return count;
}

int static_counter() {
  static int static_count = 0;

  static_count++;

  return static_count;
}

int main() {
  unsigned short n;

  printf("Counter calls: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("counter() call #%d: %d\n", i, counter());
  }

  for (int j = 1; j <= n; j++) {
    printf("static_counter() call #%d: %d\n", j, static_counter());
  }

  return 0;
}
