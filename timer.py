# this program probably works only on Linux.

import time
import os

os.system('clear')
timer = int(input('Timer (seconds): '))

for i in range(timer, 0, -1):
    if i >= 60:
        x = i // 60
        x = x + 1
        if x > 1:
            os.system('clear')
            output_string = str(str(x) + ' minutes (' + str(i) + ' seconds) remaining.')
            print(output_string)
            time.sleep(1)
        elif x == 1:
            os.system('clear')
            output_string = str(str(x) + ' minute (' + str(i) + ' seconds) remaining.')
            print(output_string)
            time.sleep(1)
    elif i < 60:
        if i > 1:
            os.system('clear')
            output_string = str(str(i) + ' seconds remaining.')
            print(output_string)
            time.sleep(1)
        elif i == 1:
            os.system('clear')
            output_string = str(str(i) + ' second remaining.')
            print(output_string)
            time.sleep(1)
os.system('clear')
