import numpy as np

# Perform Reshape, Join and Split operations in the arrays.
def experiment_3_2():
    # Concatenating two integer arrays into one.
    a = np.array([1, 2, 3])
    b = np.array([4, 5, 6])
    c = np.concatenate((a, b))
    print(c)

    # Concatenating two two-dimensional arrays.
    # Changing the `axis` to 1, gives flattened transpose of the matrix.
    d = np.array([[1, 2, 3], [4, 5, 6]])
    e = np.array([[7, 8, 9], [11, 12, 13]])
    f = np.concatenate((d, e), axis=0)
    print(f)