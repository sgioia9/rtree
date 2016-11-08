import os
import sys

splits = ["linear", "greene"]

os.system("mkdir resM")

for split in splits:
    for M in range(6, 121, 3):
        print "Running M: " + str(M)
        directory_name = "default"
        os.system("rm -rf " + directory_name)
        file_name = "datasets/parsed_osm.txt"
        os.system("mkdir " + directory_name)
        # os.system("python generate_random_rectangles.py " + str(N) + " > " + file_name)
        os.system("python simple-run.py -split " + split + " -test " + file_name + " -M " + str(
            M) + " -d " + directory_name + " > resM/" + str(M) + ".txt")
