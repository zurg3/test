#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int i;

  cout << "Argc: " << argc << "\n" << endl;

  cout << "Argv:" << endl;
  for (i = 0; i < argc; i++) {
    cout << i << " - " << argv[i] << endl;
  }

  return 0;
}
