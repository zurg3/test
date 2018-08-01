// this program probably works only on Linux.

#include <iostream>
using namespace std;

int main()
{
  int i, loading_status;
  loading_status = 0;
  for (i = loading_status; i <= 100; i++)
  {
    system("clear");
    if (i >= 0 && i < 10)
    {
      cout << "[__________] | " << i << "%" << endl;
    }
    else if (i >= 10 && i < 20)
    {
      cout << "[#_________] | " << i << "%" << endl;
    }
    else if (i >= 20 && i < 30)
    {
      cout << "[##________] | " << i << "%" << endl;
    }
    else if (i >= 30 && i < 40)
    {
      cout << "[###_______] | " << i << "%" << endl;
    }
    else if (i >= 40 && i < 50)
    {
      cout << "[####______] | " << i << "%" << endl;
    }
    else if (i >= 50 && i < 60)
    {
      cout << "[#####_____] | " << i << "%" << endl;
    }
    else if (i >= 60 && i < 70)
    {
      cout << "[######____] | " << i << "%" << endl;
    }
    else if (i >= 70 && i < 80)
    {
      cout << "[#######___] | " << i << "%" << endl;
    }
    else if (i >= 80 && i < 90)
    {
      cout << "[########__] | " << i << "%" << endl;
    }
    else if (i >= 90 && i < 100)
    {
      cout << "[#########_] | " << i << "%" << endl;
    }
    else if (i == 100)
    {
      cout << "[##########] | " << i << "%" << endl;
    }
    else
    {
      cout << "Something is wrong!" << endl;
    }
    system("sleep 1");
  }
  system("clear");
  return 0;
}
