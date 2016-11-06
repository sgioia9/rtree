
buf = ""

with open("datasets/osm.csv") as f:
	for line in f:
		comps = line.split(";")
		polystr = comps[1][:-1]
		if len(comps) > 2 or polystr == "rect":
			continue
		polystr = polystr.replace("POLYGON","").replace("(","").replace(")","")
		pointstr = polystr.split(",")
		points = []
		for point in pointstr:
			coords = map(float,point.split(" "))
			points.append((coords[0],coords[1]))
		points.sort()
		buf += str(points[2][0]) + " " + str(points[2][1]) + " " + str(points[3][0]) + " " + str(points[3][1]) + "\n"

print buf