#include <iostream>
#include "admin.h"      // Include Admin class which inherits LendingSystem and AVLTree
#include "avlBooksStoring.h"  // Include AVL tree functionality
#include "lendingsystem.h" // Include Lending system functionality
#include "member.h"   // Include member functionality
#include <vector>
#include<string>
using namespace std;

int main() {
    // Create an Admin object
    AVLTree avltree;
    LendingSystem LS;
    Admin adminsystem;
    Member member;



    // Add admins for testing
    string x="aa";
    string y="bb";
    adminsystem.addAdmin(x,y);
    string usernames[] = {"admin1", "admin2", "admin3", "admin4", "admin5"};
    string passwords[] = {"password123", "admin456", "pass789", "securepass", "qwerty2024"};
    for (int i = 0; i < 5; i++) {
        adminsystem.addAdmin(usernames[i], passwords[i]);
    }




    //Members for Testing
    string a = "Abdelrahman Eid";
    int id = 2004;
    LS.addMember(a,id);
    string names[] = {
        "ali hassan", "mohamed ali", "salma farouk", "sara ibrahim", "ahmed kamal",
        "noor khaled", "nada amr", "omar sameh", "youssef tarek", "fatma said",
        "hanan nabil", "ibrahim adel", "tamer magdy", "malak reda", "jana eid"
    };

    // Array of IDs
    int ids[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010,
                 1011, 1012, 1013, 1014, 1015};

    // Add members with predefined names and IDs
    for (int i = 0; i < 15; i++) {
        LS.addMember(names[i], ids[i]);
    }





    // Add books to AVL tree for testing
Book book1("9780743273565", "The Great Gatsby", 5);
Book book2("9780451524935", "1984", 3);
Book book3("9780061120084", "To Kill a Mockingbird", 4);
Book book4("9780307277671", "The Road", 7);
Book book5("9780140283334", "The Catcher in the Rye", 5);
Book book6("9780385755867", "The Book Thief", 6);
Book book7("9781501128034", "It Ends with Us", 4);
Book book8("9780743477123", "Romeo and Juliet", 5);
Book book9("9781449483186", "Milk and Honey", 6);
Book book10("9780062315007", "The Alchemist", 7);
Book book11("9780060935467", "Brave New World", 8);
Book book12("9780385472579", "Things Fall Apart", 6);
Book book13("9781501139153", "Verity", 5);
Book book14("9780060838676", "Night", 4);
Book book15("9780525559474", "Where the Crawdads Sing", 9);
Book book16("9780062498533", "Becoming", 6);
Book book17("9781982163681", "The Seven Husbands of Evelyn Hugo", 5);
Book book18("9780385333849", "My Sister's Keeper", 7);
Book book19("9780143127741", "A Man Called Ove", 6);
Book book20("9781250279192", "It Starts with Us", 4);
Book book21("9780439023481", "The Hunger Games", 8);
Book book22("9781451673319", "Fahrenheit 451", 7);
Book book23("9780142437230", "Moby Dick", 5);
Book book24("9780141439600", "Wuthering Heights", 4);
Book book25("9780553386790", "The Road to Character", 6);
Book book26("9780316769488", "Of Mice and Men", 7);
Book book27("9780679783268", "Pride and Prejudice", 6);
Book book28("9780140177398", "Eden", 4);
Book book29("9780316015844", "Twilight", 9);
Book book30("9780735219090", "The Book", 5);
Book book31("9780375703768", "Beloved", 6);
Book book32("9780451526342", "Animal Farm", 8);
Book book33("9780525559474", "The Outsiders", 5);
Book book34("9780345803481", "Fifty Shades of Grey", 4);
Book book35("9780156027328", "Life of Pi", 6);
Book book36("9780060899226", "The Art of War", 7);
Book book37("9780307474278", "Eat, Pray, Love", 6);
Book book38("9780743262170", "Angels and Demons", 8);
Book book39("9780062024039", "Divergent", 5);
Book book40("9780062387240", "The Subtle Art of Not Giving a F*ck", 7);
    avltree.insert(book1);
    avltree.insert(book2);
    avltree.insert(book3);
    avltree.insert(book1);
    avltree.insert(book2);
    avltree.insert(book3);
    avltree.insert(book4);
    avltree.insert(book5);
    avltree.insert(book6);
    avltree.insert(book7);
    avltree.insert(book8);
    avltree.insert(book9);
    avltree.insert(book10);
    avltree.insert(book11);
    avltree.insert(book12);
    avltree.insert(book13);
    avltree.insert(book14);
    avltree.insert(book15);
    avltree.insert(book16);
    avltree.insert(book17);
    avltree.insert(book18);
    avltree.insert(book19);
    avltree.insert(book20);
    avltree.insert(book21);
    avltree.insert(book22);
    avltree.insert(book23);
    avltree.insert(book24);
    avltree.insert(book25);
    avltree.insert(book26);
    avltree.insert(book27);
    avltree.insert(book28);
    avltree.insert(book29);
    avltree.insert(book30);
    avltree.insert(book31);
    avltree.insert(book32);
    avltree.insert(book33);
    avltree.insert(book34);
    avltree.insert(book35);
    avltree.insert(book36);
    avltree.insert(book37);
    avltree.insert(book38);
    avltree.insert(book39);
    avltree.insert(book40);








    //Requests for Testing
    string lbookTitles[] = {
        "The Great Gatsby", "1984", "To Kill a Mockingbird", "The Road", "The Catcher in the Rye",
        "The Book Thief", "It Ends with Us", "Romeo and Juliet", "Milk and Honey", "The Alchemist"
    };
    for (int i = 0; i < 15; ++i) {
        Request newRequest;
        newRequest.bookTitle = lbookTitles[i%10];
        newRequest.name = names[i];
        newRequest.ID = to_string(ids[i]);
        newRequest.status = "Pending";

        // Simulate adding a request
        member.myRequests.push_back(newRequest);
    }
    // Display all requests for verification
    cout << "\nAll Loan Requests Created:\n";
    for (size_t i = 0; i < member.myRequests.size(); ++i) {
        cout << "Request #" << i + 1 << ":\n";
        cout << "  Member Name: " << member.myRequests[i].name << endl;
        cout << "  Member ID: " << member.myRequests[i].ID << endl;
        cout << "  Book Title: " << member.myRequests[i].bookTitle << endl;
        cout << "  Status: " << member.myRequests[i].status << endl;
    }


//Some Loans for testing

    Loaning loan1;
    loan1.loanedBook = book1;
    loan1.LID = 1001;
    loan1.dueDate = time(0) - 5 * 24 * 60 * 60; // Overdue by 5 days
    loan1.returnDate = 0;
    loan1.dailyPenalty = 1.6;
    loan1.totalFee = 0;
    LS.loans.push_back(loan1);
    Loaning loan2;
    loan2.loanedBook = book2;
    loan2.LID = 1002;
    loan2.dueDate = time(0) + 7 * 24 * 60 * 60; // Due in 7 days
    loan2.returnDate = 0;
    loan2.dailyPenalty = 1.6;
    loan2.totalFee = 0;
    LS.loans.push_back(loan2);
    Loaning loan3;
    loan3.loanedBook = book1;
    loan3.LID = 1002;
    loan3.dueDate = time(0) - 3 * 24 * 60 * 60; // Overdue by 3 days
    loan3.returnDate = 0;
    loan3.dailyPenalty = 1.6;
    loan3.totalFee = 0;
    LS.loans.push_back(loan3);
    Loaning loan4;
    loan4.loanedBook = book3;
    loan4.LID = 1003;
    loan4.dueDate = time(0) + 5 * 24 * 60 * 60; // Due in 5 days
    loan4.returnDate = 0;
    loan4.dailyPenalty = 1.6;
    loan4.totalFee = 0;
    LS.loans.push_back(loan4);
    Loaning loan5;
    loan5.loanedBook = book4;
    loan5.LID = 1004;
    loan5.dueDate = time(0) - 10 * 24 * 60 * 60; // Overdue by 10 days
    loan5.returnDate = 0;
    loan5.dailyPenalty = 1.6;
    loan5.totalFee = 0;
    LS.loans.push_back(loan5);
    Loaning loan6;
    loan6.loanedBook = book5;
    loan6.LID = 1005;
    loan6.dueDate = time(0) + 3 * 24 * 60 * 60; // Due in 3 days
    loan6.returnDate = 0;
    loan6.dailyPenalty = 1.6;
    loan6.totalFee = 0;
    LS.loans.push_back(loan6);
    Loaning loan7;
    loan7.loanedBook = book3;
    loan7.LID = 1003;
    loan7.dueDate = time(0) - 1 * 24 * 60 * 60; // Overdue by 1 day
    loan7.returnDate = 0;
    loan7.dailyPenalty = 1.6;
    loan7.totalFee = 0;
    LS.loans.push_back(loan7);




        int choice;
        bool running = true; // Flag to control the loop
        while (running) {
            // Main Menu
            cout << "\nWelcome to the library's system!" << endl;
            cout << "---------------------------------" << endl;
            cout << "1. Log in as Admin" << endl;
            cout << "2. Log in as Member" << endl;
            cout << "3. Exit the system" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            // Handle input
            switch (choice) {
                case 1:
                    adminsystem.functionality(avltree, LS, member);
                break;
                case 2:
                    member.functionality(avltree, LS);
                break;
                case 3:
                    cout << "Exiting the system. Goodbye!" << endl;
                running = false;
                break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        return 0;
    }
