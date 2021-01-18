#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int a, b, x, y;

  cout << "Enter min value in array: ";
  cin >> a;
  cout << "Enter max value in array: ";
  cin >> b;
  cout << "Enter array size [↓]: ";
  cin >> x;
  cout << "Enter array size [→]: ";
  cin >> y;

  int random_multi_array[x][y];

  srand(time(NULL));

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      //random_multi_array[i][j] = a + rand() % b;
      random_multi_array[i][j] = a + (rand() % (b - a + 1));
    }
  }

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (to_string(a).length() == to_string(b).length()) {
        cout << random_multi_array[i][j] << " ";
      }
      else {
        cout << random_multi_array[i][j] << "\t";
      }
    }
    cout << endl;
  }

  return 0;
}
