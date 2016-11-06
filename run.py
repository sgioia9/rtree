import subprocess
import time
import sys

delta_time = float(sys.argv[1]) if len(sys.argv) > 1 else 0.01

init_time = time.time()
results = ""
proc = subprocess.Popen("./rtree", shell=True, stdout=subprocess.PIPE)

while proc.poll() is None:
    file = open("/proc/" + str(proc.pid) + "/io")
    results = file.read() if file is not None else ""
    file.close()
    time.sleep(delta_time)

end_time = time.time()

print results
print "Duration: " + str(end_time - init_time) + " seconds."
