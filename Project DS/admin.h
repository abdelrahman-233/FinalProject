#ifndef ADMIN_H
#define ADMIN_H
#include "avlBooksStoring.h" // Include AVL tree functionality
#include "lendingsystem.h"   // Include lending system functionality
#include<vector>
#include<string>

#include "member.h"
using namespace std;

class Admin : public LendingSystem, public AVLTree, public Member {

private:
    string above_user ="ADS";
    string above_pass = "ADS123";

public:
Admin();

void functionality(AVLTree& avlTree, LendingSystem& lending, Member member);

    void aboveall (LendingSystem& lending);
    void view_requests (Member& m);
    
    
    










};
#endif 