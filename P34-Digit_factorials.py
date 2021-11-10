#!/usr/bin/python
import math
sum2 = 0
for i in range(1000000,100000000):
	x = str(i)
	l = len(x)
	sum1 = 0
	for j in range(l):
		sum1 = sum1 + math.factorial(int(x[j]))
	if sum1 == i :
		sum2 = sum2 +sum1
		print i
print sum2
