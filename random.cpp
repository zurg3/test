#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int n;
  int a;
  int b;
  int output_type;
  cout << "Enter array size: ";
  cin >> n;
  cout << "Enter the first num in the range: ";
  cin >> a;
  cout << "Enter the second num in the range: ";
  cin >> b;
  int random_array[n] {};
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    random_array[i] = a + rand() % b;
  }
  cout << "How do you want see the output? 1 - row, 2 - column: ";
  cin >> output_type;
  if (output_type == 1)
  {
    for (int i = 0; i < n; i++)
    {
      cout << random_array[i] << " ";
    }
    cout << endl;
  }
  else if (output_type == 2)
  {
    for (int i = 0; i < n; i++)
    {
      cout << random_array[i] << endl;
    }
  }
  else
  {
    cout << "Something is wrong!" << endl;
  }
  return 0;
}
