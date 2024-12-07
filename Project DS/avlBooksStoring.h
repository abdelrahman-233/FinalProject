#ifndef AVLBOOKSSTORING_H
#define AVLBOOKSSTORING_H

#include <string>
#include<vector>
#include <fstream>
using namespace std;

// Define the Book struct
struct Book {
    string isbn;
    string title;
    string author;
    int year;
    int copy;
    Book() : isbn(""), title(""), author(""), year(0), copy(0) {}

    // Constructor with all parameters
    Book(string isbn, string title, string author, int year, int copy) :
        isbn(isbn), title(title), author(author), year(year), copy(copy) {}
    Book (string isbn, string title, int copy) : isbn (isbn), title (title), copy (copy){}

};

// Define the AVLNode struct
struct AVLNode {
    Book book;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Book book);
};

// Declare the AVL Tree class
class AVLTree {
public:
    AVLNode* root;
    vector<string> bookTitles;
    vector<string> bookISBNs;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    void updateHeight(AVLNode* node);
    AVLNode* insertNode(AVLNode* node, Book book);
    AVLNode* balanceNode(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    AVLNode* findMin(AVLNode* node);
    AVLNode* deleteNode(AVLNode* root, string isbn);

    AVLTree();
    void insert(Book book);
    bool removeBook(string isbn);
    Book* getByISBN(string isbn);
    void getByName(string name);
    void inOrderTraversal(AVLNode* node);
    void display();
    void printTree(AVLNode* node, int space = 0, int indent = 6) const;

};

#endif // AVLBOOKSSTORING_H