#include <iostream>
using namespace std;

int main()
{
  int a;
  int b;
  int c;

  cout << "Первое число: ";
  cin >> a;
  cout << "Второе число: ";
  cin >> b;

  if (a < b)
  {
    c = a / b;

    cout << "Результат: " << c << endl;
  }
  else
  {
    cout << a << " больше, чем " << b << endl;
  }
  return 0;
}
