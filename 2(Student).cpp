#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Friend Class
class Display;

class Student {
private:
    string* name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;

    static int studentCount; // Static data member to track the number of students

public:
    // Default Constructor
    Student() {
        name = new string("Unknown");
        rollNumber = 0;
        studentClass = "Unknown";
        division = 'X';
        dateOfBirth = "01-01-2000";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicense = "Unknown";
        studentCount++;
    }

    // Parameterized Constructor
    Student(string name, int rollNumber, string studentClass, char division, string dob, string bloodGroup,
            string address, string telephone, string license) {
        this->name = new string(name);
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dateOfBirth = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = address;
        this->telephoneNumber = telephone;
        this->drivingLicense = license;
        studentCount++;
    }

    // Copy Constructor
    Student(const Student& other) {
        name = new string(*other.name);
        rollNumber = other.rollNumber;
        studentClass = other.studentClass;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicense = other.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        delete name;
        studentCount--;
    }

    // Static Member Function
    static int getStudentCount() {
        return studentCount;
    }

    // Inline Function for setting student details
    inline void setDetails(string name, int rollNumber, string studentClass, char division, string dob,
                           string bloodGroup, string address, string telephone, string license) {
        *(this->name) = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dateOfBirth = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = address;
        this->telephoneNumber = telephone;
        this->drivingLicense = license;
    }

    // Function to input details
    void inputDetails() {
        cout << "Enter Name: ";
        cin.ignore(); // To clear the newline character from the input buffer
        getline(cin, *name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Class: ";
        cin >> studentClass;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        cin >> dateOfBirth;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cin.ignore();
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Enter Driving License Number: ";
        cin >> drivingLicense;
    }

    // Display Function
    void displayDetails() const {
        cout << "Name: " << *name << "\nRoll Number: " << rollNumber << "\nClass: " << studentClass
             << "\nDivision: " << division << "\nDate of Birth: " << dateOfBirth
             << "\nBlood Group: " << bloodGroup << "\nContact Address: " << contactAddress
             << "\nTelephone Number: " << telephoneNumber << "\nDriving License: " << drivingLicense << endl;
    }

    // Friend Class
    friend class Display;
};

// Initialize Static Data Member
int Student::studentCount = 0;

// Friend Class to Access Private Data
class Display {
public:
    void showDetails(const Student& student) {
        cout << "\n[Friend Class Access]\n";
        cout << "Name: " << *student.name << "\nRoll Number: " << student.rollNumber << endl;
    }
};

int main() {
    try {
        int numStudents;

        cout << "Enter the number of students: ";
        cin >> numStudents;

        // Dynamically allocate memory for an array of students
        Student* students = new Student[numStudents];

        // Input details for each student
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nEnter details for Student " << i + 1 << ":" << endl;
            students[i].inputDetails();
        }

        // Display details for each student
        cout << "\nStudent Details:" << endl;
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nStudent " << i + 1 << ":" << endl;
            students[i].displayDetails();
        }

        // Using Static Member Function
        cout << "\nTotal Students: " << Student::getStudentCount() << endl;

        // Deallocate memory
        delete[] students;

    } catch (bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }

    return 0;
}
