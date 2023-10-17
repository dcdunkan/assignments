import numpy as np

arr1 = np.array([1, 2, 3, 4, 5, 6, 7])
print(np.array_split(arr1, 1))
print(np.array_split(arr1, 2))
print(np.array_split(arr1, 5))
print(np.array_split(arr1, 7))
print(np.array_split(arr1, 10))

arr2 = np.array([1, 2, 3, 4, 5, 6, 7, 8])
print(np.split(arr2, 1))
print(np.split(arr2, 2))
print(np.split(arr2, 4))
print(np.split(arr2, 7))  # expect error
print(np.split(arr2, 10))
