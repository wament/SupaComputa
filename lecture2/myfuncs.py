"""Module for my functions"""
import math
import numpy
def exp(x):
 econst = 2.7182818284590451
 x0 = int(round(x))
 z = x - x0
 approx = 0
 for k in range(100):
  approx += (z**k)/(math.factorial(k))
 out = math.pow(econst, x0) * approx
 
 
 return out

print("My function for e^x outputs: ", exp(2.5), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(2.5), "\n")
print("Error: ", abs(numpy.exp(2.5) - exp(2.5)), "\n")

print("My function for e^x outputs: ", exp(10), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(10), "\n")
print("Error: ", abs(numpy.exp(10) - exp(10)), "\n")

print("My function for e^x outputs: ", exp(25), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(25), "\n")
print("Error: ", abs(numpy.exp(25) - exp(25)), "\n")




def ln(x):
 s = x * 1.0
 
 for k in range(100):
  s = s - 1 + (x* exp(-s))
 
 return s

print("My function for ln outputs: ", ln(2.5), "\n")
print("Numpy function for ln outputs: ", numpy.log(2.5), "\n")
print("Error: ", abs(numpy.log(2.5)-ln(2.5)), "\n")

print("My function for ln outputs: ", ln(10), "\n")
print("Numpy function for ln outputs: ", numpy.log(10), "\n")
print("Error: ", abs(numpy.log(10)-ln(10)), "\n")

print("My function for ln outputs: ", ln(25), "\n")
print("Numpy function for ln outputs: ", numpy.log(25), "\n")
print("Error: ", abs(numpy.log(25)-ln(25)), "\n")


