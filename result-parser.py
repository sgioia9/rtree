interestingLines = [3,4,9]
buf = ""

files = "results/g8_find.txt results/g9_find.txt results/g10_find.txt results/g11_find.txt results/g12_find.txt results/g13_find.txt results/g14_find.txt results/g15_find.txt results/g16_find.txt results/g17_find.txt".split(" ")

for i in range(len(files)):
	filename = files[i]
	with open(filename) as f:
		c = 0
		buf += str(i+8) + " "
		for line in f:
			if c in interestingLines:
				buf += line.split(" ")[1][:-1] + " "
			c += 1
		buf += "\n"

print buf