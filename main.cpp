// COMSC-210 | Lab 9 | Huiluan Yie

#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
using namespace std;

const int DAYS = 30;

//Function prototype
void print_temp(array<double, DAYS>);

int main() {
    // declarations
    array<double, DAYS> temperatures; // an array of temperatures for 30 days
    
    // file input
    ifstream fin; 
    fin.open("data.txt");
    if (fin.good( )) {
        for (int i = 0; i < DAYS; i++)
        {
            fin >> temperatures[i];
        }
        fin.close( ); // close the file  

        // use <array> member functions
        // <array> objects can report their own size, unlike C-style arrays
        cout << "1.  Size: " << temperatures.size() << endl;

        
    }
    else
        cout << "File not found.\n";
    
    return 0;
}

//Function definition
void print_temp(array<double, DAYS> temps)
{
    for (double t : temps) cout << t << " "; cout << endl;
}