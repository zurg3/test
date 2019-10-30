#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // Variables and constants
  const char currency[5] = "RUB";
  
  char work_month[20] = "November";
  unsigned short int work_year = 2019;
  
  const unsigned short int work_hours_per_day = 8;
  
  const unsigned int money_per_hour = 80;
  const float salary_tax_percent = 0.13;
  
  char employee_first_name[20];
  char employee_last_name[30];
  
  unsigned int work_days;

  // Input
  cout << "Employee first name: ";
  cin >> employee_first_name;
  
  cout << "Employee last name: ";
  cin >> employee_last_name;
  
  cout << "Work days: ";
  cin >> work_days;
  
  //system("cls");
  system("clear");
  
  // Calculations
  int work_hours = work_days * work_hours_per_day;
  
  float salary_all = work_hours * money_per_hour;
  float salary_tax = salary_all * salary_tax_percent;
  float salary_real = round(salary_all - salary_tax);
  
  // Output
  cout << "# " << work_month << " " << work_year << endl << endl;
  cout << "# " << employee_first_name << " " << employee_last_name << endl;
  cout << "##########" << endl;
  cout << "# Work days: " << work_days << endl;
  cout << "# Work hours: " << work_hours << endl;
  cout << "##########" << endl;
  cout << "# Salary all: " << salary_all << " " << currency << endl;
  cout << "# Salary tax: " << salary_tax << " " << currency << endl;
  cout << "##########" << endl;
  cout << "# Salary real: " << salary_real << " " << currency << endl;
  
  return 0;
}
