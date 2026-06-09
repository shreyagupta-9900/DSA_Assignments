#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertFront(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void insertEnd(int x) {
        Node* temp = new Node(x);

        if (head == NULL) {
            head = temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
    }

    void insertPosition(int pos, int x) {
        if (pos == 1) {
            insertFront(x);
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1; i++)
            curr = curr->next;

        Node* temp = new Node(x);
        temp->next = curr->next;
        curr->next = temp;
    }

    void deleteFront() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;
        while (curr->next->next != NULL)
            curr = curr->next;

        delete curr->next;
        curr->next = NULL;
    }

    void deletePosition(int pos) {
        if (pos == 1) {
            deleteFront();
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1; i++)
            curr = curr->next;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    bool search(int key) {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }

        return false;
    }
    
    int length() {
        int cnt = 0;
        Node* curr = head;

        while (curr != NULL) {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }
    void display() {
        Node* curr = head;

        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main(){

    LinkedList l;

    l.insertFront(20);
    l.insertFront(10);
    l.insertEnd(30);

    l.display();

    cout << "Length = " << l.length() << endl;

    if (l.search(20))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
