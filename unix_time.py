import time

while True:
    a = time.time()
    unix_time = int(a // 1)
    print(unix_time)
    time.sleep(1)
    if unix_time == 0:
        break
