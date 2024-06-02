#include"BST.h"

class Node
{
    public:
        int info;
        Node *left;
        Node *right;
        Node *parent;
        Node (int infoin);    
};

class LinkedBST
{
    private:
        Node *root;

    public:
        LinkedBST();
        ~LinkedBST(){}    
        bool isEmpty();
        void addBST(int data);
        void removeBST(int data);
        bool searchBST(int data);
        void inorder(Node * root); 
        void display();
};