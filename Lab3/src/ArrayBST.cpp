
#include<iostream>
#include"ArrayBST.h"
using namespace std;

Node::Node() //default constructor
{
    key = 0;
    value = 0;
}
Node::Node(int key, int value)//Parameterized constructor
{
    this->key = key;
    this->value = value;
}
ArrayBST::ArrayBST()//default constructor
{
    for (int i = 0; i < MAX; i++)
    {
        list[i].value = -1; //assigns -1 to all the node's values: -1 indicates that the node is empty

        list[i].key = i;
    }
}
// A function  to check  if the binary search tree is empty

bool ArrayBST::isEmpty()
{
 if (list[1].value == -1)
    {
        return true;
    }
else
    {
        return false;
    }
}
// A function to insert elements in the Binary search Tree
void ArrayBST::addBST(int data, int index)
{
 static int i,j;
    if(list[index].value==-1)
    {
        list[index].value=data;
        return;
    }
    {
        if (data < list[index].value)
        {
            i = index * 2;
            addBST(data, i);
        }
        else
        {
            j = index * 2 + 1;
            addBST(data, j);
        }
    }
}
void ArrayBST::show()
{
    for (int i = 0; i < MAX; i++)
    {

        cout << "key: " << list[i].key << " value: " << list[i].value <<endl;
    }
}
//A function to search any element in the BST
bool ArrayBST::searchBST(int targetkey)
{
    int i = 1;
    while (i <= MAX)
    {
        if (list[i].value == targetkey)
        {
            cout << "The given element: "<<targetkey<<" Exists! " << endl;
            return true;
        }
        else if (targetkey < list[i].value)
        {
            // If the target key is less than the current node, go to its left child.
            i = 2 * i;
        }
        else
        {
            // If the target key is greater than the current node, go to its right child.
            i = 2 * i + 1;
        }
    }
    cout<<"The given element: "<<targetkey<<" does not exist!"<<endl;
    return false;
}
//A function that removes targeted node from the BST
void ArrayBST:: removeBST(int targetkey,int root ){
    int i = root;
    for(;i<MAX;i++){
    if (list[i].value == targetkey)
    {
        Node right = list[2 * i + 1]; //right child
        Node left = list[2 * i];//left child
        if (right.value == -1 && left.value == -1)
        {
            list[i].value = -1;
        }
        else if (right.value == -1)
        {
            list[i].value = left.value;
            removeBST(left.value, 2 * i );
        }
        else if (left.value == -1)
        {
            list[i].value = right.value;
            removeBST(right.value, 2 * i+1);
        }
        else
        {
            int max;
            int j = 2 * i; // position of the right child
            while (list[j].value != -1)
            {
                j = 2 * j + 1;
            }
            max = (j - 1) / 2;
            list[i].value = list[max].value;
            list[max].value = -1;
        }
    }
        }
}
