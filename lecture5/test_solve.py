import Gaussian_elimination_solve as g
import numpy as np
from numpy import linalg as l


A = np.array([[-2, 0, 1], [-1, 7, 1], [5, -1, 1]])
B = np.array([-4, -50, -26])
print("My Gaussian Elimination")
print(g.solve(A, B), "\n")
print("Numpy Gaussian Elimination")
print(l.solve(A,B), "\n")