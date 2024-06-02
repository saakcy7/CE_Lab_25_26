#include"LinkedBST.h"
#include<iostream>

Node::Node(int infoin)
{
    info=infoin;
    left=nullptr;
    right=nullptr;
    parent=nullptr;
}

LinkedBST::LinkedBST()
{
    root=nullptr;
}
bool LinkedBST::isEmpty()
{
    if (root==nullptr)//checks to emptiness of BST
    {
        std::cout<<"BST is Empty"<<std::endl;
        std::cout<<""<<std::endl;
        return true;
    }
    else 
    {
        std::cout<<"BST is not Empty"<<std::endl;
        std::cout<<""<<std::endl;
        return false;
    }
}

void LinkedBST::addBST(int data)
{
    Node *insert= new Node(data);//putting new data into node
    if (root==nullptr)//inserting into root condition
    {
        root = insert;
        root->parent=nullptr;
        return;
    }
    else
    {
        Node *temp=root;
        Node *p=nullptr;
        while (temp!=nullptr)//finding the node to enter data
        {
            p=temp;
            if (data<temp->info) temp=temp->left;
            else if(data>temp->info) temp=temp->right;
        }   
        if (data<p->info) //inserting into the tree
        {
            p->left=insert;
            insert->parent=p;
        }
        else 
        {
            p->right=insert;
            insert->parent=p;
        }
    }
}

void LinkedBST::removeBST(int data) 
{
    Node* p = nullptr;
    Node* temp = root;
    while (temp != nullptr && temp->info != data) 
    {
        p = temp;
        if (data < temp->info) 
        {
            temp = temp->left;
        } else 
        {
            temp = temp->right;
        }
    }   
    if (temp == nullptr) 
    {
        std::cout << "Node not found in the tree." << std::endl;
        return;
    }   
    if (temp->left == nullptr && temp->right == nullptr) 
    {
        if (temp != root) 
        {
            if (p->left == temp) 
            {
                p->left = nullptr;
            } else 
            {
                p->right = nullptr;
            }
        } 
        else 
        {
            root = nullptr;
        }
        delete temp;
    }

    else if (temp->left && temp->right) 
    {
        Node* replacementParent = temp;
        Node* replacement = temp->right;
        while (replacement->left != nullptr) 
        {
            replacementParent = replacement;
            replacement = replacement->left;
        }

        temp->info = replacement->info;

            
        if (replacementParent->left == replacement) 
        {
            replacementParent->left = replacement->right;
        }
        else 
        {
            replacementParent->right = replacement->right;
        }

        delete replacement;
    }
    else 
    {
        Node* child = (temp->left) ? temp->left : temp->right;

        if (temp!= root) 
        {
            if (temp == p->left) 
            {
                p->left = child;
            }
            else 
            {
                p->right = child;
            }
        }
        else
        {
            root = child;
        }
        delete p;
    }
}


bool LinkedBST::searchBST(int data)//checks if data is present or not
{
    Node *temp=root;
    if (root==nullptr)
    {
        std::cout<<"Since The BST is empty,The requested data was not found"<<std::endl;
        std::cout<<""<<std::endl;
        return false;
    }
    while (temp!=nullptr)
    {
        if (data==temp->info)
        {
            std::cout<<"The requested information was found"<<std::endl;
            std::cout<<std::endl;
            return true;
            break;
        }
        else if (data<temp->info)
        {
            temp=temp->left;
        }
        else if (data > temp->info)
        {
            temp=temp->right;
        }
        else
        {
            std::cout<<"Enter an acceptable value"<<std::endl;
            std::cout<<std::endl;
            return false;
            break;
        }
    }
    std::cout<<"The requested information was not found"<<std::endl;
    std::cout<<std::endl;
    return false;
}

void LinkedBST::inorder(Node * Toot)
{
    if (Toot ==nullptr) return;
    inorder(Toot->left);
    std::cout<<"Node data "<<Toot->info<<std::endl;
    inorder(Toot->right);
}
void LinkedBST::display()
{
    std::cout<<std::endl;
    inorder(root);
    std::cout<<std::endl;
}