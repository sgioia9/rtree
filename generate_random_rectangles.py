import random
import sys

N = int(sys.argv[1])
mod = "I" if len(sys.argv) <= 2 else sys.argv

min_value = -50000
max_value = 50000
min_dim = 25000
max_dim = 25000

buf = "0\n" if mod == "I" else "1\n"

for i in range(N):
    x = random.random() * (max_value - min_value)
    y = random.random() * (max_value - min_value)
    h = max(0.1, int(random.random() * (max_dim - min_dim)))
    w = max(0.1, int(random.random() * (max_dim - min_dim)))
    buf += mod + " " + str(x) + " " + str(y + h) + " " + str(x + w) + " " + str(y) + "\n"

print buf
