#include <iostream>

class Node {
public:
    Node* next;
    int data;
    Node(int d) : data(d), next(nullptr) {}
    Node() : next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    void appendToTail(int d) {
        Node* end = new Node(d);
        if(head == nullptr) {
            head = end;
            return;
        }
        Node* n = head;
        while(n->next != nullptr) {
            n = n->next;
        }
        n->next = end;
    }
    bool deleteNode(int d) {
        Node* n = head;
        if(n->data == d) {
            head = head->next;
            delete n;
            return true;
        }
        while(n->next != nullptr) {
            if(n->next->data == d) {
                Node *aux = n->next;
                n->next = n->next->next;
                delete aux;
                return true;
            }
            n = n->next;
        }
        return false;
    }
    void printAll() {
        Node *n = head;
        while(n != nullptr) {
            std::cout << n->data << ' ';
            n = n->next;
        }
        std::cout << std::endl; 
    }
    LinkedList() : head(nullptr) {}
};

int main() {

    LinkedList L;

    L.appendToTail(5);
    L.appendToTail(1);
    L.appendToTail(3);
    L.deleteNode(3);
    L.appendToTail(4);
    L.printAll();

    return 0;
}