import matplotlib.pyplot as plt
import numpy as np


boys = [114, 230, 510, 370, 400]
girls = [115, 215, 250, 200, 300]

n = 5
r = np.arange(n)
width = 0.25


plt.bar(r, boys, color='blue',        width=width,        label='Boys')
plt.bar(r + width, girls, color='pink',
        width=width,        label='Girls')

plt.xlabel("Year")
plt.ylabel("Number of people")
plt.title("Number of boys and girls went abroad")

plt.xticks(r + width/2, ['2018', '2019', '2020', '2021', '2022'])
plt.legend()

plt.show()
