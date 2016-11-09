import sys
import random

buf = "0\n"

for i in range(int(sys.argv[1])):
    x = random.random() * (-7890000 + 7880000) - 7880000
    y = random.random() * (-3980000 + 3930000) - 3930000
    h = max(0.1, int(random.random() * (5000 - 1)))
    w = max(0.1, int(random.random() * (5000 - 1)))
    buf += "F " + str(x) + " " + str(y + h) + " " + str(x + w) + " " + str(y) + "\n"

print buf