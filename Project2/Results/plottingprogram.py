import numpy as np
import pylab as plt
import os



rho_5 = [f for f in os.listdir(".") if f[-13] == str(5)]
rho_10 = [f for f in os.listdir(".") if f[-14] == str(1)]
print rho_5
for f in rho_5:
	if f[1] == "a":
		eigenvalues = []
		file = open(f)
		data = file.read()
		for line in data:
			line = line.split()
			if line[0] == "N":
				N = line[1]
			elif line[0] == "rho_max":
				rho_max = line[1]
			elif line[0] == "rho_min":
				rho_min = line[1]
			elif line[0] == "iterations":
				iterations = line[1]
			elif line[0] == "eps":
				eps = line[1]
			else:
				eigenvalues.append(np.float(line[0]))
		eigenvalues = array(eigenvalues)
		sort_index = eigenvalues.argsort()
		eigenvalues = eigenvalues[sort_index]

		data = np.array(data.split()).astype(np.float)

		for line in f:
			line.split()
			if line[0] == "N":
				eigenvalues.append(float(line[1]))




