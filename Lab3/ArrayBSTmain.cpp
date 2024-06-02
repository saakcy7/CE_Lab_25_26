
#include<iostream>
#include"BST.h"
#include"arrayBST.h"
using namespace std; //declaring std on global namespace

int main()
{
    cout<<endl<<endl<<endl;

    cout<<"Array Implementation of Binary Tree"<<endl;
    
    ArrayBST *BST = new ArrayBST(); // creating instance of class ArrayBST
    if(BST->isEmpty())
    {
                cout<<"The BST is Empty !"<<endl<<endl;

    }
    else{
                cout<<"The BST is not Empty !"<<endl<<endl;

    }
    
    /*Addition of Data in Binary Search Tree*/
    BST->addBST(30, 1);
    BST->addBST(10, 1);
    BST->addBST(40, 1);
    BST->addBST(20, 1);
    BST->addBST(50, 1);
    BST->addBST(7, 1);
    BST->addBST(35, 1);
    BST->addBST(45, 1);
    BST->show();

    cout<<endl;
    
    BST->searchBST(55);
    BST->searchBST(35);
    cout<<endl;

    BST->removeBST(35,1);
    BST->show();

    cout<<endl;
}