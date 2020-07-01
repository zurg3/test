#!/usr/bin/env python3

import sys

print('Content-type: text/html')
print()
if sys.platform == 'linux':
    print('<p>You are using Linux</p>')
elif sys.platform == 'win32':
    print('<p>You are using Windows</p>')
else:
    print('<p>You are using something else</p>')
