
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
			coords = map(abs,map(int,map(float,point.split(" "))))
			points.append((coords[0],coords[1]))
		points.sort()
		buf += "I " + str(points[2][0]) + " " + str(points[2][1]) + " " + str(points[3][0]) + " " + str(points[3][1]) + "\n"

queries = [
	"POLYGON((-7863193.45384967 -3955161.54482673,-7863193.45384967 -3949260.27435004,-7857176.16108496 -3949260.27435004,-7857176.16108496 -3955161.54482673,-7863193.45384967 -3955161.54482673))", #PROVIDENCIA
	"POLYGON((-7869375.51086264 -3958752.7278199,-7869375.51086264 -3951995.81444473,-7861944.13307546 -3951995.81444473,-7861944.13307546 -3958752.7278199,-7869375.51086264 -3958752.7278199))", #SANTIAGO
	"POLYGON((-7862660.09326975 -3958511.9232991,-7862660.09326975 -3953024.16201654,-7855901.36138791 -3953024.16201654,-7855901.36138791 -3958511.9232991,-7862660.09326975 -3958511.9232991))", #NUNOA
	"POLYGON((-7860002.63252836 -3960000.61323257,-7860002.63252836 -3943655.88453213,-7839914.13220169 -3943655.88453213,-7839914.13220169 -3960000.61323257,-7860002.63252836 -3960000.61323257))", #LAS CONDES
	"POLYGON((-7862610.23716495 -3981106.19356356,-7862610.23716495 -3967579.40851531,-7846487.89191315 -3967579.40851531,-7846487.89191315 -3981106.19356356,-7862610.23716495 -3981106.19356356))", #PUENTE ALTO
	"POLYGON((-7895899.00595791 -3971485.41575489,-7895899.00595791 -3956278.22979575,-7872331.07592218 -3956278.22979575,-7872331.07592218 -3971485.41575489,-7895899.00595791 -3971485.41575489))" #MAIPU
	]

for polystr in queries:
	polystr = polystr.replace("POLYGON","").replace("(","").replace(")","")
	pointstr = polystr.split(",")
	points = []
	for point in pointstr:
		coords = map(float,point.split(" "))
		points.append((coords[0],coords[1]))
	points.sort()
	buf += "F " + str(points[2][0]) + " " + str(points[2][1]) + " " + str(points[3][0]) + " " + str(points[3][1]) + "\n"

print buf[:-1]