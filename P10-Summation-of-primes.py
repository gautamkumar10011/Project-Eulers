#!/usr/bin/python
import math
range1 = long(input("enter the range :"))
flag = 0
#list of the primes 
sum1 = 2
num  = 3
while num < range1 :
	i    = 2
	flag = 0
	while i < math.sqrt(num)+1:
		if num % i == 0 :
			flag = 1		
			break
		i = i + 1
	if flag == 0 :
		sum1  = sum1 + num
	num = num + 2
	print num
print sum1
