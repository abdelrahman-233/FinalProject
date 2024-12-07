#include "member.h"
#include <iostream>
#include <ctime>

using namespace std;
#include "member.h"
#include <iostream>
#include <limits> // For numeric_limits
#include <ctime> // For ctime conversion

using namespace std;

Member::Member() : loggedInName(""), loggedInID(0), isLoggedIn(false) {}

bool Member::login(const LendingSystem& lending) {
    string name;
    int id;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your ID: ";
    cin >> id;

    // Verify credentials
    for (size_t i = 0; i < lending.memberNames.size(); i++) {
        if (lending.memberNames[i] == name && lending.memberIds[i] == id) {
            loggedInName = name;
            loggedInID = id;
            isLoggedIn = true;
            cout << "Login successful!" << endl;
            return true;
        }
    }

    cout << "Invalid name or ID." << endl;
    return false;
}

void Member::viewAvailableBooks(AVLTree& avlTree) {
    if (!isLoggedIn) {
        cout << "Please log in first." << endl;
        return;
    }

    cout << "\n--- Available Books ---\n";
    avlTree.display(); // Display books in the AVLTree
}

void Member::viewMyLoans(LendingSystem& lending) {
    if (!isLoggedIn) {
        cout << "Please log in first." << endl;
        return;
    }

    cout << "\n--- Your Loans ---\n";
    bool hasLoans = false;

    for (const auto& loan : lending.loans) {
        if (loan.LID == loggedInID) {
            cout << "Book Title: " << loan.loanedBook.title << endl;
            cout << "Due Date: " << ctime(&loan.dueDate); // Convert timestamp to human-readable form
            cout << "-------------------------" << endl;
            hasLoans = true;
        }
    }

    if (!hasLoans) {
        cout << "You have no loans." << endl;
    }
}

void Member::applyForLoan() {
    if (!isLoggedIn) {
        cout << "Please log in first." << endl;
        return;
    }

    Request newRequest;
    cout << "Enter the title of the book you want to request: ";
    cin.ignore();
    getline(cin, newRequest.bookTitle);
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, newRequest.name);
    cout << "Enter your ID: ";
    cin.ignore();
    getline(cin, newRequest.ID);
    newRequest.status = "Pending";

    myRequests.push_back(newRequest);
    cout << "Your loan application has been submitted and is pending approval." << endl;
}


void Member::viewMyRequests() const {
    if (!isLoggedIn) {
        cout << "Please log in first." << endl;
        return;
    }
    string i;
    cout<<"Enter your ID : "<<endl;
    cin>>i;
    cout << "\n--- Your Requests ---\n";
    if (myRequests.empty()) {
        cout << "You have no requests." << endl;
        return;
    }

    for (const auto& req : myRequests) {
        if (req.ID==i) {
            cout << "Book Title: " << req.bookTitle << endl;
            cout << "Status: " << req.status << endl;
            cout << "-------------------------" << endl;
        }
    }
}



void Member::functionality(AVLTree& avlTree, LendingSystem& lending) {
    if (!login(lending)) {
        cout << "Login failed. Returning to main menu." << endl;
        return;
    }

    int choice;
    do {
        cout << "\n--- Member Menu ---\n";
        cout << "1. View Available Books\n";
        cout << "2. View My Loans\n";
        cout << "3. Apply for a Loan\n";
        cout << "4. View My Requests\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                viewAvailableBooks(avlTree);
            break;
            case 2:
                viewMyLoans(lending);
            break;
            case 3:
                applyForLoan();
            break;
            case 4:
                viewMyRequests();
            break;
            case 5:
                cout << "Logging out..." << endl;
            isLoggedIn = false; // Reset login status
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

