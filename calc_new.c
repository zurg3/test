#include <stdio.h>
#include <stdlib.h>

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
    printf("%s%s%s=%g\n", argv[1], argv[2], argv[3], calc(atof(argv[1]), *argv[2], atof(argv[3])));
  }

  return 0;
}
