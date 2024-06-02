#include"BST.h"
#ifndef ArrayBST_h
#define ArrayBST_h
#define MAX 15
class Node{
    public:
    int key;
    int value;
    Node();
    Node(int,int);
};
 class ArrayBST{

    private:
    Node list[MAX];

    public:
    ArrayBST();
    ~ArrayBST();
    bool isEmpty();
    void addBST(int value,int index);
    bool searchBST(int targetkey);
    void removeBST(int targetkey,int root);
    void show();
    
};
#endif