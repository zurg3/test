#include <stdio.h>
#include <unistd.h>

int main() {
  for (int i = 0; i <= 100; i++) {
    if (i == 100) {
      printf("\rLoading: %d%%\n", i);
      fflush(stdout);
      usleep(80000);
    }
    else {
      printf("\rLoading: %d%%", i);
      fflush(stdout);
      usleep(80000);
    }
  }

  return 0;
}
