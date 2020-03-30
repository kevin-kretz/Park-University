number_of_yards = input("Enter a positive number of yards: ")
number_of_miles = number_of_yards // 1760
remaining_yards = number_of_yards % 1760
number_of_feet = number_of_yards * 3

print("You entered " + str(number_of_yards) + " yards, which is:")
print(str(number_of_miles) + " miles and " + str(remaining_yards) + " yards.")
print("or")
print(str(number_of_feet) + " feet")
