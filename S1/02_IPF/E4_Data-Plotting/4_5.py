import matplotlib.pyplot as plt
import numpy as np

# 1:
x1 = np.array([1, 8])
y1 = np.array([3, 10])

plt.subplot(1, 2, 1)
plt.plot(x1, y1)

plt.title("Exercise 1")
plt.xlabel("x values")

# 2:
plt.title("Population")

x2 = np.random.randint(0, 100, 50)

plt.subplot(1, 2, 2)
plt.hist(x2, bins=[0, 20, 40, 60, 80, 100])

plt.xlabel("Age")
plt.ylabel("Number of people")

plt.show()
