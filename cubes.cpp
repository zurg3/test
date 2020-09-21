/*
Compile: g++ cubes.cpp -std=c++17 -o cubes
Compile (static): g++ cubes.cpp -static -std=c++17 -o cubes
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#if defined(WIN32) || defined(_WIN32)
  #include <windows.h>
#else
  #include <unistd.h>
#endif
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int players;
  int turn;
  int max_turns;
  int cube1, cube2;
  int s;
  const int sleep_time = 2;

  cout << "Enter count of players: ";
  cin >> players;

  if (players == 1) {
    int sum_s = 0;
    turn = 0;
    max_turns = 10;

    while (turn < max_turns) {
      turn++;

      srand(time(NULL));
      cube1 = 1 + rand() % 6;
      cube2 = 1 + rand() % 6;

      if (cube1 == cube2) {
        cout << "!!!" << endl;
        max_turns++;
      }

      s = cube1 * cube2;
      sum_s += s;

      cout << turn << "|" << cube1 << "*" << cube2 << "=" << s << "|" << sum_s << endl;

      #if defined(WIN32) || defined(_WIN32)
        Sleep(sleep_time * 1000);
      #else
        sleep(sleep_time);
      #endif
    }

    if (sum_s >= 500) {
      cout << "Diamond" << endl;
    }
    else if (sum_s >= 300) {
      cout << "Gold" << endl;
    }
    else if (sum_s >= 200) {
      cout << "Silver" << endl;
    }
    else if (sum_s >= 100) {
      cout << "Bronze" << endl;
    }
    else if (sum_s < 100) {
      cout << "You lose!" << endl;
    }
  }
  else if (players > 1) {
    vector<int> sum_s;

    for (int i = 0; i < players; i++) {
      cout << "Player " << i << endl;
      sum_s.push_back(0);
      turn = 0;
      max_turns = 10;

      while (turn < max_turns) {
        turn++;

        srand(time(NULL));
        cube1 = 1 + rand() % 6;
        cube2 = 1 + rand() % 6;

        if (cube1 == cube2) {
          cout << "!!!" << endl;
          max_turns++;
        }

        s = cube1 * cube2;
        sum_s[i] += s;

        cout << turn << "|" << cube1 << "*" << cube2 << "=" << s << "|" << sum_s[i] << endl;

        #if defined(WIN32) || defined(_WIN32)
          Sleep(sleep_time * 1000);
        #else
          sleep(sleep_time);
        #endif
      }
      cout << endl;
    }

    cout << "Score:" << endl;
    for (int i = 0; i < players; i++) {
      cout << "Player " << i << " got " << sum_s[i] << " points." << endl;
    }

    cout << endl;
    auto max_s = max_element(sum_s.begin(), sum_s.end());
    auto winner = distance(sum_s.begin(), max_s);
    cout << "Player " << winner << " wins!" << endl;
  }
  else {
    cout << "Something is wrong!" << endl;
  }

  return 0;
}
