import os


for i in xrange(18, 19):
    N = 2**i
    print "Running " + str(N)
    directory_name = "2_to_the_" + str(i) + "th"
    os.system("rm -rf " + directory_name)
    file_name = "datasets/" + str(N) + ".txt"
    os.system("mkdir " + directory_name)
    os.system("python generate_random_rectangles.py " + str(N) + " > " + file_name)
    os.system("python run.py -test " + file_name + " -M 57 -d " + directory_name + " > " + directory_name + "/results.txt")