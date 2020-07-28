#include <iostream>
using namespace std;

int main() {
  int *a = new int;
  int *b = new int(5);
  int *c = new int;

  *a = 10;
  *c = *a + *b;

  cout << *a << " + " << *b << " = " << *c << endl;

  delete c;
  delete b;
  delete a;

  return 0;
}
