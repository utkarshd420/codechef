import random
import math
print 100000
x = range(1,100001) 
random.shuffle(x)
str1=""
for i in x:
    str1 = str1 + " "+str(i)
print str1
