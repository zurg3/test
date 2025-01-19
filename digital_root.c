#include <stdio.h>

int digital_root(int n) {
  return (n - 1) % 9 + 1;
}

int main() {
  int num;

  printf("Number: ");
  scanf("%d", &num);

  printf("%d\n", digital_root(num));

  return 0;
}
