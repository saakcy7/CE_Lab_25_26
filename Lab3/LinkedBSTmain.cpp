#include"LinkedBST.h"
#include<iostream>
int main()
{
    
    LinkedBST *t = new LinkedBST();
    t->isEmpty();
    t->searchBST(81);
    t->addBST(23);
    t->addBST(20);
    t->addBST(65);
    t->addBST(10);
    t->addBST(21);
    t->addBST(40);
    t->addBST(75);
    t->addBST(5);
    t->addBST(15);
    t->addBST(19);
    t->addBST(22);
    t->addBST(37);
    t->addBST(50);
    t->addBST(71);
    t->addBST(80);
    t->display();
    std::cout<<std::endl;
    t->isEmpty();
    
    t->removeBST(5);
    t->removeBST(10);
    t->removeBST(21);
    t->removeBST(19);
    t->removeBST(15);
    
    t->display();
}