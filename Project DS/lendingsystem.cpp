#include "lendingsystem.h"
#include<iostream>
#include <vector>
#include <string>
#include <ctime>
#include<string>

using namespace std;
Loaning::Loaning() {
    loanedBook = Book();           // Default constructor of Book
    dueDate = 0;                   // Default value for due date (0 means no due date initially)
    returnDate = 0;                // Default value for return date (0 means not returned yet)
    dailyPenalty = 0.0;            // No penalty by default
    totalFee = 0.0;                // No fee initially
    LID = -1;                      // Default invalid member ID (-1 means no member)
}
    LendingSystem::LendingSystem() {
        memberIds = {}; // Empty vector for member IDs
        memberNames = {}; // Empty vector for member names
        loans = {}; // Empty vector for active loans
    }

    bool LendingSystem::isMember(int id) {
        for (int i = 0; i < memberIds.size(); i++) {
            if (id == memberIds[i]) {
                return true;
            }
        }
        return false;
    }


bool LendingSystem::lendBook(string bookID, int memberID, AVLTree &avltree) {
    if (avltree.root == nullptr) {
        cout << "Error: AVL tree is empty." << endl;
        return false;
    }

    if (!isMember(memberID)) {
        cout << "Error: No member found with the given ID." << endl;
        return false;
    }

    AVLNode *bookNode = avltree.root;

    // Debug statement to confirm the conversion
    cout << "Searching for book with ID: " << bookID << endl;

    while (bookNode != nullptr) {
        cout << "Checking book: " << bookNode->book.isbn << endl; // Debug output

        if (bookID == bookNode->book.isbn) {
            // Found the book
            if (bookNode->book.copy > 0) {
                bookNode->book.copy--; // Decrease the available copies
                Loaning newLoan;
                newLoan.loanedBook = bookNode->book;                // Assign the book
                newLoan.dueDate = time(0)+ 7 * 24 * 60 * 60;        // Assign due date (7 days from now)
                newLoan.returnDate = 0;                             // Initialize return date to 0
                newLoan.dailyPenalty = 1.6;                         // Set daily penalty
                newLoan.totalFee = 0;                               // Initialize total fee to 0
                newLoan.LID = memberID;                             // Assign member ID
                loans.push_back(newLoan);

                cout << "The book is lent successfully and is due in 7 days." << endl;
                return true;
            } else {
                cout << "Error: No copies of the book are available for lending." << endl;
                return false;
            }
        } else if (bookID < bookNode->book.isbn) {
            bookNode = bookNode->left; // Traverse left
        } else {
            bookNode = bookNode->right; // Traverse right
        }
    }

    cout << "Error: Book not found in the AVL tree." << endl;
    return false;
}


void LendingSystem::calculateFee(Loaning &loan) {
    time_t effectiveReturnDate = loan.returnDate == 0 ? time(0) : loan.returnDate;
    if (effectiveReturnDate > loan.dueDate) {
        // Calculate days late
        double daysLate = difftime(effectiveReturnDate, loan.dueDate) / (60 * 60 * 24);
        loan.totalFee = daysLate * loan.dailyPenalty;
        cout << "Late fee calculated: $" << loan.totalFee << endl;
    } else {
        loan.totalFee = 0.0;
        cout << "No late fee. Book returned on time!" << endl;
    }
}

    bool LendingSystem::returnBook(string bookID, int memberID, AVLTree &avlTree) {
        // Step 1: Find the loan in the loans vector
        for (int i = 0; i < loans.size(); i++) {
            if (loans[i].LID == memberID && loans[i].loanedBook.isbn == bookID) {
                cout << "Loan found!" << endl;

                // Step 2: Calculate late fees
                calculateFee(loans[i]);
                loans.erase(loans.begin()+i);

                // Step 3: Return the book copy in the AVL tree
                AVLNode *current = avlTree.root; // Start at the AVL tree root
                while (current != nullptr) {
                    if (current->book.isbn == bookID) {
                        current->book.copy++; // Increment the book's copy count
                        cout << "Book copy returned to AVL tree." << endl;
                        break;
                    } else if (bookID < current->book.isbn) {
                        current = current->left; // Traverse left
                    } else {
                        current = current->right; // Traverse right
                    }
                }

                if (!current) {
                    cout << "Error: Book not found in AVL tree!" << endl;
                    return false;
                }

                // Step 4: Mark the loan as returned
                loans[i].returnDate = time(0); // Record the current time as return date
                cout << "Loan successfully closed!" << endl;

                return true; // Successful return
            }
        }

        // If no matching loan was found
        cout << "Error: Loan not found or mismatched member/book ID!" << endl;
        return false;
    }
    #include <ctime> // For time_t, localtime, strftime

void LendingSystem::displayLoans() const {
    if (loans.empty()) {
        cout << "No active loans." << endl;
        return;
    }
    for (int y = 0; y < loans.size(); y++) {
        cout << "The name of the book: " << loans[y].loanedBook.title << endl;
        cout << "The ID of the member who took it: " << loans[y].LID << endl;

        // Convert the due date (Unix timestamp) to a human-readable format
        time_t due = loans[y].dueDate; // Get the due date as a Unix timestamp
        char buffer[80]; // Buffer to store the formatted string
        struct tm *timeInfo = localtime(&due); // Convert to local time
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo); // Format the time

        cout << "Due: " << buffer << endl;
        cout << "---------------------------------" << endl;
    }
}


    void LendingSystem::addMember(const string &name, int id) {
        memberIds.push_back(id);
        memberNames.push_back(name);
    }

void LendingSystem::addAdmin( string& user, string& pass) {
    username.push_back(user);
    password.push_back(pass);
    cout << "Admin added successfully!" << endl;
}

bool LendingSystem::isAdmin(const string& user, const string& pass) {
    for (size_t i = 0; i < username.size(); ++i) {
        if (username[i] == user && password[i] == pass) {
            return true;
        }
    }
    return false;
}

void LendingSystem::viewMembers ()
{
    for (int i=0;i<memberNames.size();i++) {
        cout <<"Name: "<<memberNames[i]<<endl;
        cout <<"ID: "<<memberIds[i]<<endl;
    }
}