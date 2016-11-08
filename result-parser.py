interestingLines = [3,4,9]
buf = ""

for i in range(6,121,3):
	with open("resM/"+str(i)+".txt") as f:
		c = 0
		buf += str(i) + " "
		for line in f:
			if c in interestingLines:
				buf += line.split(" ")[1][:-1] + " "
			c += 1
		buf += "\n"