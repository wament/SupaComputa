import numpy as np

def solve(matrix, col):
    #get matrix sizes
    matrixDim = matrix.shape
    colDim = col.shape
    #copy matricies
    A = np.copy(matrix)
    B = np.copy(col)

    #Check if a solution is possible
    if(matrixDim[0] != colDim[0]):
        return None
 
    #print(A)
    #print(B)

    A[[0, 1]] = A[[1,0]] #iteration 1
    B[[0, 1]] = B[[1,0]]

    A[[0]] = A[[0]] * -1 #2
    B[[0]] = B[[0]] * -1
    
    A[[2]] = A[[2]] - np.dot(A[[0]], 5) # 3
    B[[2]] = B[[2]] - np.dot(B[[0]], 5)

    A[[1]] = A[[1]] + np.dot(A[[0]], 2) # 4
    B[[1]] = B[[1]] + np.dot(B[[0]], 2)

    A[[1, 2]] = A[[2,1]] # 5
    B[[1, 2]] = B[[2,1]]
    
    A[[1]] = np.dot(A[[1]], 1/34) # 6
    B[[1]] = np.dot(B[[1]], 1/34)
   
    A[[2]] = A[[2]] + np.dot(A[[1]], 14) # 7
    B[[2]] = B[[2]] + np.dot(B[[1]], 14)

    A[[2]] = A[[2]] * -1 # 8
    B[[2]] = B[[2]] * -1

    #print(A)
    #print(B)

    x3 = B[2]*A[2,2]
    x2 = B[1]*A[1,1] + x3*A[1,2]
    x1 = B[0]*A[0,0] + x2*A[0,1] + x3*A[0,2]

    return np.array([x1, x2, x3])
