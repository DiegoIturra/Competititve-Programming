#Uva 12554 A Special Birthday Song!! (ACEPTADO)

def main():
	numPeople = int(input())
	people = []

	song = ["Happy" , "birthday" ,"to","you","Happy",
		"birthday","to","you","Happy","birthday","to",
		"Rujia","Happy","birthday","to","you"]

	name = ""
	for i in range(numPeople):
		name = input()
		people.append(name)

	size = len(people)
	#caso 1: personas = 16
	if(size == 16):
		for i in range(size):
			print(people[i] + ": " + song[i])
	#caso 2: personas < 16
	elif(size < 16):
		index = -1
		for i in range(16):
			index += 1
			if index == size:
				index = 0
			print(people[index] + ": " + song[i])
	#caso 3: personas > 16
	else:
		indexSong = -1
		indexPeople = -1
		cantidad = ((size // 16)*16) + (size % 16) + (16 - (size % 16))
		for i in range(cantidad):
			indexSong += 1
			indexPeople += 1
			if indexSong == 16:
				indexSong = 0
			if indexPeople == size:
				indexPeople = 0
			print(people[indexPeople] + ": " + song[indexSong])


if __name__ == '__main__':
	main()