# -*- coding: utf-8 -*-

import subprocess
import time
import sys
import os

cmd = []
delta_time = 0.000001
directory = "default"
test_file = None
M = 500

for i in range(len(sys.argv)):
    if sys.argv[i] == "-M" and i + 1 < len(sys.argv):
        cmd = ["-M", sys.argv[i + 1]] + cmd
        M = int(sys.argv[i + 1])
    elif sys.argv[i] == "-split" and i + 1 < len(sys.argv):
        cmd = ["-split", sys.argv[i + 1]] + cmd
    elif sys.argv[i] == "-d" and i + 1 < len(sys.argv):
        cmd = ["-d", sys.argv[i + 1]] + cmd
        directory = sys.argv[i + 1]
    elif sys.argv[i] == "-sleep" and i + 1 < len(sys.argv):
        delta_time = float(sys.argv[i + 1])
    elif sys.argv[i] == "-test" and i + 1 < len(sys.argv):
        test_file = open(sys.argv[i + 1])

cmd = ["./rtree"] + cmd

init_time = time.time()
results = ""
proc = subprocess.Popen(cmd, shell=False, stdout=subprocess.PIPE, stdin=test_file)

while proc.poll() is None:
    try:
        proc_file = open("/proc/" + str(proc.pid) + "/io", "r")
        results = proc_file.read() if proc_file is not None else ""
        proc_file.close()
    except IOError, e:
        pass

print proc.stdout.read()
end_time = time.time()

print results
print "Duration: " + str(end_time - init_time) + " seconds."

nofiles = len([name for name in os.listdir(directory) if ".rtree" in name])

print "Files created: " + str(nofiles)

wc = os.popen("wc -l " + directory + "/*.rtree | xargs")
wcres = wc.read().replace("\n", " ").split(" ")

for i in range(0,len(wcres) - 3, 2):
    us = float(int(wcres[i]) - 1)/M
    print wcres[i+1][:-1] + " " + str(us*100) + "%"
    print "\t[" + "█" * int(us * 20) + " " * int(20 - us * 20) + "]"

usage = float((int(wcres[-3]) - nofiles)) / (M * nofiles)
test_file.close()

print "Average file usage: " + str(usage * 100) + "%"
print "\t[" + "█" * int(usage * 20) + " " * int(20 - usage * 20) + "]"


du = os.popen("du -sc " + directory + "/*.rtree | xargs")
dures = du.read().split(" ")

print "Filename \t\tDisk space"
for i in range(0, len(wcres) - 1, 2):
    print wcres[i+1][:-1] + " \t " + str(wcres[i]) + "Kb"