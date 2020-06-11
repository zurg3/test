#include <stdio.h>
#include <unistd.h>

int main() {
  for (int i = 0; i <= 100; i++) {
    printf("\rLoading: %d%%", i);
    fflush(stdout);
    usleep(80000);
  }

  return 0;
}
