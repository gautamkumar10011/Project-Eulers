#!/usr/bin/python
import math
range1 = int(input("enter the range :"))

#list of the primes 
product = 1
prime = [0]*range1
prime[0] = 2
j = 1
num = 3
counter = 1
while counter < range1 :
	n = num - 1
	val = prime[counter - 1]
	pro = 1
	while n :
		if n%2 != 0 :
			pro = pro*val % num
		val = val * val % num
		n = n / 2

	if pro == 1 :
		prime[j] = num 
		j = j + 1
		counter = counter + 1
	num = num + 2
print prime
