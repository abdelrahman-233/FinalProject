#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "avlBooksStoring.h" // Include AVLTree definition
#include "lendingSystem.h"   // Include LendingSystem definition

using namespace std;

struct Request {
    string ID;
    string name;
    string bookTitle;
    string status; // "Pending", "Approved", "Rejected"
};

class Member {
public:
    string loggedInName;
    int loggedInID;
    bool isLoggedIn;
    vector<Request> myRequests; // Store individual member requests


    Member();

    // Login functionality
    bool login(const LendingSystem& lending);

    // View available books
    void viewAvailableBooks(AVLTree& avlTree);

    // View member-specific loans
    void viewMyLoans(LendingSystem& lending);

    // Apply for a loan
    void applyForLoan();

    // View requests specific to the logged-in member
    void viewMyRequests() const;


    void functionality(AVLTree& avlTree, LendingSystem& lending);
};
#endif // MEMBER_H
