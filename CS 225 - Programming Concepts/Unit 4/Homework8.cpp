// HW8_SalesReport_shell.cpp (shell code. need ADD CODE #1 ~ #3)
// by Bin "Crystal" Peng, CS225
// generate sales report using monthly sales data
// fixed # of sales people; unknown # of sales record


#include <iostream>
#include <fstream> // std::ifstream
#include <string>  // std::string
#include <iomanip> // std::setw(), std::fixed, std::setprecision()

//----------------------------------------------
// global declarations
//----------------------------------------------

const int MAX = 10;   // max # of sales person

struct salesPersonRec
{
  std::string ID;     // salesperson's ID
  double totalSales;  // salesperson's yearly sales amount
};


//----------------------------------------------
// function declarations
//----------------------------------------------

// read id data into array and set totalSales of each record to 0
bool loadID(salesPersonRec list[]/*OUT*/, int listSize/*IN*/);
// Pre: listSize specified
// Post: listSize # of ids read in from file and saved in the ID column in the first listSize records of list. totalSales of those records set to 0

// read in sales data and calculate total sales per person
bool loadData(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains valid ids and totalSales set to 0 for the first listSize records
// Post: sales data read from file
//       totalSales of the first listSize records are set to accumulated sales of the salesperson with the given id

// display menu on screen
void showMenu();
// Pre: none
// Post: menu choices printed on screen

// display id and yearly sales amout of all salespersons by id order
void showReportByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the id column
//       id and totalSales column of the first listSize records in list are printed on screen

// display id and yearly sales amout of all salespersons by total sales order
void showReportBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the total sales column
//       id and totalSales column of the first listSize records in list are printed on screen

// sort sales person records by total sales amount
void sortBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of the totalSales column


// ADD CODE #1: two function declarations


void sortByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the first listSize records in list are reordered so they are now in ascending order of ID column

void showReport(salesPersonRec list[]/*OUT*/, int listSize/*IN*/);
// Pre: listSize specified, list contains at least listSize number of records
// Post: the report is printed and organized based on the criteria given by the user.


// END ADD CODE #1



//----------------------------------------------

int main()
{
  salesPersonRec salesPersonList[MAX]; // array to hold the salesperson's data
  int numOfSalesPerson = 6;

  if (!loadID(salesPersonList, numOfSalesPerson)) // load id data
    return 1;

  if (!loadData(salesPersonList, numOfSalesPerson)) // load sales data
    return 1;

  // user interaction via menu
  int option = 0; // user option
  do
  {
    // display menu
    showMenu();

    // user option
    std::cin >> option;

    switch (option)
    {
    case 1: // sort and display report by id
      showReportByID(salesPersonList, numOfSalesPerson);
      break;
    case 2: // sort and display report by sales
      showReportBySales(salesPersonList, numOfSalesPerson);
      break;
    case 0: // exit
      std::cout << "\nThank you for using our reporting system!\n";
      break;
    default: // invalid input
      std::cout << "invalid choice. Please try again.\n";
      break;
    }
  } while (option != 0);

} // end main


//----------------------------------------------
// Function Implementation
//----------------------------------------------

// read id data into array and set totalSales of each record to 0
bool loadID(salesPersonRec list[]/*OUT*/, int listSize/*IN*/)
{
  std::ifstream inFile;  // input file
  std::string idfilename = "salesID.txt";

  // open id file
  inFile.open(idfilename);
  if (inFile.fail())
  {
    std::cerr << "Error: can't open input file \"" << idfilename << "\". Abort. \n"; // report to cerr
    return false;                                           // and end now
  }

  // read in id data
  for (int index = 0; index < listSize; index++)
  {
    if (!(inFile >> list[index].ID)) // get salesperson's ID
      return false;  // reading failed

    list[index].totalSales = 0.0;
  }
  inFile.close(); // close file

  return true;
} //end loadID

//----------------------------------------------

// read in sales data and calculate total sales of each person
bool loadData(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  std::ifstream inFile;  // input file
  std::string datafilename = "salesData.txt";

  // open sales data
  inFile.open(datafilename);
  if (inFile.fail())
  {
    std::cerr << "Error: can't open input file\"" << datafilename << "\". Abort. \n"; // report to cerr
    return false;                                           // and end now
  }

  // read in data and process
  std::string id;
  int month;
  double amount;

  // ADD CODE #2:
  // read sales data from file,
  // calculate and update totalSales of each record
  while (inFile >> id >> month >> amount) {  // for every line inside of salesData.txt
    for (int index = 0; index < listSize; index++) { // check each list index
      if (id == list[index].ID) {  // if id matches
        list[index].totalSales += amount;  // add amount to totalSales
      }
    }
  }
  // END ADD CODE #2


  inFile.close(); // close data file

  return true;
} //end loadData

//----------------------------------------------

// display menu on screen
void showMenu()
{
  const std::string menuOptions[] = { "Options:",
    "1. Display sales report by sales id.",
    "2. Display sales report by annual sales amount.",
    "0. Exit",
    "Choose (0 ~ 2): "
  };
  int menuLen = sizeof(menuOptions) / sizeof(std::string);

  std::cout << std::endl;
  for (int i = 0; i < menuLen - 1; i++)
    std::cout << menuOptions[i] << std::endl;
  std::cout << menuOptions[menuLen - 1]; // last item
} // end getUserOption

//----------------------------------------------

void showReportByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  sortByID(list, listSize);
  showReport(list, listSize);
} // end showReportByID

//----------------------------------------------

void showReportBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  sortBySales(list, listSize);
  showReport(list, listSize);
} // end showReportBySales

//----------------------------------------------

void sortBySales(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/)
{
  // insertion sort
  for (int i = 1; i < listSize; i++)
  {
    // find spot to insert [i]
    salesPersonRec hold = list[i];
    double amount = list[i].totalSales;
    int indexToInsert = i - 1;
    while (indexToInsert >= 0 && amount < list[indexToInsert].totalSales)
    {
      // shift
      list[indexToInsert + 1] = list[indexToInsert];
      indexToInsert--;
    }
    // insert
    list[indexToInsert + 1] = hold;
  }
} // end sortBySales

//----------------------------------------------

// ADD CODE #3: implementation of two functions
void sortByID(salesPersonRec list[]/*INOUT*/, int listSize/*IN*/) {
  // insertion sort
  for (int i = 1; i < listSize; i++)
  {
    // find spot to insert [i]
    salesPersonRec hold = list[i];
    std::string ID = list[i].ID;
    int indexToInsert = i - 1;
    while (indexToInsert >= 0 && ID < list[indexToInsert].ID)
    {
      // shift
      list[indexToInsert + 1] = list[indexToInsert];
      indexToInsert--;
    }
    // insert
    list[indexToInsert + 1] = hold;
  }
} // end sortByID

void showReport(salesPersonRec list[]/*OUT*/, int listSize/*IN*/) {
  std::cout << "\n---- Annual Sales Report ----\n";  // print header
  std::cout << std::left << std::setw(7) << "ID" << "Total Sales" << std::endl;  // print labels
  for (int i = 0; i < listSize; i++) {  // for every index in the list
    std::cout << std::left << std::setw(7) << list[i].ID << std::right << std::setw(10)<< std::fixed << std::setprecision(2)<< list[i].totalSales << std::endl; // print id and sales amount formated to match example
  }
  std::cout << "-----------------------------";  // print break link per example
}  // end showReport


// END ADD CODE #3
