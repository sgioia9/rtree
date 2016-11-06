import random
import sys

N = int(sys.argv[1])

min_value = -500000
max_value = 500000
min_dim = 1
max_dim = 100

buf = ""

for i in range(N):
	x = random.random()*(max_value - min_value)
	y = random.random()*(max_value - min_value)
	h = max(0.01,int(random.random()*(max_dim - min_dim)))
	w = max(0.01,int(random.random()*(max_dim - min_dim)))
	buf += "I " + str(x) + " " + str(y+h) + " " + str(x+w) + " " + str(y) + "\n"

print buf