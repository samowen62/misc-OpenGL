from math import pow, factorial
import sys

#gens mesh based on input file with bezier curves
#assumes input mesh is m x n and 3 dimensional

presicion = 10.0

def nCr(n,k):
   return (factorial(n) / factorial(k)) / (1.0 * factorial(n-k))

#n,i ints and t in [0,1]
def bezierPoly(t,n,i):
	return nCr(n,i) * pow(t,i) * pow(1.0 - t,n - i)

if(len(sys.argv) != 2):
	sys.exit(0)

#read file into array
input = open(sys.argv[1],'r')
lines = input.read().splitlines()
points = []
for line in lines:
	new = []
	old = line.split(',')
	for i in xrange(0, len(old), 3):
		c = [int(j) for j in old[i:i+3]]
		new.append(c)
	points.append(new)

mesh = []
m = len(points)
n = len(points[0])

def bezier(u,v):
	sum = [0,0,0]
	for i in range(n):
		for j in range(m):
			res = bezierPoly(u,n - 1,i)*bezierPoly(v,m - 1,j)
			sum[0] += res*points[i][j][0]		
			sum[1] += res*points[i][j][1]
			sum[2] += res*points[i][j][2]
	return sum

for i in range(int(presicion) + 1):
	line = []
	for j in range(int(presicion) + 1):
		line.append(bezier(i/presicion,j/presicion))
	mesh.append(line)

for i in mesh:
	for j in i:
		j[0] = str(round(j[0],3))+'f'
		j[1] = str(round(j[1],3))+'f'
		j[2] = str(round(j[2],3))+'f'


output = open('mesh','w')
output.write(str(mesh))