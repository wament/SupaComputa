import myfuncs as my
import numpy

 
print("Testing 0!", my.factorial(0), "\n")
print("Testing 1!", my.factorial(1), "\n")
print("Testing 2!", my.factorial(2), "\n")
print("Testing 3!", my.factorial(3), "\n")
print("Testing 6!", my.factorial(7), "\n\n")




#test cases
print("EXP TEST CASES \n")
print("My function for e^x outputs: ", my.exp(2.5), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(2.5), "\n")
print("Error: ", abs(numpy.exp(2.5) - my.exp(2.5)), "\n")

print("My function for e^x outputs: ", my.exp(10), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(10), "\n")
print("Error: ", abs(numpy.exp(10) - my.exp(10)), "\n")

print("My function for e^x outputs: ", my.exp(25), "\n")
print("Numpy function for e^x outputs: ", numpy.exp(25), "\n")
print("Error: ", abs(numpy.exp(25) - my.exp(25)), "\n\n")

#test cases
print("LOG TEST CASES \n")
print("My function for ln outputs: ", my.ln(2.5), "\n")
print("Numpy function for ln outputs: ", numpy.log(2.5), "\n")
print("Error: ", abs(numpy.log(2.5)-my.ln(2.5)), "\n")

print("My function for ln outputs: ", my.ln(10), "\n")
print("Numpy function for ln outputs: ", numpy.log(10), "\n")
print("Error: ", abs(numpy.log(10)-my.ln(10)), "\n")

print("My function for ln outputs: ", my.ln(25), "\n")
print("Numpy function for ln outputs: ", numpy.log(25), "\n")
print("Error: ", abs(numpy.log(25)-my.ln(25)), "\n")
