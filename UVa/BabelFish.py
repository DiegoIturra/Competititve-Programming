#UVa 10282 Babelfish (ACEPTADO)
from sys import stdin

def main():
	wordDictionary = dict()

	for line in stdin:
		#leer palabra en ingles y su traduccion
		if len(line) == 1:
			break
		englishWord,foreignWord = line.split()
		wordDictionary[foreignWord] = englishWord

	#leer mensaje en lenguaje extranjero
	#rstrip(): elimina los saltos de linea al final de un string
	for word in stdin:
		englishWord = wordDictionary.get(word.rstrip())
		if not englishWord:
			print("eh")
		else:
			print(englishWord)

if __name__ == '__main__':
	main()
