#!/usr/bin/python
a = 2**1000
x = str(a)
sum1 = 0
len1 = len(x) 
for i in range(len1):
	sum1 = sum1  + int(x[i])
print sum1
