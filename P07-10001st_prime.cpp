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
while counter < 10001 :
	i = 2
   	flag = 0
	while i < math.sqrt(num)+1:
		if num % i == 0 :
			flag = 1		
			break
		i = i + 1
	if flag == 0 :
		prime[j] = num 
		counter = counter + 1
		j = j + 1
	num = num + 2

#prime = list(set(prime))
del prime[0]
print prime
