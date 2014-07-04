import math
def prime(num):
	b =0
	n = int(num)
	if n == 2 or n == 3:
	    return True
	k = 1
	while (6*k - 1) <= math.sqrt(n):
	    if n % 2 == 0 or n % 3 == 0 or n % (6*k - 1) == 0 or n % (6*k + 1) == 0:
	        return False
	    k += 1
	return True

import sys,string
input = sys.stdin
num = input.readline()

while(1):
	rev_num = num[::-1]
	if(rev_num == num):
		if(prime(num)):
			print num
			break
	num= str(int(num)+1)