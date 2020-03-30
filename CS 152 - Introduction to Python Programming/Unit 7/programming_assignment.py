# open file and read contents
file = open("state_crime - CS152.csv", "r")

crimes = {};
US_total = 0;
    
def add_to_crimes(file):
  """Takes the information from a file and puts the state and reported crimes into a dictionary."""
  for line in enumerate(file): #used enumerate to ignore the first line of headers
    if (line[0] != 0): #ignore the first line of headers
      line = line[1].split(',') #set to line for easier readability
      state = line[10]
      all_property_totals = int(line[11])
      all_violent_totals = int(line[15])

      if state in crimes.keys(): #if the key already exists in the dictionary, add totals to state
        crimes[state] += all_property_totals + all_violent_totals

      else: #otherwise, make a new key
        crimes[state] = all_property_totals + all_violent_totals
  
  file.close()
      
def get_US_total():
  """Adds the crimes reported from each state in the dictionary and returns the sum."""
  total = 0
  for key in crimes:
    total += crimes[key]
  return total


def write_summary():
  """Writes the summary of the file to a new file names 'crime_summary.txt'"""
  new_file = open('crime_summary.txt', 'x') #make new file
  new_file.write("{:27} {:>15}\n".format('State', 'Reported Crimes')) #write header
  for key in sorted(crimes): #write each state summary
    new_file.write("{:27} {:>15,}\n".format(key, crimes[key]))
  new_file.write("{:27} {:>15,}".format('United States', get_US_total())) # write U.S. total summary

def main():
  """Runs the program"""
  add_to_crimes(file)
  write_summary()
  
main()
