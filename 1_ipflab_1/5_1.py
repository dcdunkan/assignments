import numpy
import statistics

dataset = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

print("Mean:", numpy.mean(dataset))
print("Median:", numpy.median(dataset))
print("Mode:", statistics.mode(dataset))
print("Mean", numpy.std(dataset))
