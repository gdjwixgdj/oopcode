#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Map to store state names as keys and their populations as values
    map<string, int> statePopulation;

    // Adding some sample data
    statePopulation["California"] = 39538223;
    statePopulation["Texas"] = 29145505;
    statePopulation["Florida"] = 21538187;
    statePopulation["New York"] = 20201249;
    statePopulation["Pennsylvania"] = 13002700;

    // Display all states and their populations
    cout << "States and their populations:\n";
    for (const auto& state : statePopulation) {
        cout << state.first << ": " << state.second << endl;
    }

    // Prompt user to enter a state name
    string queryState;
    cout << "\nEnter the name of a state to get its population: ";
    getline(cin, queryState);

    // Search for the state in the map
    auto it = statePopulation.find(queryState);
    if (it != statePopulation.end()) {
        // State found
        cout << "Population of " << queryState << ": " << it->second << endl;
    } else {
        // State not found
        cout << "State \"" << queryState << "\" not found in the database.\n";
    }

    return 0;
}
