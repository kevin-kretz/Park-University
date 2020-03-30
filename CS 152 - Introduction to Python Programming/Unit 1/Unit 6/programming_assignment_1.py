"""
 Unit 5 - Programming Assignment
 By Kevin Kretz | 07 July 2019
 Given a list strings containing city, state zip with irregular spacing between the components print the information in a nicely formatted table.
"""
def get_city(string):
    """Using the string provided, adds characters to a string, removing duplicate spaces, until a comma is found, then return the string, which is the complete city."""
    city = ""
    previous_ch = None;

    #For each character in string
    for ch in string:
        #break if it is a comma, the city has been completed
        if ch == ",":
            break
        #if the character is a letter, add it to the "city" string
        elif ch.isalpha():
            city += ch
        #if the character is a space, and the previous character is a letter, add the space to the "city" string. (This prevents duplicate spaces)
        elif ch.isspace() & previous_ch.isalpha():
            city += ch

        #update previous character
        previous_ch = ch

    return city

def get_state(string):
    """Skips all letters, until a comma is found, then addes all letters after the comma (should only be two) to the "state" string
    and returns the state once completed. """
    comma_found = False
    state = ""

    #for each character in string
    for ch in string:
        #if the comma has been passed
        if comma_found:
            #if the character is a letter add it to the "state" string
            if ch.isalpha():
                state += ch
        #if the comma has not been passed
        else:
            #if the letter is a comma, update comma to be found
            if ch == ",":
                comma_found = True;
    
    return state

def get_zip_code(string):
    """Adds all numbers to a string, then returns it as a zip code"""
    zip_code = ""

    #for each character in string
    for ch in string:
        #if the character is a number, add it to the "zip_code" string
        if ch.isdigit():
            zip_code += ch

    return zip_code

def get_longest_city_length(cities):
    """Goes through each city in "cities", and returns the length of the longest city name."""
    longest_length = 0

    #for each city in cities
    for city in cities:
        #if the length is longer than the length of the current lonest city, update the longest city length
        if len(city) > longest_length:
            longest_length = len(city)
    
    return longest_length


def main():
    file = open("CityStateData.txt")
    mycities = file.readlines()
    file.close()
    
    cities = []
    states = []
    zip_codes = []
    
    #for each string in mycities, use the above functions, and add them to the "cities", "states" and "zip_codes" lists
    for string in mycities:
        cities.append(get_city(string))
        states.append(get_state(string))
        zip_codes.append(get_zip_code(string))

    #store the length of the longest city in a variable
    longest_city_length = get_longest_city_length(cities)

    i = 0
    #go through all the strings provided, and print them in a formated table, with the first column being equal to the width of the longest city length
    while i < len(mycities):
        print("{:{width}} {} {}".format(cities[i], states[i], zip_codes[i], width = longest_city_length))
        i += 1
        
main()
