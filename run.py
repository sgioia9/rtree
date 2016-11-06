import subprocess

proc = subprocess.Popen("./rtree", shell=True, stdout=subprocess.PIPE)
results = ""
while proc.poll() is None:
    file = open("/proc/" + str(proc.pid) + "/io")
    results = file.read()
    file.close()

print results
