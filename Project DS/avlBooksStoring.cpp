#include "avlBooksStoring.h"
#include <iostream>
#include <algorithm> // for the max fn.
#include <iomanip> // For formatted output


using namespace std;


AVLNode::AVLNode(Book book) : book(book), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    else {return node->height;}
}

void AVLTree::updateHeight(AVLNode* node) {
    if (node == nullptr) {
        return;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    cout << "Updated height for " << node->book.title << ": " << node->height << endl;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::insertNode(AVLNode* node, Book book) {
    if (node == nullptr) {
        node = new AVLNode(book);
        bookTitles.push_back(book.title);
        bookISBNs.push_back(book.isbn);
        cout << "Inserted: " << book.title << endl;
        return node;
    }

    if (book.isbn == node->book.isbn) {
        node->book.copy += book.copy;
        return node;
    }

    if (book.isbn < node->book.isbn) {
        node->left = insertNode(node->left, book);
    } else {
        node->right = insertNode(node->right, book);
    }

    updateHeight(node);
    return balanceNode(node);
}

void AVLTree::insert(Book book) {
    root = insertNode(root, book);
}

AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLNode* AVLTree::balanceNode(AVLNode* node) {
    int balance = balanceFactor(node);
    cout<<"Balance factor for node :"<<balance<<endl;
    if (balance > 1) {
            cout<<"r"<<endl;
        if (balanceFactor(node->left) >= 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        cout<<"l"<<endl;
        if (balanceFactor(node->right) <= 0)
            return rotateLeft(node);
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

Book* AVLTree::getByISBN(string isbn) {
    AVLNode* current = root;
    while (current != nullptr) {
        if (isbn == current->book.isbn) {
            cout<<"Book Found!"<<endl;
            cout<<"Copies : "<<current->book.copy<<endl;
            return &(current->book);
        } else if (isbn < current->book.isbn) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout<<"Book isn't available"<<endl;
    return nullptr;
}

void AVLTree::getByName(string name) {
    for (int i = 0; i < bookTitles.size(); i++) {
        if (bookTitles[i] == name) {
            getByISBN(bookISBNs[i]);
            return;
        }
    }
    cout << "Book not found" << endl;
}

AVLNode* AVLTree::findMin(AVLNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

AVLNode* AVLTree::deleteNode(AVLNode* root, string isbn) {
    if (!root) return root;

    if (isbn < root->book.isbn) {
        root->left = deleteNode(root->left, isbn);
    } else if (isbn > root->book.isbn) {
        root->right = deleteNode(root->right, isbn);
    } else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            AVLNode* temp = findMin(root->right);
            root->book = temp->book;
            root->right = deleteNode(root->right, temp->book.isbn);
        }
    }

    if (!root) return root;

    updateHeight(root);
    return balanceNode(root);
}

void AVLTree::inOrderTraversal(AVLNode* node) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->left);

    cout << "Book Title: " << node->book.title << endl;
    cout << "ISBN: " << node->book.isbn << endl;
    cout << "Copies Available: " << node->book.copy << endl;
    cout << "---------------------------" << endl;

    inOrderTraversal(node->right);
}

void AVLTree::display() {
    if (root == nullptr) {
        cout << "The library is empty." << endl;
        return;
    }

    cout << "Library Books (In-Order Traversal):" << endl;
    cout << "===================================" << endl;
    inOrderTraversal(root);
}

bool AVLTree::removeBook(string isbn) {
    if (getByISBN(isbn)) {
        root = deleteNode(root, isbn);
        auto itTitle = find(bookTitles.begin(), bookTitles.end(), isbn);
        auto itISBN = find(bookISBNs.begin(), bookISBNs.end(), isbn);
        if (itTitle != bookTitles.end()) bookTitles.erase(itTitle);
        if (itISBN != bookISBNs.end()) bookISBNs.erase(itISBN);
        return true;
    }
    return false;
}

void AVLTree::printTree(AVLNode* node, int space, int indent) const {
    if (node == nullptr) {
        return;
    }

    space += indent;

    printTree(node->right, space, indent);

    cout << endl;
    for (int i = indent; i < space; i++) {
        cout << " ";
    }
    cout << node->book.title << " (" << node->book.isbn << ")" << endl;

    printTree(node->left, space, indent);
}


    
