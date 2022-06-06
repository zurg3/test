#include <iostream>
#include <string>
using namespace std;

int get_year_sum(int year) {
  int year_sum = 0;

  for (int i = 0; i < to_string(year).length(); i++) {
    year_sum += (to_string(year)[i] - '0');
  }

  return year_sum;
}

int main() {
  int year;

  cout << "Year: ";
  cin >> year;

  cout << get_year_sum(year) << endl;

  return 0;
}
