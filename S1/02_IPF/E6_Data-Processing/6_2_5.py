# Created on Thu Nov 30 14:14:24 2023

# Q) Download a CSV file from the internet and apply the following operations.
# (Note: if the CSV file doesn't contains any duplicates or empty cells, insert
# atleast 5 such entries in different locations)

import pandas as pd

# 1. Read the CSV file and display the top 10 rows.
data = pd.read_csv(".\\sample.csv")
print(data.head(10))

# 2. Clean the dataset.
data = data.dropna().drop_duplicates()

# 3. Find the mean and median of a numeric field and print it.
print("Mean (net):", data["net"].mean())
print("Median (net):", data["net"].median())

# 4. Find the correlation between any three valid columns.
fields = ["age", "worth", "net"]
print(data[fields].corr())

# 5. Draw the scatter plot that shows the relation between any two such
# attributes.
data.plot.scatter("age", "worth")
