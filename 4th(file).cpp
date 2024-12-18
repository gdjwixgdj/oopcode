#include <iostream>
#include <fstream>  // For file handling
#include <string>   // For string operations
using namespace std;

int main() {
    // File name
    const string filename = "example.txt";

    // Step 1: Create an output file and write information to it
    ofstream outFile(filename); // Open file in output mode
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1; // Exit with error
    }

    // Writing data to the file
    cout << "Writing data to file..." << endl;
    outFile << "Hello, this is a test file!" << endl;
    outFile << "It contains multiple lines of text." << endl;
    outFile << "File handling in C++ is simple and efficient." << endl;

    outFile.close(); // Close the file
    cout << "Data written to " << filename << " successfully.\n" << endl;

    // Step 2: Open the file as an input file and read its contents
    ifstream inFile(filename); // Open file in input mode
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Exit with error
    }

    // Reading data from the file
    cout << "Reading data from file..." << endl;
    string line;
    while (getline(inFile, line)) { // Read file line by line
        cout << line << endl;
    }

    inFile.close(); // Close the file
    cout << "\nData read from " << filename << " successfully." << endl;

    return 0;
}
