# October 7, 2023
# EXERCISES: Experiment 3: Data structures with Library functions
import numpy as np

# Create a matrix of size 3x3 with integer data, print the matrix,
# its datatype and its dimension.
matrix = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])
print(matrix)
print(matrix.dtype)
print(matrix.ndim)

# Convert the matrix values to floating point numbers and print
# matrix, its dimension and datatype.
converted = np.array(matrix, float)
print(converted)
print(converted.dtype)
print(converted.ndim)
