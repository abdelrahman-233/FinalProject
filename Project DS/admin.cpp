
#include "admin.h"
#include <iostream>
using namespace std;

// Constructor
Admin::Admin() {}
void Admin::view_requests(Member &m) {
    // Display all requests
    for (int x = 0; x < m.myRequests.size(); x++) {
        cout << "Request Index: " << x << endl; // For easier identification
        cout << "Name: " << m.myRequests[x].name << endl;
        cout << "ID: " << m.myRequests[x].ID << endl;
        cout << "Book: " << m.myRequests[x].bookTitle << endl;
        cout << "Status: " << m.myRequests[x].status << endl;
        cout << "-------------------------" << endl;
    }

    int a;
    if (!m.myRequests.empty())
    {cout << "Do you wish to change the status of a request?" << endl;
        cout << "Enter 1 for Yes, 2 for No: ";
        cin >> a;

        if (a == 1) {
            int ind;
            string newStatus;
            cout << "Enter the index of the request to update (as shown above): ";
            cin >> ind;

            if (ind >= 0 && ind < m.myRequests.size()) { // Ensure valid index
                cout << "Enter the new status (e.g., Approved, Rejected, Pending): ";
                cin.ignore(); // Clear input buffer
                getline(cin, newStatus);

                // Update the status
                m.myRequests[ind].status = newStatus;
                cout << "Request status updated successfully!" << endl;
            } else {
                cout << "Invalid index entered. No changes made." << endl;
            }
        } else {
            cout << "No changes were made to the requests." << endl;
        }
    }
}


/*void Admin::functionality(AVLTree& avlTree, LendingSystem& lending) {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    if (!isAdmin(user, pass)) {
        cout << "Invalid username or password!" << endl;
        return;
    }

    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Admin (High-Clearance Functionality)\n";
        cout << "2. Add Book\n";
        cout << "3. Remove Book\n";
        cout << "4. Add Member\n";
        cout << "5. Lend Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Loans\n";
        cout << "8. Display Books\n";
        cout << "9. View Active Members\n";
        cout << "10. View Requests\n"; // Added view requests
        cout << "11. Delete Book by Isbn\n"; // Added delete books
        cout << "12. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                aboveall(lending); // Call `aboveall` function
                break;
            }
            case 2: {
                string title, isbn, author;
                int year, copies;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book ISBN: ";
                cin >> isbn;
                cout << "Enter book author: ";
                cin.ignore();
                getline(cin, author);
                cout << "Enter book year: ";
                cin >> year;
                cout << "Enter number of copies: ";
                cin >> copies;
                Book newBook(isbn, title, author, year, copies);
                avlTree.insert(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 3: {
                string isbn;
                cout << "Enter ISBN of the book to remove: ";
                cin >> isbn;
                if (avlTree.removeBook(isbn)) {
                    cout << "Book removed successfully!" << endl;
                } else {
                    cout << "Failed to remove book!" << endl;
                }
                break;
            }
            case 4: {
                string name;
                int id;
                cout << "Enter member name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter member ID: ";
                cin >> id;
                lending.addMember(name, id);
                cout << "Member added successfully!" << endl;
                break;
            }
            case 5: {
                string bookID;
                int memberID;
                cout << "Enter the ID of the member you're lending to: ";
                cin >> memberID;
                cout << "Enter book ID to lend: ";
                cin >> bookID;

                if (lending.lendBook(bookID, memberID, avlTree)) {
                    cout << "Book lent successfully!" << endl;
                } else {
                    cout << "Failed to lend book!" << endl;
                }
                break;
            }
            case 6: {
                string bookID;
                int memberID;
                cout << "Enter book ID to return: ";
                cin >> bookID;
                cout << "Enter member ID: ";
                cin >> memberID;
                if (lending.returnBook(bookID, memberID, avlTree)) {
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Failed to return book!" << endl;
                }
                break;
            }
            case 7:
                lending.displayLoans();
                break;
            case 8:
                avlTree.display();
                break;
            case 9:
                lending.viewMembers();
                break;
            case 10: {
                Member member; // Assuming you provide the `Member` object as required
                view_requests(member); // Call view requests
                break;
            }
            case 11: {
                string isbn;
                cout << "Enter the isbn of the book to delete: ";
                cin.ignore();
                getline(cin, isbn);

                if (avlTree.removeBook(isbn)) { // Ensure this function exists in AVLTree
                    cout << "Book deleted successfully!" << endl;
                } else {
                    cout << "Failed to delete book!" << endl;
                }
                break;
            }
            case 12:
                cout << "Exiting admin functionalities..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 12);
}*/






