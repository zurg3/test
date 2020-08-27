#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guess_num(int max_value) {
  srand(time(NULL));

  int unknown_number = 1 + rand() % max_value;
  int enter_number;
  int attempts = 0;

  cout << unknown_number << endl;

  while (true) {
    cout << "Enter unknown number [1.." << max_value << "]: ";
    cin >> enter_number;
    attempts++;

    if (enter_number == unknown_number) {
      cout << "You win!" << endl;

      if (attempts == 1) {
        cout << "You guessed the number in " << attempts << " attempt." << endl;
      }
      else if (attempts > 1) {
        cout << "You guessed the number in " << attempts << " attempts." << endl;
      }

      break;
    }
  }
}

int main() {
  int difficulty;

  cout << "Enter difficulty level [1 - Easy, 2 - Medium, 3 - Hard]: ";
  cin >> difficulty;

  if (difficulty == 1) {
    guess_num(10);
  }
  else if (difficulty == 2) {
    guess_num(50);
  }
  else if (difficulty == 2) {
    guess_num(100);
  }
  else {
    cout << "Something is wrong!" << endl;
  }

  return 0;
}
