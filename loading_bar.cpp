// this program probably works only on Linux.

#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  int i, loading_status;
  float sec, time_sec, time_sleep;
  loading_status = 0;
  cout << "За сколько секунд нужно выполнить загрузку?" << endl;
  cout << "-> ";
  cin >> sec;
  if (sec != 0)
  {
    time_sec = sec / 100;
    time_sleep = time_sec * 1000000;
    for (i = loading_status; i <= 100; i++)
    {
      system("clear");
      if (i >= 0 && i < 5)
      {
        cout << "[____________________] | " << i << '%' << endl;
      }
      else if (i >= 5 && i < 10)
      {
        cout << "[#___________________] | " << i << '%' << endl;
      }
      else if (i >= 10 && i < 15)
      {
        cout << "[##__________________] | " << i << '%' << endl;
      }
      else if (i >= 15 && i < 20)
      {
        cout << "[###_________________] | " << i << '%' << endl;
      }
      else if (i >= 20 && i < 25)
      {
        cout << "[####________________] | " << i << '%' << endl;
      }
      else if (i >= 25 && i < 30)
      {
        cout << "[#####_______________] | " << i << '%' << endl;
      }
      else if (i >= 30 && i < 35)
      {
        cout << "[######______________] | " << i << '%' << endl;
      }
      else if (i >= 35 && i < 40)
      {
        cout << "[#######_____________] | " << i << '%' << endl;
      }
      else if (i >= 40 && i < 45)
      {
        cout << "[########____________] | " << i << '%' << endl;
      }
      else if (i >= 45 && i < 50)
      {
        cout << "[#########___________] | " << i << '%' << endl;
      }
      else if (i >= 50 && i < 55)
      {
        cout << "[##########__________] | " << i << '%' << endl;
      }
      else if (i >= 55 && i < 60)
      {
        cout << "[###########_________] | " << i << '%' << endl;
      }
      else if (i >= 60 && i < 65)
      {
        cout << "[############________] | " << i << '%' << endl;
      }
      else if (i >= 65 && i < 70)
      {
        cout << "[#############_______] | " << i << '%' << endl;
      }
      else if (i >= 70 && i < 75)
      {
        cout << "[##############______] | " << i << '%' << endl;
      }
      else if (i >= 75 && i < 80)
      {
        cout << "[###############_____] | " << i << '%' << endl;
      }
      else if (i >= 80 && i < 85)
      {
        cout << "[################____] | " << i << '%' << endl;
      }
      else if (i >= 85 && i < 90)
      {
        cout << "[#################___] | " << i << '%' << endl;
      }
      else if (i >= 90 && i < 95)
      {
        cout << "[##################__] | " << i << '%' << endl;
      }
      else if (i >= 95 && i < 100)
      {
        cout << "[###################_] | " << i << '%' << endl;
      }
      else if (i == 100)
      {
        cout << "[####################] | " << i << '%' << endl;
      }
      else
      {
        cout << "Something is wrong!" << endl;
      }
      usleep(time_sleep);
    }
    sleep(1);
    system("clear");
  }
  else
  {
    cout << "Something is wrong!" << endl;
  }
  return 0;
}
