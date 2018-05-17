#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int x;
  int y;
  int a;
  int b;
  cout << "Enter the first num in the range: ";
  cin >> x;
  cout << "Enter the second num in the range: ";
  cin >> y;
  cout << "Enter array size [i]: ";
  cin >> a;
  cout << "Enter array size [j]: ";
  cin >> b;
  int random_multi_array[a][b] {{}};
  srand(time(NULL));
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      random_multi_array[i][j] = x + rand() % y;
    }
  }
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < b; j++)
    {
      cout << random_multi_array[i][j] << "\t";
    }
    cout << endl;
  }
  return 0;
}
