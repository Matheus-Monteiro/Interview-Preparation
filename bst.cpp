#include <bits/stdc++.h>
using namespace std;

#define INSERT 0
#define SEARCH 1
#define DELETE 2

class Node {
public:
    Node *left;
    Node *right;
    int value;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node() {
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
    Node *root;

    Node* insert(Node *root, int value) {
        if(root == nullptr) {
            return new Node(value);
        }
        if(value < root->value) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    bool search(Node* root, int value) {
        if(root == nullptr) {
            return false;
        }
        if(root->value == value) {
            return true;
        }
        if(value < root->value) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }

    Node* remove(Node* root, int value) {
        if(root == nullptr) {
            return root;
        }
        if(root->value == value) {
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            if(root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = root->right;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
            return root;
        }
        if(value < root->value) {
            root->left = remove(root->left, value);
        } else {
            root->right = remove(root->right, value);
        }
        return root;
    }

public:
    BinarySearchTree() {
        this->root = nullptr;
    }
    void insert(int value) {
        this->root = insert(this->root, value);
    }
    bool search(int value) {
        return search(this->root, value);
    }
    void remove(int value) {
        this->root = remove(this->root, value);
    }
};

int rand(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

void stressTest() {
    srand(7);

    set<int> values;
    BinarySearchTree bst;

    while(true) {
        int operation = rand() % 3;
        cout << "Number of Elemenets in the BST: " << values.size() << endl;
        if(operation == INSERT) { 
            int value = rand(1, 1000000);
            if(values.count(value)) {
                continue;
            } 
            cout << "Inserting Number " << value << endl;
            values.insert(value);
            bst.insert(value);
        } else {
            int minVal = 1;
            int maxVal = 1000000;
            int value = rand(minVal, maxVal);
            if(!values.empty()) {
                minVal = *values.begin();
                maxVal = *values.rbegin();
                value = *values.lower_bound(rand(minVal, maxVal));
            }
            if(operation == SEARCH) {
                if(rand(1, 3) == 2) {
                    value++;
                }
                bool resultSearchBst = bst.search(value);
                bool resultSearchSet = values.count(value);
                cout << "Searching Number " << value << "  | Search result " << resultSearchSet << ' ' << resultSearchBst << endl;
                assert(resultSearchBst == resultSearchSet);
            } else if(operation == DELETE) {
                cout << "Deleting Number " << value << endl;
                if(values.count(value)) {
                    cout << "äsdfasfadsfaf" << endl;
                }                
                values.erase(value);
                bst.remove(value);
            } 
        } 
        cout << endl;
    }
}

int main() {

    stressTest();

    return 0;
}

