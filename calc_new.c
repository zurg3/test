#include <stdio.h>
#include <stdlib.h>
#include "calc_new.h"

int main(int argc, char *argv[]) {
  if (argc > 1 && argc == 4) {
    printf("%s%s%s=%g\n", argv[1], argv[2], argv[3], calc(atof(argv[1]), *argv[2], atof(argv[3])));
  }

  return 0;
}
