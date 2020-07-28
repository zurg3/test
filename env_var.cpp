#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << "$USER: " << getenv("USER") << endl;
  cout << "$HOME: " << getenv("HOME") << endl;
  cout << "$PWD: " << getenv("PWD") << endl;
  cout << "$SHELL: " << getenv("SHELL") << endl;
  cout << "$LANG: " << getenv("LANG") << endl;

  return 0;
}
