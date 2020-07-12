"""
Uva 12582-Wedding of Sultan (ACEPTADO)
Nombre: Diego Iturra Huenteo
Codigo Propio
uva username: diturra2016
"""
from sys import stdin

def solve(traversal,case):
	"""
	traversal: es la secuencia de nodos visitados en el recorrido dfs
	case: el el caso actual
	"""
	stack = []
	grafo = {}

	#crear un grafo (lista de adyacencia)
	for node in traversal:
		if node not in grafo:
			grafo[node] = []

	for i,v in enumerate(traversal):
		if i == 0:
			stack.append(v)
		else:
			if v == stack[len(stack)-1]:
				stack.pop()
			else:
				#añadir al grafo v -> s.top()
				aux = grafo.get(v)
				aux.append(stack[len(stack)-1])
				grafo[v] = aux

				#añadir al grafo s.top() -> v
				aux2 = grafo.get(stack[len(stack)-1])
				aux2.append(v)
				grafo[stack[len(stack)-1]] = aux2

				#añadir v al stack
				stack.append(v)

	#ordenar diccionario segun sus claves para la impresion
	print(f"Case {case+1}")
	gSort = sorted(grafo.items() , key=lambda x: x[0], reverse=False)
	
	for nodo in gSort:
		print(f"{nodo[0]} = {len(nodo[1])}")		


def main():
	cases = int(stdin.readline())

	for case in range(cases):
		traversal = stdin.readline().strip()
		solve(traversal,case)


if __name__ == '__main__':
	main()