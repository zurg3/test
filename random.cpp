#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int n, a, b, output_type;

  cout << "Enter array size: ";
  cin >> n;
  cout << "Enter min value in array: ";
  cin >> a;
  cout << "Enter max value in array: ";
  cin >> b;

  int random_array[n];

  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    //random_array[i] = a + rand() % b;
    random_array[i] = a + (rand() % (b - a + 1));
  }

  cout << "How do you want see the output? 1 - row, 2 - column: ";
  cin >> output_type;

  if (output_type == 1) {
    for (int i = 0; i < n; i++) {
      cout << random_array[i] << " ";
    }
    cout << endl;
  }
  else if (output_type == 2) {
    for (int i = 0; i < n; i++) {
      cout << random_array[i] << endl;
    }
  }
  else {
    cout << "Something is wrong!" << endl;
  }

  return 0;
}
