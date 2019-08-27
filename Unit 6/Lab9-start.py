# Open and read health data file one line at a time
# Columns are 
#   disease,increase,location,number,population,year

file = open("health-no-head-sample.csv", "r")

# Process each line of the file
for aline in file:
    print (aline)
    values = aline.split(',')
    print (values)
    
# Close file
file.close()
