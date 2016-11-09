import sys
import random

buf = "0\n"

xmin = -7900000
ymax = -3928873
xmax = -7829582
ymin = -3984608

for i in range(int(sys.argv[1])):
    x = random.random() * (xmax - xmin) + xmin
    y = random.random() * (ymax - ymin) + ymin
    h = max(0.1, int(random.random() * (5000 - 1)))
    w = max(0.1, int(random.random() * (5000 - 1)))
    buf += "F " + str(x) + " " + str(y + h) + " " + str(x + w) + " " + str(y) + "\n"

print buf