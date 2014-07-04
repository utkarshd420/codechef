import sys,string
input = sys.stdin
int_num = string.atoi(input.readline())
for i in xrange(1,int_num+1):
	n = string.atoi(input.readline())
	res = [[0 for x in xrange(n)] for x in xrange(n)]
	for j in xrange(0,n):
		line = input.readline()
		vals = map(int,line.split())
		if (j == 0):
			res[0][0] = vals[0]
		else:
			for index,val in enumerate(res[j-1]):
				if(val==0):
					break
				res[j][index]=max(res[j][index],res[j-1][index]+vals[index])
				res[j][index+1]=max(res[j][index+1],res[j-1][index]+vals[index+1])
	print max(res[n-1])
