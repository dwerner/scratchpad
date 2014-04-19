import sys, random, datetime

if not len(sys.argv) > 1:
  print "Provide a number of elements."
  exit()

print "Generating a list with " + sys.argv[1] + " elements"

s = sys.argv[1]

n = [int(10000*random.random()) for i in xrange(int(s))]

print "beginning sort..."

start = datetime.datetime.now() 
sortname = "insertion"

for j in range(1, len(n)):
  key = n[j]
  i = j - 1
  while i >= 0 and n[i] > key:
    n[i+1] = n[i]
    i = i - 1
    n[i+1] = key

etime = datetime.datetime.now() 
print n
  
print sortname + " sort of "+s+" items took : " + str(etime - start)
