import numpy as np


def GaussElimination(matrix, col):
    A = np.copy(matrix)
    b = np.copy(col)
    num_rows = A.shape[0]
    num_cols = A.shape[1]
    b_size = b.shape[0]
    if num_rows != b_size:
        return
        
    print("Gaussian Elimination === ")
    print("A", A)
    print("b", b, "\n")
    
    for c in range (num_cols-1):
        print("Gauss elimination along col=",c,":")
        for r in range(c+1, num_rows):
            m = (A[r][c]/A[c][c])
            print("m", m, "\n")
            A[r][c:] = A[r][c:] - m*A[c][c:]
            b[r] = b[r] - m*b[c]
        
        A[c][c:] = A[c][c:]/ A[c][c]
        
        print(A)
        print(b)
        print("\n")
        
    print("Back substitution === ")
    x = np.zeros(num_cols)
    x[num_rows-1] = b[num_rows-1]/A[num_rows-1][num_cols-1]
    for r in range(num_rows-2,-1,-1):
        x[r] = (b[r] - np.dot(A[r][r+1:], x[r+1:]))/A[r][r]
    return x


if __name__ == "__main__":
    # p(x) = ax^3 + bx^2 + cx + d
    # f(x) = cos(x)
    x0 = float(-0.1)
    x1 = float(-0.02)
    x2 = float(0.02)
    x3 = float(0.1)
    A = np.array([[x0**3, x0**2, x0, 1], [x1**3, x1**2, x1, 1], [x2**3, x2**2, x2, 1], [x3**3, x3**2, x3, 1]])
    b = np.array([np.cos(x0), np.cos(x1), np.cos(x2), np.cos(x3)])
    sol = GaussElimination(A, b)
    print(sol)
    
    
