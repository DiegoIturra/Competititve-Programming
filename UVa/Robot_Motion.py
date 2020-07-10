#UVA 10116 - Robot Motion (ACEPTADO)
from sys import stdin

def traverse(grid,start,N,M):
	current = grid[0][start] #elemento en la partida
	x = 0
	y = start

	path = 0
	currentPath = 0
	visited = {}
	loop = False
	while True:
		#verificar en nodos visitados
		if (x,y) not in visited:
			#agregar si esta en el rango
			if x >= 0 and y >= 0 and y < M and x < N: 
				visited[(x,y)] = [grid[x][y],path]
		else:
			currentPath = visited.get((x,y)) #info antes del loop
			path = path - currentPath[1]
			loop = True
			break
		#si nos salimos de la matriz , termina el recorrido
		if x < 0 or x >= N or y < 0 or y >= M:
			break
		else:
			if grid[x][y] == 'N':
				x = x - 1
				path += 1
			elif grid[x][y] == 'S':
				x = x + 1
				path += 1
			elif grid[x][y] == 'E':
				y = y + 1
				path += 1
			elif grid[x][y] == 'W':
				y = y - 1
				path += 1
	if loop:
		print(f"{currentPath[1]} step(s) before a loop of {path} step(s)")
	else:
		print(f"{path} step(s) to exit")
	

def main():
	while(True):
		N,M,start = stdin.readline().strip().split(' ')
		if N == '0' and M == '0' and start == '0':
			break

		N = int(N)
		M = int(M)
		start = int(start) - 1

		#se crea una lista de listas vacias
		grid = []
		for i in range(N):
			grid.append([])

		for i in range(N):
			row = stdin.readline().strip()
			grid[i] = row

		traverse(grid,start,N,M)



if __name__ == '__main__':
	main()