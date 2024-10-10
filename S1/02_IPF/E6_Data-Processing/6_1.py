# Created on Thu Nov 30 07:59:55 2023

# Q) Write a Pandas program to create a dataframe from a dictionary
# and display it.

from pandas import DataFrame

sample = {
    "height": [180, 185, 150, 160, 175],
    "weight": [84, 94, 89, 83, 86],
    "age": [30, 40, 45, 60, 25],
}

data_frame = DataFrame(sample)
print(data_frame.to_string())
