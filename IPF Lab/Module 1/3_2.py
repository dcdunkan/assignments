import numpy as np

# Perform Reshape, Join and Split operations in the arrays.

# Reshaping arrays
x = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
x = x.reshape(4, 3)
print(x)

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

arr = np.array([1, 4, 6, 2, 11, 9, 0, 3])
print("Original array:", arr)

# Splitting an array
chunks = 3
split_arrays = np.array_split(arr, chunks)
print("Splitting the array into chunks of 3:", split_arrays)

# Slicing
n = np.array([4, 5, 6, 0, 11, 3])
print(n[2:4])  # outputs [6, 0]; the index-4 element is not included
print(n[2::2])  # starts from 2 and goes until the end, but by 2-by-2
print(n[::])  # everything
print(n[1:5:3])  # find out yourself
