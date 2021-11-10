#!/usr/bin/python
base = pow(10,10)

#28433    7830457 

power = 7830457
product = 1
val = 2
while power != 0 :
	
	if power % 2 == 1 :
		product = product * val % base
	
	val = val ** 2 % base
	power = power / 2
x = 28433*product + 1
print x
