import numpy as np

numbers = np.array([1, 5, 3, 9, 11, 7])
sorted = np.sort(numbers)
reversed = sorted[-1::-1]
print(reversed)
