import numpy as np
import pylab as plt
import os

files = sorted(f for f in os.listdir(".") if f.endswith(".txt"))
print files
rho_5 = [f for f in os.listdir(".") if f[-13] == str(5)]
rho_10 = [f for f in os.listdir(".") if f[-14] == str(1)]

for f in rho_5:
	eigenvalues = []
	for line in f:
		line.split()
		if line[0] == "N":
			eigenvalues.append(float(line[1]))


files.close
print rho_5
