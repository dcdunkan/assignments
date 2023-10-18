import numpy

data = (34, 46, 50, 43, 23, 16, 48, 36, 12, 17, 21, 34, 38, 49, 24)
percentile = numpy.percentile(data, 80)
print(percentile)
