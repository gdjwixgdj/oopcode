#include <iostream>   // For input/output
#include <string>     // For string operations
using namespace std;

// Base class: Publication
class Publication {

public:
    string title;  // Title of the publication
    float price;   // Price of the publication
    // Default constructor
    Publication() : title(""), price(0.0) {}

    // Function to input data for Publication
    void inputPublicationData() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;

        // Validate input
        if (price < 0) {
            throw runtime_error("Price cannot be negative.");
        }
    }

    // Function to display Publication data
    void displayPublicationData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class: Book
class Book : public Publication {
private:
    int pageCount;  // Page count of the book

public:
    // Default constructor
    Book() : pageCount(0) {}

    // Function to input data for Book
    void inputBookData() {
        try {
            inputPublicationData();  // Input base class data
            cout << "Enter page count: ";
            cin >> pageCount;
            cin.ignore(); // Clear input buffer

            // Validate input
            if (pageCount < 0) {
                throw runtime_error("Page count cannot be negative.");
            }
        } catch (exception& e) {
            // Handle exception and reset data members to zero values
            cout << "Exception: " << e.what() << endl;
            title = "";
            price = 0.0;
            pageCount = 0;
        }
    }

    // Function to display Book data
    void displayBookData() const {
        displayPublicationData();  // Display base class data
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class: Tape
class Tape : public Publication {
private:
    float playingTime;  // Playing time of the tape

public:
    // Default constructor
    Tape() : playingTime(0.0) {}

    // Function to input data for Tape
    void inputTapeData() {
        try {
            inputPublicationData();  // Input base class data
            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;
            cin.ignore(); // Clear input buffer

            // Validate input
            if (playingTime < 0) {
                throw runtime_error("Playing time cannot be negative.");
            }
        } catch (exception& e) {
            // Handle exception and reset data members to zero values
            cout << "Exception: " << e.what() << endl;
            title = "";
            price = 0.0;
            playingTime = 0.0;
        }
    }

    // Function to display Tape data
    void displayTapeData() const {
        displayPublicationData();  // Display base class data
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;       // Create Book object
    Tape tape;       // Create Tape object

    cout << "\nEnter data for book:" << endl;
    book.inputBookData();

    cout << "\nEnter data for tape:" << endl;
    tape.inputTapeData();

    cout << "\n--- Displaying Book Data ---" << endl;
    book.displayBookData();

    cout << "\n--- Displaying Tape Data ---" << endl;
    tape.displayTapeData();

    return 0;
}
