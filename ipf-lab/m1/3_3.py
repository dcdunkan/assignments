import numpy as np


# Perform Search and Sort operations in Numpy arrays
arr = np.array([1, 4, 6, 2, 11, 9, 0, 3])
print("Original array:", arr)

# Sorting arrays
sorted_arr = np.sort(arr)
print("Sorted array:", sorted_arr)

# Searching in arrays
to_find = 11
index = np.where(arr == to_find)
print("Index of the entry 11:", index[0][0])
