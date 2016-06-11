from random import randint
import sys, time, hashlib

startTime = time.time()
c=0
m=10000000
while(c<m):

  n0=randint(0,9999999999)
  n1=randint(0,9999999999)
  nn=hashlib.md5((str(n0) + str(n1)).encode('utf-8')).hexdigest()
  c=c+1

print ('Python: Version ' + sys.version)
print ('Execution time (seconds): {0}'.format(time.time() - startTime))