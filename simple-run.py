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