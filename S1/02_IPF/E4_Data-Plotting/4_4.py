import matplotlib.pyplot as plt
import numpy as np

x = np.array([30, 15, 5, 25, 10, 10])
labels = np.array(["Food", "Rent", "Misc.", "Loan",
                  "Travel", "Electricity & Maintainence"])
plt.title("Expenses")
plt.pie(x, labels=labels)
plt.show()
