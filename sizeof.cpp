#include <iostream>
using namespace std;

int main() {
  cout << "| Data type | Size |" << endl;
  cout << "| --------- | ---- |" << endl;
  cout << "| bool      | " << sizeof(bool) << "    |" << endl;
  cout << "| char      | " << sizeof(char) << "    |" << endl;
  cout << "| short     | " << sizeof(short) << "    |" << endl;
  cout << "| int       | " << sizeof(int) << "    |" << endl;
  cout << "| long      | " << sizeof(long) << "    |" << endl;
  cout << "| float     | " << sizeof(float) << "    |" << endl;
  cout << "| double    | " << sizeof(double) << "    |" << endl;
  cout << "| string    | " << sizeof(string) << "   |" << endl;
  cout << "| --------- | ---- |" << endl;

  return 0;
}
