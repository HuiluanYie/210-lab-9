// COMSC-210 | Lab 9 | Huiluan Yie

#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int DAYS = 30,
    W = 3;

//Function prototype
void print_arr(array < double, DAYS > );
void print_vec(vector < double >);

int main() {
    /*Array*/
    // declarations
    array < double, DAYS > temperatures; // an array of temperatures for 30 days

    // file input
    ifstream fin;
    fin.open("temperatures.txt");
    if (fin.good()) {
        for (int i = 0; i < DAYS; i++) {
            fin >> temperatures[i];
        }
        fin.close(); // close the file  

        // use <array> member functions
        // <array> objects can report their own size, unlike C-style arrays
        cout << "1.  Days of temperature recorded: " << temperatures.size() << endl;

        // range loop to access elements
        cout << "2.  Temperatures each day: \n";
        print_arr(temperatures);

        // accessing individual elements
        cout << "3.  2nd temperature: " << temperatures.at(2) << endl;
        cout << "4.  3rd temperature: " << temperatures[3] << endl;
        cout << "5.  1st temperature: " << temperatures.front() << endl;
        cout << "6.  last temperature: " << temperatures.back() << endl;
        cout << "7.  Empty? " << (temperatures.empty() == 0 ? "False" : "True") << endl;
        cout << "8.  Address? " << temperatures.data() << endl;

        // find an element
        // find an element
        double target = 83; // search target
        array < double, temperatures.size() > ::iterator it; // declare iterator to point to the found element
        it = find(temperatures.begin(), temperatures.end(), target);

        cout << "9. looking for a day which temperature is " << target << endl;
        if (it != temperatures.end())
            cout << "\tFound, day#" << it - temperatures.begin() << "'s temperature is " << target << endl;
        else
            cout << " Not found.\n";

        // use iterators to sort
        sort(temperatures.begin(), temperatures.end());
        cout << "10.  Sorted: \n";
        print_arr(temperatures);

        sort(temperatures.rbegin(), temperatures.rend());
        cout << "11. Reverse sorted: \n";
        print_arr(temperatures);

        // find max & min & sum
        cout << "12. The maximun temperature is: " << * max_element(temperatures.begin(), temperatures.end()) << endl;
        cout << "13. The minimun temperature is: " << * min_element(temperatures.begin(), temperatures.end()) << endl;
        cout << "14. The average temperature is: " << accumulate(temperatures.begin(), temperatures.end(), 0) / temperatures.size() << endl;

        // fill an array with one value
        array < double, DAYS > same;
        cout << "15. An array of the same number: \n";
        same.fill(70);
        print_arr(same);

        // swap same and temperatures
        same.swap(temperatures);
        cout << "15. Swapped, now same has: \n";
        print_arr(same);
        cout << "temperatures has: \n";
        print_arr(temperatures);
    } else
        cout << "File not found.\n";


    /*Vector*/
    // declarations
    vector < double > temperatures2; // a vector of temperatures for 30 days

    // file input
    fin.open("temperatures.txt");
    if (fin.good()) {
        for (int i = 0; i < DAYS; i++) {
            fin >> temperatures2[i];
        }
        fin.close(); // close the file  

        // use <array> member functions
        // <array> objects can report their own size, unlike C-style arrays
        cout << "1.  Days of temperature recorded: " << temperatures2.size() << endl;

        // range loop to access elements
        cout << "2.  Temperatures each day: \n";
        print_vec(temperatures2);

        // accessing individual elements
        cout << "3.  2nd temperature: " << temperatures2.at(2) << endl;
        cout << "4.  3rd temperature: " << temperatures2[3] << endl;
        cout << "5.  1st temperature: " << temperatures2.front() << endl;
        cout << "6.  last temperature: " << temperatures2.back() << endl;
        cout << "7.  Empty? " << (temperatures2.empty() == 0 ? "False" : "True") << endl;
        cout << "8.  Address? " << temperatures2.data() << endl;

        // find an element
        // find an element
        double target = 83; // search target
        vector < double > ::iterator it; // declare iterator to point to the found element
        it = find(temperatures2.begin(), temperatures2.end(), target);

        cout << "9. looking for a day which temperature is " << target << endl;
        if (it != temperatures2.end())
            cout << "\tFound, day#" << it - temperatures2.begin() << "'s temperature is " << target << endl;
        else
            cout << " Not found.\n";

        // use iterators to sort
        sort(temperatures2.begin(), temperatures2.end());
        cout << "10.  Sorted: \n";
        print_vec(temperatures2);

        sort(temperatures2.rbegin(), temperatures2.rend());
        cout << "11. Reverse sorted: \n";
        print_vec(temperatures2);

        // find max & min & sum
        cout << "12. The maximun temperature is: " << * max_element(temperatures2.begin(), temperatures2.end()) << endl;
        cout << "13. The minimun temperature is: " << * min_element(temperatures2.begin(), temperatures2.end()) << endl;
        cout << "14. The average temperature is: " << accumulate(temperatures2.begin(), temperatures2.end(), 0) / temperatures2.size() << endl;

        // fill an array with one value
        array < double, DAYS > same;
        cout << "15. An array of the same number: \n";
        same.fill(70);
        print_vec(same);

        // swap same and temperatures2
        same.swap(temperatures2);
        cout << "15. Swapped, now same has: \n";
        print_vec(same);
        cout << "temperatures2 has: \n";
        print_vec(temperatures2);
    } else
        cout << "File not found.\n";

    return 0;
}

//Function definition
void print_vec(array < double, DAYS > arr) {
    // print_temp() prints out the contents in the array
    // arguments: an array of doubles
    // returns: none
    for (int i = 0; i < arr.size(); i++)
        cout << setw(W) << i + 1 << ":  " << arr[i] << endl;
}

void print_vec(vector < double > vec)
{
    // print_temp() prints out the contents in the vector
    // arguments: a vector of doubles
    // returns: none
    for (int i = 0; i < vec.size(); i++)
        cout << setw(W) << i + 1 << ":  " << vec[i] << endl;
}