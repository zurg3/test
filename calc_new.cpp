#include <iostream>
using namespace std;

float calc(float num1, char operand, float num2) {
  float answer = 0;

  switch (operand) {
    case '+':
      answer = num1 + num2;
      break;
    case '-':
      answer = num1 - num2;
      break;
    case '*':
      answer = num1 * num2;
      break;
    case '/':
      answer = num1 / num2;
      break;
  }

  return answer;
}

int main(int argc, char *argv[]) {
  if (argc > 1 && argc == 4) {
    cout << argv[1] << "" << argv[2] << "" << argv[3] << "=" << calc(stof(argv[1]), *argv[2], stof(argv[3])) << endl;
  }

  return 0;
}
