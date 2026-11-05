// Write a program that models ordered binary
// tree with some numbers, which must be
// sorted in ascending and descending order
// - add function to count nodes

// - add function which prints all
// elements smaller than the root

// - add function which shows the root only


#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor for regular nodes (takes the sentinel node as default children)
    Node(int val, Node* nil_node) {
        data = val;
        left = nil_node;
        right = nil_node;
    }

    // Constructor specifically for the sentinel (NIL) node
    Node() 
    {
        data = 0;
        left = this;
        right = this;
    }
};

// Function to insert a value into the Binary Search Tree without using nullptr
void insert(Node*& root, int val, Node* nil_node) 
{
    if (root == nil_node) 
    {
        root = new Node(val, nil_node);
        return;
    }
    if (val < root->data) 
    {
        insert(root->left, val, nil_node);
    }
    else if (val > root->data) 
    {
        insert(root->right, val, nil_node);
    }
}

// Function to print the tree in ascending order (In-order traversal: Left -> Root -> Right)
void print_ascending(Node* node, Node* nil_node) 
{
    if (node == nil_node) return;
    print_ascending(node->left, nil_node);
    cout << node->data << " ";
    print_ascending(node->right, nil_node);
}

// Function to print the tree in descending order (Reverse in-order traversal: Right -> Root -> Left)
void print_descending(Node* node, Node* nil_node) 
{
    if (node == nil_node) return;
    print_descending(node->right, nil_node);
    cout << node->data << " ";
    print_descending(node->left, nil_node);
}


// Function to print all elements smaller than the root
void print_smaller_than_root(Node* node, Node* root, Node* nil_node)
{
    if (node == nil_node)
    {
        return;
    }

    print_smaller_than_root(node->left, root, nil_node);

    if (node->data < root->data)
    {
        cout << node->data << " ";
    }

    print_smaller_than_root(node->right, root, nil_node);
}


// Function to count the nodes in the Binary Search Tree
int count_nodes(Node* node, Node* nil_node)
{
    if (node == nil_node)
    {
        return 0;
    }

    return 1 + count_nodes(node->left, nil_node) 
        + count_nodes(node->right, nil_node);
}


// Function to print the root only
void print_root(Node* root, Node* nil_node)
{
    if (root == nil_node)
    {
        cout << "The tree is empty!" << endl;
        return;
    }

    cout << root->data;
}


// Function for Pre-order traversal
void print_preorder(Node* node, Node* nil_node)
{
    if (node == nil_node)
        return;

    cout << node->data << " ";

    print_preorder(node->left, nil_node);
    print_preorder(node->right, nil_node);
}



// Function for Post-order traversal
void print_postorder(Node* node, Node* nil_node)
{
    if (node == nil_node)
        return;

    print_postorder(node->left, nil_node);
    print_postorder(node->right, nil_node);

    cout << node->data << " ";
}



int main() 
{
    // Create a sentinel node to replace nullptr
    Node* NIL = new Node();

    Node* root = NIL;

    // Numbers to insert into the tree
    int numbers, num;
    cout << "How many numbers do you want to write? ";
    cin >> numbers;
    for (int i = 0; i < numbers; i++)
    {
        cout << "Enter number " << i + 1 << endl;
        cin >> num;
        insert(root, num, NIL);
    }


    cout << "Tree elements in Ascending order: ";
    print_ascending(root, NIL);
    cout << endl;

    cout << "Tree elements in Descending order: ";
    print_descending(root, NIL);
    cout << endl;

    cout << "Number of nodes in the tree: ";
    cout << count_nodes(root, NIL) << endl;

    cout << "Elements smaller than the root: ";

    if (root != NIL)
    {
        print_smaller_than_root(root, root, NIL);
    }
    cout << endl;

    cout << "Root of the tree: ";
    print_root(root, NIL);
    cout << endl;


    cout << "Pre-order traversal (Root -> Left -> Right): ";
    print_preorder(root, NIL);
    cout << endl;

    cout << "Post-order traversal (Left -> Right -> Root): ";
    print_postorder(root, NIL);
    cout << endl;

    return 0;
}
