#include <iostream>
#include "calc_new.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1 && argc == 4) {
    cout << argv[1] << "" << argv[2] << "" << argv[3] << "=" << calc(stof(argv[1]), *argv[2], stof(argv[3])) << endl;
  }

  return 0;
}