void Admin::functionality(AVLTree& avlTree, LendingSystem& lending, Member member) {
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    if (!isAdmin(user, pass)) {
        cout << "Invalid username or password!" << endl;
        return;
    }

    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Admin (High-Clearance Functionality)\n";
        cout << "2. Add Book\n";
        cout << "3. Remove Book\n";
        cout << "4. Add Member\n";
        cout << "5. Lend Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Loans\n";
        cout << "8. Display Books\n";
        cout << "9. View Active Members\n";
        cout << "10. View Requests\n";
        cout << "11. Delete Book by ISBN\n";
        cout << "12. Search for Book by ISBN\n"; // Added
        cout << "13. Search for Book by Name\n"; // Added
        cout << "14. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                aboveall(lending);
                break;
            }
            case 2: {
                string title, isbn, author;
                int year, copies;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book ISBN: ";
                cin >> isbn;
                cout << "Enter book author: ";
                cin.ignore();
                getline(cin, author);
                cout << "Enter book year: ";
                cin >> year;
                cout << "Enter number of copies: ";
                cin >> copies;
                Book newBook(isbn, title, author, year, copies);
                avlTree.insert(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 3: {
                string isbn;
                cout << "Enter ISBN of the book to remove: ";
                cin >> isbn;
                if (avlTree.removeBook(isbn)) {
                    cout << "Book removed successfully!" << endl;
                } else {
                    cout << "Failed to remove book!" << endl;
                }
                break;
            }
            case 4: {
                string name;
                int id;
                cout << "Enter member name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter member ID: ";
                cin >> id;
                lending.addMember(name, id);
                cout << "Member added successfully!" << endl;
                break;
            }
            case 5: {
                string bookID;
                int memberID;
                cout << "Enter the ID of the member you're lending to: ";
                cin >> memberID;
                cout << "Enter book ID to lend: ";
                cin >> bookID;

                if (lending.lendBook(bookID, memberID, avlTree)) {
                    cout << "Book lent successfully!" << endl;
                } else {
                    cout << "Failed to lend book!" << endl;
                }
                break;
            }
            case 6: {
                string bookID;
                int memberID;
                cout << "Enter book ID to return: ";
                cin >> bookID;
                cout << "Enter member ID: ";
                cin >> memberID;
                if (lending.returnBook(bookID, memberID, avlTree)) {
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Failed to return book!" << endl;
                }
                break;
            }
            case 7:
                lending.displayLoans();
                break;
            case 8:
                avlTree.display();
                break;
            case 9:
                lending.viewMembers();
                break;
            case 10: {;
                view_requests(member);
                break;
            }
            case 11: {
                string isbn;
                cout << "Enter the ISBN of the book to delete: ";
                cin.ignore();
                getline(cin, isbn);

                if (avlTree.removeBook(isbn)) {
                    cout << "Book deleted successfully!" << endl;
                } else {
                    cout << "Failed to delete book!" << endl;
                }
                break;
            }
            case 12: {
                string isbn;
                cout << "Enter ISBN to search for: ";
                cin >> isbn;
                Book* foundBook = avlTree.getByISBN(isbn);
                if (foundBook) {
                    cout << "Book found: " << foundBook->title << ", copies: " << foundBook->copy << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 13: {
                string name;
                cout << "Enter book name to search for: ";
                cin.ignore();
                getline(cin, name);
                avlTree.getByName(name);
                break;
            }
            case 14:
                cout << "Exiting admin functionalities..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 14);
}



void Admin::aboveall(LendingSystem& lending) {
    string inputUser, inputPass;
    int a;
    cout << "This functionality requires high-level clearance." << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter the username: ";
    cin >> inputUser;
    cout << "Enter the password: ";
    cin >> inputPass;

    // Check the high-level credentials
    if (inputUser == above_user && inputPass == above_pass) {
        string newAdminUser, newAdminPass;
        cout << "Enter the username of the new admin: ";
        cin >> newAdminUser;
        cout << "Enter the password of the new admin: ";
        cin >> newAdminPass;
        lending.addAdmin(newAdminUser, newAdminPass);
        cout<<"Admin added successfully"<<endl;
    } else {
        cout << "Invalid high-level credentials. Access denied!" << endl;
    }
}
