// this program probably works only on Linux.

#include <iostream>
using namespace std;

int main()
{
  int timer, i, x;

  system("clear");
  cout << "Timer (seconds): ";
  cin >> timer;

  for (i = timer; i > 0; i--)
  {
    if (i >= 60)
    {
      x = i / 60;
      x = x + 1;
      if (x > 1)
      {
        system("clear");
        cout << x << " minutes (" << i << " seconds) remaining." << endl;
        system("sleep 1");
      }
      else if (x == 1)
      {
        system("clear");
        cout << x << " minute (" << i << " seconds) remaining." << endl;
        system("sleep 1");
        system("clear");
      }
    }
    else if (i < 60)
    {
      if (i > 1)
      {
        system("clear");
        cout << i << " seconds remaining." << endl;
        system("sleep 1");
      }
      else if (i == 1)
      {
        system("clear");
        cout << i << " second remaining." << endl;
        system("sleep 1");
        system("clear");
      }
    }
  }
  return 0;
}
