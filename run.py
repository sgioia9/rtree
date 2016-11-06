import subprocess
import time
import sys
import os

cmd = []
delta_time = 0.01
directory = "default"
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
        cmd += ["<", sys.argv[i + 1]]

cmd = ["./rtree"] + cmd

init_time = time.time()
results = ""
proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)

while proc.poll() is None:
    file = open("/proc/" + str(proc.pid) + "/io")
    results = file.read() if file is not None else ""
    file.close()
    time.sleep(delta_time)

end_time = time.time()

print results
print "Duration: " + str(end_time - init_time) + " seconds."

nofiles = len([name for name in os.listdir(directory) if ".rtree" in name])

print "Files created: " + str(nofiles)

wc = os.popen("wc -l " + directory + "/*.rtree | grep total | xargs")
wcres = wc.read()
totallines = wcres.split(" ")[0]
usage = (totallines - nofiles) / (M * nofiles)

print "File Usage: " + str(usage * 100) + "%"
print "\t[" + ":" * int(usage * 20) + "." * int(20 - usage * 20) + "]"
