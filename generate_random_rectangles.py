import random
import sys

N = int(sys.argv[1])

min_value = 0
max_value = 500000
min_dim = 0
max_dim = 100

buf = ""

for i in range(N):
	x = int(random.random()*(max_value - min_value))
	y = int(random.random()*(max_value - min_value))
	h = int(random.random()*(max_dim - min_dim))
	w = int(random.random()*(max_dim - min_dim))
	buf += "I " + str(x) + " " + str(y+h) + " " + str(x+w) + " " + str(y) + "\n"

print buf