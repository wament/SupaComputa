import numpy as np
from numpy import linalg
from matplotlib import pyplot as plt
import math

#Gaussian Elmination for solving A x = b
#Matrix = A, col = b, output = x
def GaussElimination(matrix, col, tol = float(1.0e-11)):
    #copy matrices to do calculations
    A = np.copy(matrix)
    b = np.copy(col)
    num_rows = A.shape[0]
    num_cols = A.shape[1]
    b_size = b.shape[0]
    #check if matrix and col sizes are compatible
    if num_rows != b_size:
        return
        
    print("A", A)
    print("b", b, "\n")
    
    for c in range (num_cols-1):
        print(c, "\n")
        print("Gauss elimination along col=",c,":")
        for r in range(c+1, num_rows):
            m = (A[r][c]/A[c][c])
            A[r][c:] = A[r][c:] - m*A[c][c:]
            b[r] = b[r] - m*b[c]
            #check for near 0 values
            if( abs(A[r][c]) < tol):
                A[r][c] = 0
        
        print(A)
        print(b)
        print("\n")
        
    print("Back substitution === ")
    x = np.zeros(num_cols)
    x[num_rows-1] = b[num_rows-1]/A[num_rows-1][num_cols-1]
    for r in range(num_rows-2,-1,-1):
        x[r] = (b[r] - np.dot(A[r][r+1:], x[r+1:]))/A[r][r]
    #check for near 0 values
    for r in range(len(x)):
        if abs(x[r]) < tol:
            x[r] = 0
    return x


if __name__ == "__main__":
    # p(x) = ax^3 + bx^2 + cx + d
    # f(x) = cos(x)
    # these are the 4 approximation points for p(x), f(x)
    x0 = float(-0.1)
    x1 = float(-0.02)
    x2 = float(0.02)
    x3 = float(0.1)

    #setup matrix and col
    A = np.array([[x0**3, x0**2, x0, 1], [x1**3, x1**2, x1, 1], [x2**3, x2**2, x2, 1], [x3**3, x3**2, x3, 1]])
    b = np.array([np.cos(x0), np.cos(x1), np.cos(x2), np.cos(x3)])

    #get solution and compare with linalg.solve
    sol = GaussElimination(A, b)
    print(sol,"\n")
    print(np.linalg.solve(A,b),"\n")

    #p(x) lambda function
    p = lambda x : sol[0]*(x**3) + sol[1]*(x**2) + sol[2]*x + sol[3]

    #plot the two functions together and visualize the approximation
    t = np.linspace(-1, 1, 100) # (min, max, num_steps)
    plt.plot(t, np.cos(t), 'r') # (x, y, color)
    plt.plot(t, p(t), 'bo')
    plt.show()
    
    A = np.array([[-2, 0, 1], [-1, 7, 1], [5, -1, 1]])
    b = np.array([-4, -50, -26])
    sol = GaussElimination(A, b)
    print(sol,"\n")
    print(np.linalg.solve(A,b),"\n")
    
