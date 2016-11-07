import os
import sys

if len(sys.argv) < 2:
    exit()

split = sys.argv[1]

for i in xrange(8, 23):
    N = 2**i
    print "Running " + str(N)
    directory_name = split + "_2_to_the_" + str(i) + "th"
    #os.system("rm -rf " + directory_name)
    file_name = "datasets/find_" + str(N) + ".txt"
    #os.system("mkdir " + directory_name)
    os.system("python generate_random_rectangles.py " + str(N) + " F > " + file_name)
    os.system("python simple-run.py -split " + split + " -test " + file_name + " -M 57 -d " + directory_name + " > " + directory_name + "/find_results.txt")
