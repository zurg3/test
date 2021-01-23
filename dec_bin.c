#include <stdio.h>
#include <math.h>

int dec_to_bin(int dec) {
  int bin = 0;
  int rem;
  int i = 1;

  while (dec != 0) {
    rem = dec % 2;
    dec /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}

int bin_to_dec(int bin) {
  int dec = 0;
  int rem;
  int i = 0;

  while (bin != 0) {
    rem = bin % 10;
    bin /= 10;
    dec += rem * pow(2, i);
    i++;
  }

  return dec;
}

int main() {
  for (int i = 0; i < 32; i++) {
    printf("%d %d %d\n", i, dec_to_bin(i), bin_to_dec(dec_to_bin(i)));
  }

  return 0;
}
