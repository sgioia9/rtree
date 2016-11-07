import os
import sys

splits = ["linear","greene"]

for i in xrange(8, 23):
    N = 2**i
    print "Running " + str(N)
    file_name = "datasets/find_" + str(N) + ".txt"
    os.system("python generate_random_rectangles.py " + str(N/10) + " F > " + file_name)
    for split in splits:
	    directory_name = split + "_2_to_the_" + str(i) + "th"
	    os.system("python simple-run.py -split " + split + " -test " + file_name + " -M 57 -d " + directory_name + " > " + directory_name + "/find_results.txt")
