"""Module for my functions"""
import numpy

def factorial(x):
    s=1
    #check input
    if x <= 1:
        return 1
    return x*factorial(x-1) #recursive calculation
    


#exponential function
def exp(x, kmax = 100, tol = 1.0e-14):
 econst = 2.7182818284590451
 x0 = int(round(x))
 z = x - x0
 approx = 0 * 1.0
 
 # approximation
 for k in range(kmax):
  n = (z**k)/(factorial(k)) # (z^k / k!)
  if abs(n) < tol:
   break
  approx += n
 out = (econst ** x0) * approx # e^x0 * (x^k / k!)
 
 
 return out



#natural logorithm
def ln(x, kmax = 100, tol = 1.0e-14):
 s0 = 0
 s = x * 1.0
 
 #approximation
 for k in range(100):
  if abs(s - s0) < tol:
   break
  s0 = s
  s = s - 1 + (x* exp(-s))
  
 return s





