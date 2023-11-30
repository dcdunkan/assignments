import matplotlib.pyplot as plt
import numpy as np

plt.title("Population")

x = np.random.randint(0, 100, 50)
plt.hist(x, bins=[0, 20, 40, 60, 80, 100])
plt.xlabel("Age")
plt.ylabel("Number of people")
plt.show()
