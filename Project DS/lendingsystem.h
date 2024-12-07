#ifndef LENDING_SYSTEM_H
#define LENDING_SYSTEM_H

#include "avlBooksStoring.h"
#include <vector>
#include <string>
#include <ctime> // For due dates and calculating late fees

using namespace std;

// Struct to manage loan details
struct Loaning {
    Book loanedBook;         // Book associated with the loan
    time_t dueDate;          // Due date for returning the book
    time_t returnDate;       // Actual return date (0 if not returned yet)
    double dailyPenalty;     // Penalty per day for late returns
    double totalFee;         // Total fee calculated
    int LID;
    Loaning ();

};

// Lending system class
class LendingSystem {
public:

    vector<int> memberIds;        // Member IDs
    vector<string> memberNames;   // Member names (same index as IDs)
    vector<Loaning> loans;        // Active loans

    vector <string> username;
    vector <string> password;


    // Constructor
    LendingSystem();

    bool isMember(int id);
    void addAdmin (string& user, string& pass);
    bool isAdmin (const string& user, const string& pass);
    // Book lending functionality
    bool lendBook(string bookID, int memberID, AVLTree& avltree); // Lend a book to a member
    bool returnBook(string bookID, int memberID, AVLTree& avltree);     // Mark a book as returned

    // Fee calculation
    void calculateFee(Loaning& loan); // Calculate late fee for a specific loan
    void displayLoans() const;        // Display all active loans
    void addMember(const string& name, int id);
    void viewMembers ();
};


#endif
