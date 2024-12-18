#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define a structure for Item records
struct Item {
    int code;           // Item code
    string name;        // Item name
    double cost;        // Item cost
    int quantity;       // Item quantity
};

// Function to input item details
void inputItems(vector<Item>& items, int n) {
    for (int i = 0; i < n; ++i) {
        Item item;
        cout << "Enter details for item " << i + 1 << ":\n";
        cout << "Item Code: ";
        cin >> item.code;
        cin.ignore(); // Ignore leftover newline
        cout << "Item Name: ";
        getline(cin, item.name);
        cout << "Item Cost: ";
        cin >> item.cost;
        cout << "Item Quantity: ";
        cin >> item.quantity;
        items.push_back(item);
    }
}

// Function to display all items
void displayItems(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << "Code: " << item.code
             << ", Name: " << item.name
             << ", Cost: " << item.cost
             << ", Quantity: " << item.quantity << endl;
    }
}

// Function to sort items by code
void sortByCode(vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.code < b.code;
    });
}

// Function to search for an item by code
void searchItem(const vector<Item>& items, int searchCode) {
    auto it = find_if(items.begin(), items.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (it != items.end()) {
        cout << "Item found: Code: " << it->code
             << ", Name: " << it->name
             << ", Cost: " << it->cost
             << ", Quantity: " << it->quantity << endl;
    } else {
        cout << "Item with code " << searchCode << " not found.\n";
    }
}

int main() {
    vector<Item> items;
    int n;

    // Input item records
    cout << "Enter the number of items: ";
    cin >> n;
    inputItems(items, n);

    // Display unsorted items
    cout << "\nUnsorted Items:\n";
    displayItems(items);

    // Sort items by code
    sortByCode(items);
    cout << "\nItems sorted by code:\n";
    displayItems(items);

    // Search for an item by code
    int searchCode;
    cout << "\nEnter item code to search: ";
    cin >> searchCode;
    searchItem(items, searchCode);

    return 0;
}
