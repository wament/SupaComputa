import numpy as n
def sqrt(x):
	s = 1.0
	for k in range(100):
		s = (1/2)*(s + (x/s))
		return s

z = sqrt(2)
print(z)
