
n =int( raw_input())
for i in xrange(1,n+1):
	num = int(raw_input())
	count_fact = 0
	num_div = 5
	while(num_div <= num):
		count_fact += num/num_div
		num_div *= 5
	print count_fact

		

