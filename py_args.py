import sys

print('Argc:', len(sys.argv), '\n')

i = 0
print('Argv:')
for j in sys.argv:
    print(i, '-', j)
    i = i + 1
