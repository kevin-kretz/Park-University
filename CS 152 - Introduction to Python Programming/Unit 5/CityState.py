#Given a list strings containing city, state zip
#  with irregular spacing between the components
#print this information in a nicely formatted table table

def main():
    mycities = ['Cape Girardeau, MO 63780','Columbia, MO  65201',
                'Kansas City, MO 64108','Rolla,MO   65402',
                'Springfield, MO65897','St Joseph, MO64504',
                'St Louis,MO63111', 'Ames,   IA 50010 ', 'Enid, OK 73773',
                'West Palm Beach, FL 33412',
                'International Falls, MN 56649',
                'Frostbite Falls,MN               56650     '
                ]
            
    # Print the table
    for c in mycities:      
        print(c)

main()
