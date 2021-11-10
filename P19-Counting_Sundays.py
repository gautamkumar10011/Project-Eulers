#!/uusr/bin/python
total_num_days = 0
year = 1900

while year <= 2000:
	print "   ",year
	if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0 :
		total_num_days = total_num_days + 366
		print 366
	else :
		total_num_days = total_num_days + 365
		print 365
	year = year + 1

x = total_num_days / 7 - 52

print x
