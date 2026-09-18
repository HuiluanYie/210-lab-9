// COMSC-210 | Lab 9 | Huiluan Yie

#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
#include <iomanip>
using namespace std;

const int DAYS = 30, W = 3;

//Function prototype
void print_temp(array<double, DAYS>);

int main() {
    // declarations
    array<double, DAYS> temperatures; // an array of temperatures for 30 days
    
    // file input
    ifstream fin; 
    fin.open("temperatures.txt");
    if (fin.good( )) {
        for (int i = 0; i < DAYS; i++)
        {
            fin >> temperatures[i];
        }
        fin.close( ); // close the file  

        // use <array> member functions
        // <array> objects can report their own size, unlike C-style arrays
        cout << "1.  Days of temperature recorded: " << temperatures.size() << endl;

        // range loop to access elements
        cout << "2.  Temperatures each day: \n";
        print_temp(temperatures);

        // accessing individual elements
        cout << "3.  Element 2: " << temperatures.at(2) << endl;
        cout << "4.  Element 2: " << temperatures[2] << endl;
        cout << "5.  Front: " << temperatures.front() << endl;
        cout << "6.  Back: " << temperatures.back() << endl;
        cout << "7.  Empty? " << (temperatures.empty() == 0? "False" : "True") << endl;
        cout << "8.  Address? " << temperatures.data() << endl;


    }
    else
        cout << "File not found.\n";
    
    return 0;
}

//Function definition
void print_temp(array<double, DAYS> temps)
{
    // print_temp() prints out the array of temperatures
    // arguments: an array of temperatures
    // returns: none
    for (int i = 0; i < temps.size(); i++) 
        cout << setw(W) << i << ":  " << temps[i] << endl; 
}