import numpy as np

# Create np arrays for Integer, Float, String, Boolean, and Complex
# data types.
# Integer Array
ar1 = np.array([3, 6, 8, 9])
print("ar1 =", ar1)
print(ar1.ndim)
print(ar1.shape)
print(ar1.dtype)

# Float Array (conversion)
ar2 = np.array([3, 6, 8, 9], float)
print("ar2 =", ar2)
print(ar2.dtype)

# Boolean Array (conversion)
ar3 = np.array([3, 6, 8, 9, 0], bool)
print("ar3 =", ar3)
print(ar3.dtype)

# Complex Array
ar4 = np.array([complex(2, 3), complex(3, 5)])
print("ar4 =", ar4)
print(ar4.dtype)

# String Array
ar5 = np.array(["Good", "Fine", "Great", "Awesome"])
print("ar5 =", ar5)
print(ar5.dtype)
