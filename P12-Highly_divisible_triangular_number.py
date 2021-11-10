#!/usr/bin/python
n  = 100

f = 1
flag = 1
while flag:
	f = (n**2+ n)/2
	counter = 0
	for i in range(1,f+1):
		if f % i == 0 :
			counter = counter + 1
	
	if counter < 500 :
		n  = n * 2
	elif counter > 500 :
		n = n - 1
	else:
		flag = 0
print n ;	
