#include <stdio.h>

int main() {
  if (sizeof(void*) == 4) {
    printf("32-bit\n");
  }
  else if (sizeof(void*) == 8) {
    printf("64-bit\n");
  }
  else {
    printf("Something is wrong!\n");
  }

  return 0;
}
