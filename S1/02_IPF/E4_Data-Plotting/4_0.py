import matplotlib.pyplot as plt
import numpy as np

x = np.array(["Boys", "Girls"])
y = np.array([42390, 26798])

plt.title("Comparison of Girls and Boys opting for higher studies abroad (2018-2023)")
plt.bar(x, y, color="Green", width=0.25)
plt.xlabel("Gender")
plt.ylabel("Number of people")
plt.show()
