#include <iostream>
using namespace std;

float bmi(float mass, float height) {
  return mass / (height * height);
}

void bmi_category(float mass, float height) {
  float bmi_value = bmi(mass, height);

  if (bmi_value <= 16) {
    cout << "BMI = " << bmi_value << " (Severely underweight)" << endl;
  }
  else if (bmi_value > 16 && bmi_value <= 18.5) {
    cout << "BMI = " << bmi_value << " (Underweight)" << endl;
  }
  else if (bmi_value > 18.5 && bmi_value <= 25) {
    cout << "BMI = " << bmi_value << " (Normal (healthy weight))" << endl;
  }
  else if (bmi_value > 25 && bmi_value <= 30) {
    cout << "BMI = " << bmi_value << " (Overweight)" << endl;
  }
  else if (bmi_value > 30 && bmi_value <= 35) {
    cout << "BMI = " << bmi_value << " Obese Class I (Moderately obese)" << endl;
  }
  else if (bmi_value > 35 && bmi_value <= 40) {
    cout << "BMI = " << bmi_value << " Obese Class II (Severely obese)" << endl;
  }
  else if (bmi_value > 40) {
    cout << "BMI = " << bmi_value << " Obese Class III (Very severely obese)" << endl;
  }
  else {
    cout << "Something is wrong!" << endl;
  }
}

int main() {
  float a, b;

  cout << "Enter your mass (kg): ";
  cin >> a;
  cout << "Enter your height (m): ";
  cin >> b;

  bmi_category(a, b);

  return 0;
}
