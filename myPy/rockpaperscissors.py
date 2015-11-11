from random import randint
 
RPS = ["rock","paper","scissors"]


def chooseMove():
	print("Time to play.")
	while (True):
		choice = raw_input("Choose your move! Rock. Paper. Scissors.")
		if choice.lower() in RPS:
			return RPS.index(choice.lower()) 

def compMove():
	choice = randint(0,2)
	print("Computer chooses " + RPS[choice])
	return choice

def compareMoves( move1, move2 ):
	if move1 == move2:
		return None
	elif move1 == 1 and move2 == 0:
		return True
	elif move2 == 2 and move2 == 1:
		return True 
	elif move2 == 0 and move2 == 2:
		return True
	else:
		return False


if __name__ == "__main__":
	winCount = 0 
	for i in range(10):
		user = chooseMove()
		comp = compMove()
		results = compareMoves(user, comp) 
		if results == True:
			winCount+=1
			print("You're a winner!")
		elif results == False:
			print("I'm a winner!")
		else:
			print("We both suck!")
	print("You won " + str(winCount) + " times out of 10!")



