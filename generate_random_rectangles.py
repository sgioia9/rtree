import random
import sys

N = int(sys.argv[1])
mod = "I" if len(sys.argv) <= 2 else sys.argv[2]

min_value = 0
max_value = 500000
min_dim = 0
max_dim = 100

buf = "1\n" if mod == "I" else "0\n"

for i in range(N):
    x = random.random() * (max_value - min_value)
    y = random.random() * (max_value - min_value)
    h = max(0.1, int(random.random() * (max_dim - min_dim)))
    w = max(0.1, int(random.random() * (max_dim - min_dim)))
    buf += mod + " " + str(x) + " " + str(y + h) + " " + str(x + w) + " " + str(y) + "\n"

print buf
