import numpy as np


# Perform Search and Sort operations in Numpy arrays
def experiment_3_3():
    arr = np.array([1, 4, 6, 2, 11, 9, 0, 3])
    print("Original array:", arr)

    # Sorting arrays
    sorted_arr = np.sort(arr)
    print("Sorted array:", sorted_arr)

    # Searching in arrays
    to_find = 11
    index = np.where(arr == to_find)
    print("Index of the entry 11:", index[0][0])

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
