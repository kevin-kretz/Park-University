"""
 Unit 6 - Programming Assignment (2)
 By Kevin Kretz | 20 July 2019
 Using the data provided from the file "health-no-head.csv", print the values of the appropriate states according the filters provided by the user.
 Also print the states with the lowest and highest number of effected people.
"""

def main():
  #get filter information
  filter_state = input("Enter state (Empty means all): ")
  filter_disease = input("Enter disease (Empty means all): ")
  filter_year = input("Enter year (Empty means all): ")

  #declare variables for future use
  lowest = []
  highest = []
  total = 0

  #print header
  print("{:21} {:12} {:12} {:4}\n".format('State', 'Disease', 'Number', 'Year'))

  #open file
  file = open("health-no-head.csv", "r")

  # Process each line of the file
  for aline in file:
      values = aline.rstrip('\n').split(',')
      
      #rename values for easier readability
      state = values[2]
      disease = values[0]
      number = int(values[3])
      year = values[5]

      #declare variables for filtering
      state_matches = False
      disease_matches = False
      year_matches = False
      line_matches = False


      
      #filter information
      #if state filter is empty or current state matches state in filter
      if (filter_state == "" or filter_state.lower() == state.lower()):
        state_matches = True

      #if disease filter is empty or current disease matches disease in filter
      if (filter_disease == "" or filter_disease.lower() == disease.lower()):
        disease_matches = True
      #if year filter is empty or current year matches year in filter
      if (filter_year == "" or filter_year.lower() == year.lower()):
        year_matches = True
      
      #if state, disease and year all match the filter infomation, set line matches to true
      if state_matches & disease_matches & year_matches:
        line_matches = True

      #if current line matches filter information provided by user
      if line_matches:
        #print line
        print ("{:21} {:12} {:6,} {:>9}".format(state, disease, number, year))
        #add number to total
        total += number
        #if number is the new lowest number, change lowest
        if len(lowest) == 0 or number < lowest[1]:
          lowest = [state, number]
        #if number is the new highest, change highest
        if len(highest) == 0 or number > highest[1]:
          highest = [state, number]


      
  # Close file
  file.close()

  #print total
  print("{:21} {:12} {:6,}".format('', 'Total', total))

  #if there was at least one found in the filter, print highest and lowest states.
  if len(lowest) != 0:
    print("\nLowest")
    print("{:21} {:12} {:6,}".format(lowest[0], '', lowest[1]))
  if len(highest) != 0:
    print("\nHighest")
    print("{:21} {:12} {:6,}".format(highest[0], '', highest[1]))

main()
