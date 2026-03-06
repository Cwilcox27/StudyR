#include <iostream>
#include <limits>
using namespace std;

void clearScreen() { cout << "\033[2J\033[H"; }

void pressEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getIntInput(const string& prompt, int minVal, int maxVal) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= minVal && val <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Enter a number between " << minVal << " and " << maxVal << ".\n";
    }
}

void projectMenu() {
    clearScreen();
    cout << "-- Projects (not implemented yet) --\n";
    pressEnter();
}

void taskMenu() {
    clearScreen();
    cout << "-- Tasks (not implemented yet) --\n";
    pressEnter();
}

void timeMenu() {
    clearScreen();
    cout << "-- Time Tracking (not implemented yet) --\n";
    pressEnter();
}

void reportsMenu() {
    clearScreen();
    cout << "-- Reports (not implemented yet) --\n";
    pressEnter();
}

void mainMenu() {
    while (true) {
        clearScreen();
        cout << "--------------------------------------------------\n";
        cout << "             StudyR — Project Tracker\n";
        cout << "--------------------------------------------------\n";
        cout << "  1. Projects\n";
        cout << "  2. Tasks / Todo List\n";
        cout << "  3. Time Tracking\n";
        cout << "  4. Reports & Summaries\n";
        cout << "  0. Exit\n";
        cout << "--------------------------------------------------\n";

        int choice = getIntInput("Choice: ", 0, 4);
        if (choice == 0) { cout << "  Goodbye!\n"; return; }

        switch (choice) {
            case 1: projectMenu(); break;
            case 2: taskMenu();    break;
            case 3: timeMenu();    break;
            case 4: reportsMenu(); break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}