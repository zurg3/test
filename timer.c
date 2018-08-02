// this program probably works only on Linux.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int timer, i, x;

  system("clear");
  printf("Timer (seconds): ");
  scanf("%d", &timer);

  for (i = timer; i > 0; i--)
  {
    if (i >= 60)
    {
      x = i / 60;
      x = x + 1;
      if (x > 1)
      {
        system("clear");
        printf("%d minutes (%d seconds) remaining.\n", x, i);
        sleep(1);
      }
      else if (x == 1)
      {
        system("clear");
        printf("%d minute (%d seconds) remaining.\n", x, i);
        sleep(1);
      }
    }
    else if (i < 60)
    {
      if (i > 1)
      {
        system("clear");
        printf("%d seconds remaining.\n", i);
        sleep(1);
      }
      else if (i == 1)
      {
        system("clear");
        printf("%d second remaining.\n", i);
        sleep(1);
      }
    }
  }
  system("clear");
  return 0;
}
