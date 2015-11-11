
from random import randint, choice
game_dice = [4,6,8,10,12,20]

def roll_dice():
	while True:
		sides = raw_input("How many sides would you like?") 
		try:
			sides = int(sides)
			assert sides in game_dice
			return randint(1,sides)
		except AssertionError:
			print "Oops! Please choose side " + str(game_dice) + "."
		except ValueError:
			print "Oops! We need a number here."


answer = ["Can't wait", "Yes", "No", "Never", "I love Ryan", "Without A Doubt","Don't count on it.", "Always and forever", "Very Doubtful", "Sure. Why not?", "When can I take a break?", "Why can't I ask the questions?", "Affirmative", "When in Doubt...ask your Mom.", "Ryan's the best", "Where's Roxanne?", "Check Cocoa's face", "Only the poms will tell", "Ask the one you love.", "If Roxanne sits for you, it's affirmative otherwise, very doubtful."]


def eight_ball():
	response = choice(answer)
	raw_input("Ask me a question?")
	return response 











		