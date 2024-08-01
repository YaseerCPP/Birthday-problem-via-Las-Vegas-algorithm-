#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function to check if there is a shared birthday in the list
bool hasSharedBirthday(const std::vector<int>& birthdays) {
    // Use a sorted vector to easily find duplicates
    std::vector<int> sorted_birthdays = birthdays;
    std::sort(sorted_birthdays.begin(), sorted_birthdays.end());
    
    // Check for consecutive duplicate entries
    for (size_t i = 1; i < sorted_birthdays.size(); ++i) {
        if (sorted_birthdays[i] == sorted_birthdays[i - 1]) {
            return true; // Shared birthday found
        }
    }
    
    return false; // No shared birthday
}

// Function to simulate one instance of the birthday problem
bool simulateBirthdayProblem(int numPeople) {
    std::vector<int> birthdays(numPeople);
    
    // Assign random birthdays to each person
    for (int i = 0; i < numPeople; ++i) {
        birthdays[i] = rand() % 365; // Random birthday between 0 and 364
    }
    
    // Check if there is a shared birthday
    return hasSharedBirthday(birthdays);
}

int main() {
    const int numSimulations = 10000; // Number of simulations
    const int numPeople = 23; // Number of people in the group

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    int sharedBirthdayCount = 0; // Counter for simulations with at least one shared birthday

    // Run simulations
    for (int i = 0; i < numSimulations; ++i) {
        if (simulateBirthdayProblem(numPeople)) {
            ++sharedBirthdayCount;
        }
    }

    // Calculate the probability
    double probability = static_cast<double>(sharedBirthdayCount) / numSimulations;

    std::cout << "Probability of at least two people sharing a birthday in a group of " << numPeople << " people: " << probability << std::endl;

    return 0;
}
