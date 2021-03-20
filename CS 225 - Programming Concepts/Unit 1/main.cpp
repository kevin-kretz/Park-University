#include <iostream>  // Included input and output streams
#include <fstream>  // Include file streams
#include <string> // Includes string
#include <iomanip> // Includes input/output manipulation

int main() {
    // Open input file
    std::ifstream inputFile; // Declare variable for input file
    inputFile.open("curSalary.txt");  // Opens curSalary.txt

    // Verify no errors occured while opening the file
    if (inputFile.fail()) {  // Check if opening the file failed
        std::cerr << "Can't open the input file.  Aborted. \n";  // Prints error message
        return 1;  // Returns 1 and program ends
    }

    // Create ouput file
    std::ofstream outputFile;  // Declare a variable for output file
    outputFile.open("newSalary.txt");  // Output file is created.  If it already exists, it will overwrite the existing file

    // Verify no errors occured while creating the file
    if (outputFile.fail()) {  // Check if creating the file failed
        std::cerr << "Can't create the output file.  Aborted. \n";  // Prints error message
        return 1;  // Returns 1 and program ends
    }

    // Read through input document
    std::string lastName; // Declares variable for lastName
    std::string firstName;  // Declares variable for firstName
    double currentSalary;  // Declares variable for currentSalary
    double increasePercentage;  // Declares variable for increasePercentage
    double increaseAmount;  // Declares variable for increaseAmount
    double newSalary;  // Declares variable for newSalary
    int counter = 0;  // Declares variable for counter

    while (inputFile >> lastName >> firstName >> currentSalary >> increasePercentage) {  // Reads input file one line at a time and assigns them to the appropriate variables
        increaseAmount = currentSalary * (increasePercentage * 0.01);  // Calculates the proper amount to increase the salary by
        newSalary = currentSalary + increaseAmount;  // Increases the salary and assigns it to the newSalary variable
        outputFile << firstName << " "<< lastName << " " << std::fixed << std::setprecision(2) << newSalary << std::endl;  // Prints the new content to the output file
        counter = counter + 1;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    // If no text in input file, warns user
    if (counter == 0) {
        std::cout << "Warning: empty input file.  Output file created but is empty.";
    }
    // Prints report for number of rectords processed
    else {
        std::cout << counter << " records processed and saved in \"newSalary.txt\".";
    }

    // Return 0 and end of program 
    return 0;   
}
