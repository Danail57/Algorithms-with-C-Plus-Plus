// Write a program that prints all words, that
// can be read, starting from the beginning of the tree
// reaching to any of the leafs




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor for a regular node
    Node(int value, Node* nil_node)
    {
        data = value;
        left = nil_node;
        right = nil_node;
    }

    // Constructor for NIL node
    Node()
    {
        data = 0;
        left = this;
        right = this;
    }
};

// Insert function
void insert(Node*& root, int value, Node* NIL)
{
    if (root == NIL)
    {
        root = new Node(value, NIL);
        return;
    }

    if (value < root->data)
        insert(root->left, value, NIL);
    else
        insert(root->right, value, NIL);
}

// Print all paths from root to leaves
void print_paths(Node* node, Node* NIL, vector<int>& path)
{
    if (node == NIL)
        return;

    path.push_back(node->data);

    if (node->left == NIL && node->right == NIL)
    {
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";

        cout << endl;
    }
    else
    {
        print_paths(node->left, NIL, path);
        print_paths(node->right, NIL, path);
    }

    path.pop_back();
}

// Calculate tree height
int tree_height(Node* node, Node* NIL)
{
    if (node == NIL)
        return 0;

    int leftHeight = tree_height(node->left, NIL);
    int rightHeight = tree_height(node->right, NIL);

    return 1 + max(leftHeight, rightHeight);
}

// Print tree
void print_tree(Node* node, Node* NIL, int space = 0)
{
    if (node == NIL)
        return;

    space += 6;

    print_tree(node->right, NIL, space);

    cout << endl;

    for (int i = 6; i < space; i++)
        cout << " ";

    cout << node->data << endl;

    print_tree(node->left, NIL, space);
}

int main()
{
    Node* NIL = new Node();
    Node* root = NIL;

    int numbers, num;

    cout << "How many numbers you want to write? ";
    cin >> numbers;

    for (int i = 0; i < numbers; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;

        insert(root, num, NIL);
    }

    vector<int> path;

    cout << "\nAll paths from root to leaves:\n";
    print_paths(root, NIL, path);

    cout << "\nHeight of the tree: ";
    cout << tree_height(root, NIL) << endl;

    cout << "\nBinary Search Tree:\n";
    print_tree(root, NIL);

    return 0;
}
