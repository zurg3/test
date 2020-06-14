#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
  for (int i = 0; i <= 100; i++) {
    if (i == 100) {
      cout << "\rLoading: " << i << "%" << endl;
      fflush(stdout);
      usleep(80000);
    }
    else {
      cout << "\rLoading: " << i << "%";
      fflush(stdout);
      usleep(80000);
    }
  }

  return 0;
}
