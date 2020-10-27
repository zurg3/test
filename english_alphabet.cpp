#include <iostream>
using namespace std;

int main() {
  for (char i = 'A'; i <= 'Z'; i++) {
    if (i != 'Z') {
      cout << i << " ";
    }
    else if (i == 'Z') {
      cout << i << endl;
    }
  }

  return 0;
}
