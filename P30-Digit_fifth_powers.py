#!/usr/bin/python
num = 1 
sum2 = 0
for i in range(2,1000000):
	x = str(i)
	l = len(x)
	sum1 = 0
	for j in range(l):
		sum1 = sum1 + (int(x[j]))**5
	if sum1 == i :
		sum2 = sum2 + sum1
		print sum1

print sum2
